/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_HW_H
#define S3VDRM_HW_H

#include "../s3vdrm_types.h"
#include "../s3vdrm_io_macros.h"

/***
 ** exported functions
 */

u8   S3vdrm_vga_r8(void* base, u8 id, bool shift);
void S3vdrm_vga_w8(void* base, u8 id, bool shift, u8 val);

#endif
