#
# Copyright (C) 2018 Wind River Systems, Inc.
#

TARGET_SUPPORTED_KTYPES_amd-snowyowl = "standard preempt-rt tiny cgl"

KBRANCH_DEFAULT_standard_amd-snowyowl = "standard/${KMACHINE}"
KBRANCH_DEFAULT_preempt-rt_amd-snowyowl = "standard/preempt-rt/${KMACHINE}"
KBRANCH_DEFAULT_tiny_amd-snowyowl = "standard/tiny/${KMACHINE}"
KBRANCH_DEFAULT_cgl_amd-snowyowl = "standard/cgl/${KMACHINE}"

DEPENDS_append_amd-snowyowl = " cdrtools-native"

# A method to install/update for bzImage on a deployed target
KERNELLOADEREXTENSION_append_amd-snowyowl = " kernel-grub"
