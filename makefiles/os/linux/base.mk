# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

source_paths += \
    $(call expand_paths, $(libc), src/linux) \
$(END_OF_LIST)

libc_sources += \
    _PDCLIB/_PDCLIB_lc_message.c \
    dirent/__readdir.c \
    fcntl/__fcntl_v.c \
    fcntl/__open_v.c \
    fcntl/__openat_v.c \
    poll/poll.c \
    poll/ppoll.c \
    polyglot/__heap_get_initial.c \
    polyglot/__platform_init.c \
    sched/__clone.c \
    signal/alarm.c \
    signal/kill.c \
    signal/sigaction.c \
    signal/sigprocmask.c \
    signal/sigsuspend.c \
    stdlib/grantpt.c \
    stdlib/posix_openpt.c \
    stdlib/ptsname.c \
    stdlib/unlockpt.c \
    sys/ioctl/__ioctl_v.c \
    sys/ioctl/ioctl.c \
    sys/ipc/__ipc_generic.c \
    sys/mman/madvise.c \
    sys/mman/mmap.c \
    sys/mman/mremap.c \
    sys/mman/munmap.c \
    sys/msg/msgctl.c \
    sys/msg/msgget.c \
    sys/msg/msgrcv.c \
    sys/msg/msgsnd.c \
    sys/resource/__copy_rusage.c \
    sys/resource/__prlimit64.c \
    sys/resource/getpriority.c \
    sys/resource/getrlimit.c \
    sys/resource/getrusage.c \
    sys/resource/setrlimit.c \
    sys/select/pselect.c \
    sys/select/select.c \
    sys/sem/__semctl.c \
    sys/sem/semctl.c \
    sys/sem/semget.c \
    sys/sem/semop.c \
    sys/shm/shmat.c \
    sys/shm/shmctl.c \
    sys/shm/shmdt.c \
    sys/shm/shmget.c \
    sys/socket/__accept4.c \
    sys/socket/__setsockopt.c \
    sys/socket/__socketcall_v.c \
    sys/socket/accept.c \
    sys/socket/bind.c \
    sys/socket/connect.c \
    sys/socket/getpeername.c \
    sys/socket/getsockname.c \
    sys/socket/listen.c \
    sys/socket/recv.c \
    sys/socket/recvfrom.c \
    sys/socket/send.c \
    sys/socket/sendto.c \
    sys/socket/setsockopt.c \
    sys/socket/shutdown.c \
    sys/socket/socket.c \
    sys/stat/__copy_stat.c \
    sys/stat/__fstatat.c \
    sys/stat/fchmod.c \
    sys/stat/fchmodat.c \
    sys/stat/fstat.c \
    sys/stat/fstatat.c \
    sys/stat/lstat.c \
    sys/stat/mkdir.c \
    sys/stat/mkdirat.c \
    sys/stat/stat.c \
    sys/stat/umask.c \
    sys/statfs/__copy_kernel_statfs.c \
    sys/statfs/fstatfs.c \
    sys/statfs/statfs.c \
    sys/time/gettimeofday.c \
    sys/times/times.c \
    sys/utsname/uname.c \
    sys/wait/__wait4.c \
    sys/wait/wait.c \
    sys/wait/waitid.c \
    sys/wait/waitpid.c \
    termios/cfgetispeed.c \
    termios/cfgetospeed.c \
    termios/cfsetispeed.c \
    termios/cfsetospeed.c \
    termios/tcdrain.c \
    termios/tcflow.c \
    termios/tcflush.c \
    termios/tcgetattr.c \
    termios/tcsendbreak.c \
    termios/tcsetattr.c \
    time/clock_gettime.c \
    time/nanosleep.c \
    time/time.c \
    unistd/___llseek.c \
    unistd/__dup3.c \
    unistd/__lseek.c \
    unistd/__pipe2.c \
    unistd/__setresgid.c \
    unistd/__setresuid.c \
    unistd/_exit.c \
    unistd/access.c \
    unistd/brk.c \
    unistd/chdir.c \
    unistd/close.c \
    unistd/dup.c \
    unistd/dup2.c \
    unistd/execve.c \
    unistd/faccessat.c \
    unistd/fchdir.c \
    unistd/fork.c \
    unistd/fsync.c \
    unistd/getcwd.c \
    unistd/getegid.c \
    unistd/geteuid.c \
    unistd/getgid.c \
    unistd/getpagesize.c \
    unistd/getpgid.c \
    unistd/getpid.c \
    unistd/getppid.c \
    unistd/getsid.c \
    unistd/getuid.c \
    unistd/link.c \
    unistd/linkat.c \
    unistd/lseek.c \
    unistd/pipe.c \
    unistd/read.c \
    unistd/readlink.c \
    unistd/readlinkat.c \
    unistd/rmdir.c \
    unistd/setegid.c \
    unistd/seteuid.c \
    unistd/setgid.c \
    unistd/setregid.c \
    unistd/setreuid.c \
    unistd/setsid.c \
    unistd/setuid.c \
    unistd/sync.c \
    unistd/sysconf.c \
    unistd/unlink.c \
    unistd/unlinkat.c \
    unistd/write.c \
$(END_OF_LIST)

libc_sources += \
    shim/__accept4_via_socketcall.c \
    shim/__accept_via_accept4.c \
    shim/__accept_via_socketcall.c \
    shim/__access_via_faccessat.c \
    shim/__bind_via_socketcall.c \
    shim/__connect_via_socketcall.c \
    shim/__dup2_via_dup3.c \
    shim/__faccessat_via_fstatat.c \
    shim/__fchmodat_via_chmod.c \
    shim/__fork_via_clone.c \
    shim/__fstatat_via_stat.c \
    shim/__fsync_via_sync.c \
    shim/__getpagesize_nosys.c \
    shim/__getpeername_via_socketcall.c \
    shim/__getrlimit_via_prlimit64.c \
    shim/__getsockname_via_socketcall.c \
    shim/__link_via_linkat.c \
    shim/__linkat_via_link.c \
    shim/__listen_via_socketcall.c \
    shim/__lseek64_via__llseek.c \
    shim/__lstat_via_fstatat.c \
    shim/__mkdir_via_mkdirat.c \
    shim/__mkdirat_via_mkdir.c \
    shim/__mmap_via_mmap2.c \
    shim/__msgctl_via_ipc.c \
    shim/__msgget_via_ipc.c \
    shim/__msgrcv_via_ipc.c \
    shim/__msgsnd_via_ipc.c \
    shim/__open_via_openat_v.c \
    shim/__openat_via_open_v.c \
    shim/__pipe_via_pipe2.c \
    shim/__poll_via_ppoll.c \
    shim/__ppoll_via_poll.c \
    shim/__pselect_via_select.c \
    shim/__readlink_via_readlinkat.c \
    shim/__readlinkat_via_readlink.c \
    shim/__recv_via_recvfrom.c \
    shim/__recv_via_socketcall.c \
    shim/__recvfrom_via_socketcall.c \
    shim/__rmdir_via_unlinkat.c \
    shim/__select_via_pselect.c \
    shim/__semctl_via_ipc.c \
    shim/__semget_via_ipc.c \
    shim/__semop_via_ipc.c \
    shim/__send_via_sendto.c \
    shim/__send_via_socketcall.c \
    shim/__sendto_via_socketcall.c \
    shim/__setegid_via_setregid.c \
    shim/__setegid_via_setresgid.c \
    shim/__seteuid_via_setresuid.c \
    shim/__seteuid_via_setreuid.c \
    shim/__setrlimit_via_prlimit64.c \
    shim/__setsockopt_via_socketcall.c \
    shim/__shmat_via_ipc.c \
    shim/__shmctl_via_ipc.c \
    shim/__shmdt_via_ipc.c \
    shim/__shmget_via_ipc.c \
    shim/__shutdown_via_socketcall.c \
    shim/__socket_via_socketcall.c \
    shim/__stat_via_fstatat.c \
    shim/__time_via_gettimeofday.c \
    shim/__unlink_via_unlinkat.c \
    shim/__unlinkat_via_unlink.c \
    shim/__wait_via_wait4.c \
    shim/__waitpid_via_wait4.c \
$(END_OF_LIST)

libc_sources += \
    syscall/__syscall.S \
    syscall/__syscall_error.S \
    syscall/__sys__llseek.c \
    syscall/__sys_accept.c \
    syscall/__sys_accept4.c \
    syscall/__sys_access.c \
    syscall/__sys_alarm.c \
    syscall/__sys_bind.c \
    syscall/__sys_brk.c \
    syscall/__sys_chdir.c \
    syscall/__sys_clock_gettime32.c \
    syscall/__sys_clock_gettime64.c \
    syscall/__sys_clone.c \
    syscall/__sys_close.c \
    syscall/__sys_connect.c \
    syscall/__sys_dup.c \
    syscall/__sys_dup2.c \
    syscall/__sys_dup3.c \
    syscall/__sys_execve.c \
    syscall/__sys_faccessat.c \
    syscall/__sys_faccessat2.c \
    syscall/__sys_fchdir.c \
    syscall/__sys_fchmod.c \
    syscall/__sys_fchmodat.c \
    syscall/__sys_fcntl64_v.c \
    syscall/__sys_fcntl_v.c \
    syscall/__sys_fork.c \
    syscall/__sys_fstat.c \
    syscall/__sys_fstat64.c \
    syscall/__sys_fstat_old.c \
    syscall/__sys_fstatat64.c \
    syscall/__sys_fstatfs.c \
    syscall/__sys_fstatfs64.c \
    syscall/__sys_fsync.c \
    syscall/__sys_getcwd.c \
    syscall/__sys_getdents.c \
    syscall/__sys_getdents64.c \
    syscall/__sys_getegid.c \
    syscall/__sys_getegid32.c \
    syscall/__sys_geteuid.c \
    syscall/__sys_geteuid32.c \
    syscall/__sys_getgid.c \
    syscall/__sys_getgid32.c \
    syscall/__sys_getpagesize.c \
    syscall/__sys_getpeername.c \
    syscall/__sys_getpgid.c \
    syscall/__sys_getpid.c \
    syscall/__sys_getppid.c \
    syscall/__sys_getpriority.c \
    syscall/__sys_getrlimit.c \
    syscall/__sys_getrusage.c \
    syscall/__sys_getsid.c \
    syscall/__sys_getsockname.c \
    syscall/__sys_gettimeofday.c \
    syscall/__sys_getuid.c \
    syscall/__sys_getuid32.c \
    syscall/__sys_ioctl_v.c \
    syscall/__sys_ipc.c \
    syscall/__sys_kill.c \
    syscall/__sys_link.c \
    syscall/__sys_linkat.c \
    syscall/__sys_listen.c \
    syscall/__sys_lseek.c \
    syscall/__sys_lstat.c \
    syscall/__sys_lstat64.c \
    syscall/__sys_lstat_old.c \
    syscall/__sys_madvise.c \
    syscall/__sys_mkdir.c \
    syscall/__sys_mkdirat.c \
    syscall/__sys_mmap.c \
    syscall/__sys_mmap2.c \
    syscall/__sys_mmap_old.c \
    syscall/__sys_mremap.c \
    syscall/__sys_msgctl.c \
    syscall/__sys_msgget.c \
    syscall/__sys_msgrcv.c \
    syscall/__sys_msgsnd.c \
    syscall/__sys_munmap.c \
    syscall/__sys_nanosleep.c \
    syscall/__sys_newfstatat.c \
    syscall/__sys_open_v.c \
    syscall/__sys_openat_v.c \
    syscall/__sys_pipe.c \
    syscall/__sys_pipe2.c \
    syscall/__sys_poll.c \
    syscall/__sys_ppoll.c \
    syscall/__sys_prlimit64.c \
    syscall/__sys_pselect6.c \
    syscall/__sys_pselect6_time64.c \
    syscall/__sys_read.c \
    syscall/__sys_readdir.c \
    syscall/__sys_readlink.c \
    syscall/__sys_readlinkat.c \
    syscall/__sys_recv.c \
    syscall/__sys_recvfrom.c \
    syscall/__sys_rmdir.c \
    syscall/__sys_rt_sigaction.c \
    syscall/__sys_rt_sigprocmask.c \
    syscall/__sys_rt_sigsuspend.c \
    syscall/__sys_select.c \
    syscall/__sys_select_old.c \
    syscall/__sys_semctl.c \
    syscall/__sys_semget.c \
    syscall/__sys_semop.c \
    syscall/__sys_send.c \
    syscall/__sys_sendto.c \
    syscall/__sys_setgid.c \
    syscall/__sys_setgid32.c \
    syscall/__sys_setregid.c \
    syscall/__sys_setregid32.c \
    syscall/__sys_setresgid.c \
    syscall/__sys_setresgid32.c \
    syscall/__sys_setresuid.c \
    syscall/__sys_setresuid32.c \
    syscall/__sys_setreuid.c \
    syscall/__sys_setreuid32.c \
    syscall/__sys_setrlimit.c \
    syscall/__sys_setsid.c \
    syscall/__sys_setsockopt.c \
    syscall/__sys_setuid.c \
    syscall/__sys_setuid32.c \
    syscall/__sys_shmat.c \
    syscall/__sys_shmctl.c \
    syscall/__sys_shmdt.c \
    syscall/__sys_shmget.c \
    syscall/__sys_shutdown.c \
    syscall/__sys_sigaction.c \
    syscall/__sys_sigprocmask.c \
    syscall/__sys_sigsuspend.c \
    syscall/__sys_socket.c \
    syscall/__sys_socketcall.c \
    syscall/__sys_stat.c \
    syscall/__sys_stat64.c \
    syscall/__sys_stat_old.c \
    syscall/__sys_statfs.c \
    syscall/__sys_statfs64.c \
    syscall/__sys_sync.c \
    syscall/__sys_time.c \
    syscall/__sys_times.c \
    syscall/__sys_ugetrlimit.c \
    syscall/__sys_umask.c \
    syscall/__sys_uname.c \
    syscall/__sys_uname_old.c \
    syscall/__sys_uname_oldold.c \
    syscall/__sys_unlink.c \
    syscall/__sys_unlinkat.c \
    syscall/__sys_wait4.c \
    syscall/__sys_waitid.c \
    syscall/__sys_waitpid.c \
    syscall/__sys_write.c \
$(END_OF_LIST)

