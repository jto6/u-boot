/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2017 Tuomas Tynkkynen
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef CONFIG_CMD_USB
# define BOOT_TARGET_USB(func)	func(USB, usb, 0)
#else
# define BOOT_TARGET_USB(func)
#endif

#define BOOT_TARGET_DEVICES(func)               \
  func(NVME, nvme, 0)                          \
	BOOT_TARGET_USB(func)                         \
    func(QEMU, qemu, na)                        \
    func(VIRTIO, virtio, 0)                     \
    func(SCSI, scsi, 0)                         \
    func(DHCP, dhcp, na)

#include <config_distro_bootcmd.h>

/* Physical memory map */
#define CFG_SYS_SDRAM_BASE		0x40000000

/* For timer, QEMU emulates an ARMv7/ARMv8 architected timer */

#define BOOTENV_DEV_QEMU(devtypeu, devtypel, instance)  \
	"bootcmd_qemu="                                       \
  "if env exists kernel_start; then "                   \
  "bootm ${kernel_start} - ${fdtcontroladdr};"          \
  "fi;\0"

#define BOOTENV_DEV_NAME_QEMU(devtypeu, devtypel, instance) \
	"qemu "

#define CFG_EXTRA_ENV_SETTINGS                  \
	BOOTENV

#endif /* __CONFIG_H */
