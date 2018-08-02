COMPATIBLE_MACHINE_amd-snowyowl = "amd-snowyowl"

#add the depends of cdrtools-native to make sure it is
#always built to support the usb-image & iso-image UEFI
#booting by default  without explicitly add the configure
#option of "--enable-bootimage=iso"

DEPENDS_append_amd-snowyowl = " cdrtools-native"

# A method to install/update for bzImage on a deployed target
KERNELLOADEREXTENSION_append_amd-snowyowl = " kernel-grub"

TARGET_SUPPORTED_KTYPES_amd-snowyowl = "standard preempt-rt"

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine_amd-snowyowl ?= "${AUTOREV}"
