/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include "s3vdrm_hw.h"

void s3vdrm_hw_probe(void *base, struct s3v_status *s3v_stat) {
  bool shift = false;

  s3v_stat->regs.vga_regs.misc = S3VDRM_REG_R8(base, S3VDRM_MISC_REG_R);
  
  if (!(s3v_stat->regs.vga_regs.misc & 0b00010000)) { //ensure working i/o
    S3vdrm_enable_mmio();
    s3v_stat->regs.vga_regs.misc = S3VDRM_REG_R8(base, S3VDRM_MISC_REG_R);
  }
  
  if (s3v_stat->regs.vga_regs.misc & 0b00000001) {shift = true;} //get shift

  s3v_stat->regs.vga_regs.cr0 = S3vdrm_vga_r8(base, 0, shift);

  S3vdrm_vga_w8(base, 0x38, shift, 0b01001000); // unlock extended crtc registers
  s3v_stat->regs.vga_regs.cr36 = S3vdrm_vga_r8(base, 0x36, shift);
}
