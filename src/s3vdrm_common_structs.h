/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_COMMON_STRUCTS_H
#define S3VDRM_COMMON_STRUCTS_H

#include "s3vdrm_types.h"

/***
 ** enums
 */

enum s3vdrm_error {
  SUCCESS,

  PROBE_CARD_UNRESPONSIVE,
  PROBE_BAD_VRAM
};

/***
 ** structs
 */

struct s3v_vga_regs {
  u8 misc;
  
  u8 cr0, cr1, cr2, cr3, cr4, cr5, cr6, cr7, cr8, cr9;
  u8 cr10, cr11, cr12, cr13, cr14, cr15, cr16, cr17, cr18;
  u8 crA, crB, crC, crD, crE, crF, cr22, cr24;
  u8 cr36;
};


struct s3v_regs {
  struct s3v_vga_regs vga_regs;
};

struct s3v_status {
  struct s3v_regs regs;
  u16 device_id;        // copy of device id used for drivers's hw side 
  bool shift;           // crtc regs address shift
  u32 vram_size;
};

#endif
