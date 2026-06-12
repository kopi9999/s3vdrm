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
#include <drm/drm_managed.h>
#include <drm/drm_atomic_helper.h>
#include <drm/drm_probe_helper.h>

struct s3vdrm_device {
  struct drm_device drm;
};

/***
 ** driver exported functions
 */

int s3vdrm_mode_init(struct s3vdrm_device *s3v);

#endif
