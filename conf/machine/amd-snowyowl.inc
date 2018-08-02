#
# Copyright (C) 2018 Wind River Systems, Inc.
#

MACHINE_FEATURES += "x86 pci usbhost ext2 keyboard screen alsa acpi vfat serial"
MACHINE_FEATURES += "efi pcbios"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-radeon"

EFI_PROVIDER ?= "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', 'systemd-boot', 'grub-efi', d)}"

# grub-efi is depended in wic.bbclass, remove it to aviod depency error.
WKS_FILE_DEPENDS_BOOTLOADERS_remove = "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', 'grub-efi', '', d)}"

# Do not include installer routine when GPLv3 is not allowed.
INITRAMFS_SCRIPTS_remove = "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', 'initramfs-module-install initramfs-module-install-efi', '', d)}"
LABELS_LIVE_remove = "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', 'install', '', d)}"

KERNEL_IMAGETYPE = "bzImage"

SERIAL_CONSOLES = "115200;ttyS0"


XSERVER ?= "xserver-xorg \
           xserver-xorg-extension-dri \
           xserver-xorg-extension-dri2 \
           xserver-xorg-extension-glx \
           xserver-xorg-extension-extmod \
           xserver-xorg-extension-dbe \
           xserver-xorg-module-libint10 \
           xf86-input-mouse \
           xf86-input-keyboard \
           xf86-input-evdev \
           xf86-input-synaptics \
           xf86-video-vesa \
           xf86-video-fbdev \
           xf86-video-intel \
           xf86-video-mga \
           xf86-video-modesetting \
           xf86-video-ati \
           mesa \
           mesa-driver-radeon \
           mesa-driver-swrast \
           mesa-demos \
           matchbox-wm"

PREFERRED_PROVIDER_libglu = "libglu"
PREFERRED_PROVIDER_libdrm = "libdrm"
PREFERRED_VERSION_virtual/mesa = "17.1.5"

PREFERRED_VERSION_grub-efi ?= "2.04"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "5.2%"

PREFERRED_VERSION_autoconf-archive ?= "2019.01.06"

IMAGE_FSTYPES += "wic wic.bmap live"
WKS_FILE ?= "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', 'systemd-bootdisk.wks', 'mkefidisk.wks', d)}"
do_image_wic[depends] += "gptfdisk-native:do_populate_sysroot"
do_image_wic[recrdeptask] += "do_bootimg"

PACKAGECONFIG_pn-gnome-common = " autoconf-archive"
