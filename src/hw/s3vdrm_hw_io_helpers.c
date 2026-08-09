/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include "s3vdrm_hw.h"
#include "../s3vdrm_io_macros.h"

/***
 ** general purpose functions
 */

// Sequencer access

u8 S3vdrm_seq_r8(void* base, u8 id) {
  S3VDRM_REG_W8(base, S3VDRM_SEQ_INDEX, id);
  return S3VDRM_REG_R8(base, S3VDRM_SEQ_DATA);  
}  

void S3vdrm_seq_w8(void* base, u8 id, u8 val) {
  S3VDRM_REG_W8(base, S3VDRM_SEQ_INDEX, id);
  S3VDRM_REG_W8(base, S3VDRM_SEQ_DATA, val);
}

// CRTC access

u8 S3vdrm_crtc_r8(void* base, u8 id, bool shift) {
  S3VDRM_REG_W8(base, S3VDRM_CRTC_INDEX + (shift ? S3VDRM_REG_SHIFT : 0), id);
  return S3VDRM_REG_R8(base, S3VDRM_CRTC_DATA + (shift ? S3VDRM_REG_SHIFT : 0));  
}  

void S3vdrm_crtc_w8(void* base, u8 id, bool shift, u8 val) {
  S3VDRM_REG_W8(base, S3VDRM_CRTC_INDEX + (shift ? S3VDRM_REG_SHIFT : 0), id);
  S3VDRM_REG_W8(base, S3VDRM_CRTC_DATA + (shift ? S3VDRM_REG_SHIFT : 0), val);
}

/***
 ** extended registers locking/unlocking
 */

void S3vdrm_unlock_regs(void *base, bool shift) {
  S3vdrm_seq_w8(base, 0x08, 0x06); // SR9 - SRff
  S3vdrm_crtc_w8(base, 0x38, shift, 0x48); // CR2d - CR3f
  S3vdrm_crtc_w8(base, 0x39, shift, 0xa5); // CR40 - CRff
}

void S3vdrm_lock_regs(void *base, bool shift) {
  u8 cr40;

  // here should be detection code for S3D busyness
  
  cr40 = S3vdrm_crtc_r8(base, 0x40, shift); // disable enhanced reg access
  cr40 &= 0b11111110;
  S3vdrm_crtc_w8(base, 0x40, shift, cr40);

  S3vdrm_seq_w8(base, 0x08, 0x00); // remove register access codes
  S3vdrm_crtc_w8(base, 0x38, shift, 0x00);
  S3vdrm_crtc_w8(base, 0x39, shift, 0x00);
}

/***
 ** Some PCI Virge cards have mmio disabled by their BIOS and require manual
 ** enabling through I/O bus (bit 3 of CR53 register must be a 1 for new MMIO).
 */

void S3vdrm_enable_mmio(void) {
  u8 shift, tmp;

  shift = S3VDRM_IO_R8(S3VDRM_MISC_REG_R) & 0b00000001; //bit 0 enables shift
  if (shift) {shift = S3VDRM_REG_SHIFT;}

  S3VDRM_IO_W8(S3VDRM_CRTC_INDEX + shift, 0x39);
  S3VDRM_IO_W8(S3VDRM_CRTC_DATA + shift,  0xa5); // unlock higher ext crtc regs

  S3VDRM_IO_W8(S3VDRM_CRTC_INDEX + shift, 0x53);
  tmp = S3VDRM_IO_R8(S3VDRM_CRTC_DATA + shift);

  tmp |= 0b00001000; // add new mmio bit unintrusively

  S3VDRM_IO_W8(S3VDRM_CRTC_DATA + shift,  tmp);

  S3VDRM_IO_W8(S3VDRM_CRTC_INDEX + shift, 0x40); // relocking registers just
  tmp = S3VDRM_IO_R8(S3VDRM_CRTC_DATA + shift);  // in case

  tmp &= 0b11111110;

  S3VDRM_IO_W8(S3VDRM_CRTC_DATA + shift,  tmp);

  S3VDRM_IO_W8(S3VDRM_CRTC_INDEX + shift, 0x39);
  S3VDRM_IO_W8(S3VDRM_CRTC_DATA + shift,  0x00);
}
