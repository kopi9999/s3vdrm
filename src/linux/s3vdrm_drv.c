/*
 * SPDX_License_identifier: GPL-3.0-or-later
 * Copyright (c) 2026 kopi9999
 * This file is a part of s3vdrm project.
 */

#include <linux/module.h>
#include <linux/pci.h>

#include "s3vdrm_drv.h"
#include "../s3vdrm_drvinfo.h"
#include "../s3vdrm_dev_ids.h"


static const struct drm_driver s3vdrm_driver = {
  .name = S3VDRM_NAME,
  .desc = S3VDRM_DESC,
  .major = S3VDRM_MAJOR_VER,
  .minor = S3VDRM_MINOR_VER,
  .patchlevel = S3VDRM_PATCHLEVEL,

  .driver_features = DRIVER_MODESET | DRIVER_ATOMIC | DRIVER_GEM,
};

/***
 ** mandatory
 */
static int s3vdrm_pci_probe(struct pci_dev *pdev,
                            const struct pci_device_id *ent) {
  struct drm_device *drm;
  struct s3vdrm_device *s3v;
  int ret;

  ret = pcim_enable_device(pdev);
  if (ret) {return ret;}
  
  ret = pcim_request_all_regions(pdev, S3VDRM_NAME);
  if (ret) {return ret;}
  
  ret = -ENOMEM;
  s3v = devm_drm_dev_alloc(&pdev->dev, &s3vdrm_driver,
			      struct s3vdrm_device, drm);
  if (IS_ERR(s3v)) {return PTR_ERR(s3v);}
  
  drm = &s3v->drm;

  // start of init

  s3vdrm_mode_init(s3v);
  
  // end of init
  
  drm_mode_config_reset(drm);

  pci_set_drvdata(pdev, drm);
  ret = drm_dev_register(drm, 0);
  if (ret) {return ret;}
  
  return 0;  
}

/***
 ** mandatory
 */
static void s3vdrm_pci_remove(struct pci_dev *pdev) {
  // managed by devm
}

/***
 ** mandatory
 */
static void s3vdrm_pci_shutdown(struct pci_dev *pdev) {
  struct drm_device *drm = pci_get_drvdata(pdev);

  if (!drm) // should not be needed, just in case
    return;
  
  drm_atomic_helper_shutdown(drm);
}

static struct pci_device_id s3vdrm_pci_device_ids[] = {
  { PCI_DEVICE(S3VDRM_S3_VENDOR_ID, S3VDRM_VIRGE_DEV_ID) },
  { PCI_DEVICE(S3VDRM_S3_VENDOR_ID, S3VDRM_VIRGE_DX_GX_DEV_ID) },
  {}
};

static struct pci_driver s3vdrm_pci_driver = {
    .name = S3VDRM_NAME,
    .id_table = s3vdrm_pci_device_ids,
    .probe = s3vdrm_pci_probe,
    .remove = s3vdrm_pci_remove,
    .shutdown = s3vdrm_pci_shutdown
};

drm_module_pci_driver(s3vdrm_pci_driver);
MODULE_DEVICE_TABLE(pci, s3vdrm_pci_device_ids);

MODULE_LICENSE(S3VDRM_LICENSE);
MODULE_DESCRIPTION(S3VDRM_DESC);
MODULE_AUTHOR(S3VDRM_AUTHOR);
MODULE_VERSION(XSTR(S3VDRM_MAJOR_VER) "." XSTR(S3VDRM_MINOR_VER) "." XSTR(S3VDRM_PATCHLEVEL));
