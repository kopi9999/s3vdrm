/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_MEM_OFFSETS_H
#define S3VDRM_MEM_OFFSETS_H

/***
 ** absolute offsets
 */

#if 1 // add here detection of endianess
  #define S3VDRM_ENDIANESS_OFFSET 0
#else
  #define S3VDRM_ENDIANESS_OFFSET 0x200 0000
#endif

#define S3VDRM_IMAGE_TRANSFER_OFFSET  0x100 0000
#define S3VDRM_CONF_REG_OFFSET        0x100 8000

/***
 ** relative offsets
 */

// general
#define S3VDRM_MISC_REG_W 0x3C2
#define S3VDRM_MISC_REG_R 0x3CC

// CRTC
#define S3VDRM_CRTC_INDEX 0x3B4 // shiftable
#define S3VDRM_CRTC_DATA  0x3B5 // shiftable

/***
 ** relative offsets of relative offsets :)
 */

#define S3VDRM_COLOR_EM_SHIFT 0x20 // by bit 0 of MISC


#endif // S3VDRM_MEM_OFFSETS_H
