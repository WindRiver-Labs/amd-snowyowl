#
# Copyright (C) 2018 Wind River Systems, Inc.
#

MACHINE_FEATURES += "x86 pci usbhost ext2 keyboard screen alsa acpi vfat serial"
MACHINE_FEATURES += "efi pcbios"
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-radeon"

require recipes-bsp/grub/grub-version.inc

KERNEL_IMAGETYPE = "bzImage"

SERIAL_CONSOLES = "115200;ttyS0"

MACHINEOVERRIDES_append = ":amd-snowyowl"

# xserver-common, x11-common
VIRTUAL-RUNTIME_xserver_common ?= "x11-common"

# xserver-nodm-init, anaconda-init
VIRTUAL-RUNTIME_graphical_init_manager ?= "xserver-nodm-init"

XSERVER ?= "xserver-xorg \
           xserver-xorg-extension-dri \
           xserver-xorg-extension-dri2 \
           xserver-xorg-extension-glx \
           xserver-xorg-extension-extmod \
           xserver-xorg-extension-dbe \
           xserver-xorg-module-libint10 \
           ${VIRTUAL-RUNTIME_graphical_init_manager} \
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
           ${VIRTUAL-RUNTIME_xserver_common} \
           matchbox-wm"

PREFERRED_PROVIDER_libglu = "libglu"
PREFERRED_PROVIDER_libdrm = "libdrm"
PREFERRED_VERSION_virtual/mesa = "9.2.0"

PREFERRED_VERSION_linux-windriver ?= "4.8%"
PREFERRED_VERSION_grub-efi ?= "2.00"

PREFERRED_VERSION_autoconf-archive ?= "2016.09.16"

IMAGE_FSTYPES += "wic wic.bmap live"
WKS_FILE ?= "mkefidisk.wks"
do_image_wic[depends] += "gptfdisk-native:do_populate_sysroot"
do_image_wic[recrdeptask] += "do_bootimg"

PACKAGECONFIG_pn-gnome-common = " autoconf-archive"
