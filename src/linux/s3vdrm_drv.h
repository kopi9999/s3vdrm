
/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#ifndef S3VDRM_DRV_H
#define S3VDRM_DRV_H

#include <drm/drm_atomic.h>
#include <drm/drm_drv.h>
#include <drm/drm_module.h>

struct s3vdrm_device {
  struct drm_device dev;
};

#endif
