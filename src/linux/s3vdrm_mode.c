/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include "s3vdrm_drv.h"

static struct drm_mode_config_funcs s3vdrm_mode_config_funcs = {
    .fb_create = NULL,
    .mode_valid = NULL,
    .atomic_check = NULL,
    .atomic_commit = NULL
};

int s3vdrm_mode_init(struct s3vdrm_device *s3v) {
  struct drm_device *drm = &s3v->drm;
  int ret;

  ret = drmm_mode_config_init(drm);
  if (ret) {return ret;}

  drm->mode_config.min_width = 320;
  drm->mode_config.min_height = 200;
  drm->mode_config.max_width = 2048;
  drm->mode_config.max_height = 2048;
  drm->mode_config.prefer_shadow = 0;
  drm->mode_config.preferred_depth = 8;
  drm->mode_config.funcs = &s3vdrm_mode_config_funcs;

  s3vdrm_hw_probe(s3v->mmio, &s3v->status);

  pr_info("misc register status: %b", s3v->status.regs.vga_regs.misc);
  pr_info("cr0 register status: %b", s3v->status.regs.vga_regs.cr0);
  pr_info("cr36 register status: %b", s3v->status.regs.vga_regs.cr36);
  
  return 0;
}
