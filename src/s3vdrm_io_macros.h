/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_IO_MACROS_H
#define S3VDRM_IO_MACROS_H

#include "s3vdrm_mem_offsets.h"

#include <linux/pci.h>
#define S3VDRM_MMIO_R8(addr) ioread8(addr)
#define S3VDRM_MMIO_W8(addr, val) iowrite8(val, addr)

#endif
