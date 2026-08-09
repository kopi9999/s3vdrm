/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include "s3vdrm_hw.h"
#include "../s3vdrm_dev_ids.h"

static enum s3vdrm_card_type s3vdrm_get_card_type(void *base) {
  u16 vendor_id, device_id;

  vendor_id = S3VDRM_REG_R16(base, 0x00);
  if (vendor_id != S3VDRM_S3_VENDOR_ID) {return BAD_CARD;}

  device_id = S3VDRM_REG_R16(base, 0x02);
  switch (device_id) {
    case S3VDRM_VIRGE_DEV_ID:       return VIRGE;
    case S3VDRM_VIRGE_DX_GX_DEV_ID: return VIRGE_DX_GX;
    default:                        return BAD_CARD;
  }
}

static u32 s3vdrm_get_vram_size(void *base, bool shift) {
  u8 cr36;
  
  cr36 = S3vdrm_crtc_r8(base, 0x36, shift); //configuration register

  switch (cr36 >> 5) {
    case 0b000: return 0x400000; // 4M
    case 0b100: return 0x200000; // 2M
    default:    return 0;        // invalid
  } 
}

void s3vdrm_hw_probe(void *base, struct s3v_status *s3v_stat) {
  bool shift = false;
  u8 misc;

  s3v_stat->card_type = s3vdrm_get_card_type(base);

  misc = S3VDRM_REG_R8(base, S3VDRM_MISC_REG_R);
  
  if (misc & 0b00010000) { //ensure working i/o
    S3vdrm_enable_mmio();
    misc = S3VDRM_REG_R8(base, S3VDRM_MISC_REG_R);
  }

  s3v_stat->regs.vga_regs.misc = misc;
  if (s3v_stat->regs.vga_regs.misc & 0b00000001) {shift = true;} //get shift

  S3vdrm_unlock_regs(base, shift);
  
  s3v_stat->vram_size = s3vdrm_get_vram_size(base, shift);

  s3v_stat->regs.vga_regs.cr0 = S3vdrm_crtc_r8(base, 0, shift);
  s3v_stat->regs.vga_regs.cr1 = S3vdrm_seq_r8(base, 0x01);

  S3vdrm_lock_regs(base, shift);
}
