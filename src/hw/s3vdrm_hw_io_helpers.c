/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include "s3vdrm_hw.h"
#include "../s3vdrm_io_macros.h"

u8 S3vdrm_vga_r8(void* base, u8 id, bool shift) {
  S3VDRM_REG_W8(base, S3VDRM_CRTC_INDEX + (shift ? S3VDRM_REG_SHIFT : 0), id);
  return S3VDRM_REG_R8(base, S3VDRM_CRTC_DATA +(shift ? S3VDRM_REG_SHIFT : 0));  
}  

void S3vdrm_vga_w8(void* base, u8 id, bool shift, u8 val) {
  S3VDRM_REG_W8(base, S3VDRM_CRTC_INDEX + (shift ? S3VDRM_REG_SHIFT : 0), id);
  S3VDRM_REG_W8(base, S3VDRM_CRTC_DATA + (shift ? S3VDRM_REG_SHIFT : 0), val);
}
