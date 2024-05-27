include common/os/linux/_base.mk

source_paths += \
    $(call expand_paths, $(libc), src/linux/x86_64) \
$(END_OF_LIST)

libc_sources += \
    syscall/__sys_rt_sigreturn.S \
$(END_OF_LIST)

