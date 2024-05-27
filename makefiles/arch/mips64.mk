# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

source_paths += \
    $(call expand_paths, $(libc), src/mips64) \
$(END_OF_LIST)

crt_sources += \
    crt0.S \
    crti.S \
    crtn.S \
$(END_OF_LIST)

libc_sources += \
$(END_OF_LIST)

