# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

source_paths += \
    $(call expand_paths, $(libc), src/sparc) \
# end of list

crt_sources += \
    crt0.S \
# end of list

