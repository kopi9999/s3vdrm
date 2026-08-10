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

struct s3v_status {
  u16 device_id;        // copy of device id used for drivers's hw side 
  bool shift;           // crtc regs address shift
  u32 vram_size;
};

#endif
