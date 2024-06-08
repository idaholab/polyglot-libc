# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

include os/linux/base.mk

source_paths += \
    $(call expand_paths, $(libc), src/linux/arm) \
$(END_OF_LIST)

libc_sources += \
    syscall/__sys_rt_sigreturn.S \
    syscall/__sys_sigreturn.S \
$(END_OF_LIST)

