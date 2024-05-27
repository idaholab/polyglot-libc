# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

source_paths += \
    $(call expand_paths, $(libc), src/arm) \
# end of list

crt_sources += \
    crt1.S \
    crti.S \
    crtn.S \
# end of list

