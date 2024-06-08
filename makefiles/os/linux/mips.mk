# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

include os/linux/base.mk

source_paths += \
    $(call expand_paths, $(libc), src/linux/mips) \
$(END_OF_LIST)

libc_sources += \
    syscall/__syscall_pipe.S \
$(END_OF_LIST)

