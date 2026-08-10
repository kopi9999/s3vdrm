/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include "s3vdrm_drv.h"
#include "../s3vdrm_dev_ids.h"

static void s3vdrm_log_config(struct s3v_status *status) {
  pr_info("s3vdrm: Detected supported device, printing configuration:");
  
  switch (status->device_id) {
    case S3VDRM_VIRGE_DEV_ID:
      pr_info("s3vdrm: Model: S3 Virge 325");
      break;
    case S3VDRM_VIRGE_DX_GX_DEV_ID:
      pr_info("s3vdrm: Model: S3 Virge DX or S3 Virge GX");
      break;
  }

  switch (status->vram_size) {
  case 0x400000:
    pr_info("s3vdrm: VRAM size: 4M");
    break;
  case 0x200000:
    pr_info("s3vdrm: VRAM size: 2M");
    break;
  }
}

int s3vdrm_probe(void __iomem *base, struct s3v_status *status, u16 device_id) {
  enum s3vdrm_error error;

  error = S3vdrm_hw_probe(base, status, device_id);
  if (error) {
    switch (error) {
      case PROBE_CARD_UNRESPONSIVE:
	pr_crit("s3vdrm: Device MMIO could not been enabled.");
	break;
      case PROBE_BAD_VRAM:
	pr_crit("s3vdrm: VRAM size could not been read.");
	break;
      default: break;
    }
    return -1;
  }

  s3vdrm_log_config(status);
  
  return 0;
}
