/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_IO_MACROS_H
#define S3VDRM_IO_MACROS_H

#include "s3vdrm_mem_offsets.h"

/***
 ** kernel specific macros
 */

#include <linux/pci.h>
#include <linux/io.h>
#define S3VDRM_MMIO_R8(addr) ioread8(addr)
#define S3VDRM_MMIO_W8(addr, val) iowrite8(val, addr)
#define S3VDRM_IO_R8(addr) inb(addr)
#define S3VDRM_IO_W8(addr, val) outb(val, addr)

/***
 ** register access helpers
 */

#define S3VDRM_REG_R8(base, offset)				\
  S3VDRM_MMIO_R8(base + S3VDRM_CONF_REG_OFFSET + offset)
#define S3VDRM_REG_W8(base, offset, val)			\
  S3VDRM_MMIO_W8(base + S3VDRM_CONF_REG_OFFSET + offset, val)

#endif
