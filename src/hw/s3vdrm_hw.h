/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_HW_H
#define S3VDRM_HW_H

#include "../s3vdrm_types.h"
#include "../s3vdrm_io_macros.h"
#include "../s3vdrm_common_structs.h"

/***
 ** exported functions
 */

// s3vdrm_hw_io_helpers.c
u8   S3vdrm_seq_r8(void* base, u8 id);
void S3vdrm_seq_w8(void* base, u8 id, u8 val);

u8   S3vdrm_crtc_r8(void* base, u8 id, bool shift);
void S3vdrm_crtc_w8(void* base, u8 id, bool shift, u8 val);

void S3vdrm_unlock_regs(void *base, bool shift);
void S3vdrm_lock_regs(void* base, bool shift);

void S3vdrm_enable_mmio(void);


// s3vdrm_hw_probe.c
enum s3vdrm_error S3vdrm_hw_probe(void *base, struct s3v_status *s3v_stat,
                                  u16 dev_id);

#endif
