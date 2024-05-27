include common/os/linux/_base.mk

source_paths += \
    $(call expand_paths, $(libc), src/linux/tilegx) \
$(END_OF_LIST)

libc_sources += \
    syscall/__sys_rt_sigreturn.S \
$(END_OF_LIST)
    # signal/__sigreturn.S

