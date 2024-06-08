# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

include os/linux/base.mk

source_paths += \
    $(call expand_paths, $(libc), src/linux/sparc) \
$(END_OF_LIST)

libc_sources += \
    syscall/__syscall_clone.S \
    syscall/__syscall_fork.S \
    syscall/__syscall_pipe.S \
    syscall/__sys_sigreturn.c \
$(END_OF_LIST)

