# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

source_paths += \
    $(call expand_paths, $(libc), src/tilegx) \
$(END_OF_LIST)

#header_paths += \
#    $(cachedir)/include/linux-tilegx
#$(END_OF_LIST)

crt_sources += \
    crt1.S \
    crti.S \
    crtn.S \
$(END_OF_LIST)

# this is theoretically relevant for non-Linux targets as well, since these
# headers are included -with- the Linux kernel, but are from Tilera directly
.PHONY: linux-arch-headers
linux-arch-headers: $(prefix)/include/linux-tilegx | $(headercache)
	$(call do_rsync, <headercache>/arch, $</arch/, $(headercache)/arch/)

header_targets += linux-arch-headers

