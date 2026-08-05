/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_IO_MACROS_H
#define S3VDRM_IO_MACROS_H

#include "s3vdrm_mem_offsets.h"

#define S3VDRM_MMIO_R_8(addr) ioread8(addr)
#define S3VDRM_MMIO_W_8(addr, val) iowrite8(val, addr)

/*#define S3VDRM_VGA_READ(base, id, shift)				\
  S3VDRM_MMIO_W_8(                                                             \
      base + S3VDRM_CONF_REG_OFFSET + S3VDRM_CRTC_INDEX + shift ? 0x20 : 0,    \
      id); */								\
  

#endif
