/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include <linux/module.h>
#include <linux/pci.h>

#include "s3vdrm_drv.h"
#include "../s3vdrm_drvinfo.h"

MODULE_LICENSE(S3VDRM_LICENSE);
MODULE_DESCRIPTION(S3VDRM_DESC);
MODULE_AUTHOR(S3VDRM_AUTHOR);
MODULE_VERSION(XSTR(S3VDRM_MAJOR_VER) "." XSTR(S3VDRM_MINOR_VER) "." XSTR(S3VDRM_PATCHLEVEL));
