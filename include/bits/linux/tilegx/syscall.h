/* This file is part of the Polyglot C Library.

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

   The Polyglot C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the License,
   or (at your option) any later version.

   The Polyglot C library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
   for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library; if not, see <https://www.gnu.org/licenses/>. */

#ifndef _LINUX_TILEGX_SYSCALL_H
#define _LINUX_TILEGX_SYSCALL_H _LINUX_TILEGX_SYSCALL_H

#define __NR_accept                         202         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_accept4                        242         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_acct                           89          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_add_key                        217         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_adjtimex                       171         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_arch_specific_syscall          244         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_bind                           200         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_bpf                            280         /*     3.18 (03120000)     4.16 (04100000) */
#define __NR_brk                            214         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_cacheflush                     245         /*      3.5 (03050000)     4.16 (04100000) */
#define __NR_capget                         90          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_capset                         91          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_chdir                          49          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_chroot                         51          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_clock_adjtime                  266         /*   2.6.39 (02062700)     4.16 (04100000) */
#define __NR_clock_getres                   114         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_clock_gettime64                113         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_clock_nanosleep                115         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_clock_settime64                112         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_clone                          220         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_close                          57          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_connect                        203         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_copy_file_range                285         /*      4.5 (04050000)     4.16 (04100000) */
#define __NR_delete_module                  106         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_dup                            23          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_dup3                           24          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_epoll_create1                  20          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_epoll_ctl                      21          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_epoll_pwait                    22          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_eventfd2                       19          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_execve                         221         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_execveat                       281         /*     3.19 (03130000)     4.16 (04100000) */
#define __NR_exit                           93          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_exit_group                     94          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_faccessat                      48          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fadvise64                      223         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fallocate                      47          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fanotify_init                  262         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fanotify_mark                  263         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fchdir                         50          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fchmod                         52          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fchmodat                       53          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fchown                         55          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fchownat                       54          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fcntl                          25          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fdatasync                      83          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fgetxattr                      10          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_finit_module                   273         /*      3.8 (03080000)     4.16 (04100000) */
#define __NR_flistxattr                     13          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_flock                          32          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_flush_cache                    245         /*   2.6.36 (02062400)      3.4 (03040000) */
#define __NR_fremovexattr                   16          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fsetxattr                      7           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fstat                          80          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fstatfs                        44          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_fsync                          82          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_ftruncate                      46          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_futex                          98          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_get_mempolicy                  236         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_get_robust_list                100         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getcpu                         168         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getcwd                         17          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getdents64                     61          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getegid                        177         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_geteuid                        175         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getgid                         176         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getgroups                      158         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getitimer                      102         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getpeername                    205         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getpgid                        155         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getpid                         172         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getppid                        173         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getpriority                    141         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getrandom                      278         /*     3.17 (03110000)     4.16 (04100000) */
#define __NR_getresgid                      150         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getresuid                      148         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_ugetrlimit                     163         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getrusage                      165         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getsid                         156         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getsockname                    204         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getsockopt                     209         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_gettid                         178         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_gettimeofday                   169         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getuid                         174         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_getxattr                       8           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_init_module                    105         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_inotify_add_watch              27          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_inotify_init1                  26          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_inotify_rm_watch               28          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_io_cancel                      3           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_io_destroy                     1           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_io_getevents                   4           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_io_setup                       0           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_io_submit                      2           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_ioctl                          29          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_ioprio_get                     31          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_ioprio_set                     30          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_kcmp                           272         /*      3.6 (03060000)     4.16 (04100000) */
#define __NR_kexec_load                     104         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_keyctl                         219         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_kill                           129         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_lgetxattr                      9           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_linkat                         37          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_listen                         201         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_listxattr                      11          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_llistxattr                     12          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_lookup_dcookie                 18          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_lremovexattr                   15          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_lseek                          62          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_lsetxattr                      6           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_madvise                        233         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mbind                          235         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_membarrier                     283         /*      4.3 (04030000)     4.16 (04100000) */
#define __NR_memfd_create                   279         /*     3.17 (03110000)     4.16 (04100000) */
#define __NR_migrate_pages                  238         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mincore                        232         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mkdirat                        34          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mknodat                        33          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mlock                          228         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mlock2                         284         /*      4.4 (04040000)     4.16 (04100000) */
#define __NR_mlockall                       230         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mmap                           222         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mount                          40          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_move_pages                     239         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mprotect                       226         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mq_getsetattr                  185         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mq_notify                      184         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mq_open                        180         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mq_timedreceive                183         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mq_timedsend                   182         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mq_unlink                      181         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_mremap                         216         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_msgctl                         187         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_msgget                         186         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_msgrcv                         188         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_msgsnd                         189         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_msync                          227         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_munlock                        229         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_munlockall                     231         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_munmap                         215         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_name_to_handle_at              264         /*   2.6.39 (02062700)     4.16 (04100000) */
#define __NR_nanosleep                      101         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_newfstatat                     79          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_nfsservctl                     42          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_open_by_handle_at              265         /*   2.6.39 (02062700)     4.16 (04100000) */
#define __NR_openat                         56          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_perf_event_open                241         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_personality                    92          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pipe2                          59          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pivot_root                     41          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pkey_alloc                     289         /*      4.9 (04090000)     4.16 (04100000) */
#define __NR_pkey_free                      290         /*      4.9 (04090000)     4.16 (04100000) */
#define __NR_pkey_mprotect                  288         /*      4.9 (04090000)     4.16 (04100000) */
#define __NR_ppoll                          73          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_prctl                          167         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pread64                        67          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_preadv                         69          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_preadv2                        286         /*      4.6 (04060000)     4.16 (04100000) */
#define __NR_prlimit64                      261         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_process_vm_readv               270         /*      3.2 (03020000)     4.16 (04100000) */
#define __NR_process_vm_writev              271         /*      3.2 (03020000)     4.16 (04100000) */
#define __NR_pselect6                       72          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_ptrace                         117         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pwrite64                       68          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pwritev                        70          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_pwritev2                       287         /*      4.6 (04060000)     4.16 (04100000) */
#define __NR_quotactl                       60          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_read                           63          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_readahead                      213         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_readlinkat                     78          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_readv                          65          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_reboot                         142         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_recvfrom                       207         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_recvmmsg                       243         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_recvmsg                        212         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_remap_file_pages               234         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_removexattr                    14          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_renameat                       38          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_renameat2                      276         /*     3.15 (030f0000)     4.16 (04100000) */
#define __NR_request_key                    218         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_restart_syscall                128         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigaction                   134         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigpending                  136         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigprocmask                 135         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigqueueinfo                138         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigreturn                   139         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigsuspend                  133         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_sigtimedwait                137         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_rt_tgsigqueueinfo              240         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_get_priority_max         125         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_get_priority_min         126         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_getaffinity              123         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_getattr                  275         /*     3.14 (030e0000)     4.16 (04100000) */
#define __NR_sched_getparam                 121         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_getscheduler             120         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_rr_get_interval          127         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_setaffinity              122         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_setattr                  274         /*     3.14 (030e0000)     4.16 (04100000) */
#define __NR_sched_setparam                 118         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_setscheduler             119         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sched_yield                    124         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_seccomp                        277         /*     3.17 (03110000)     4.16 (04100000) */
#define __NR_semctl                         191         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_semget                         190         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_semop                          193         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_semtimedop                     192         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sendfile                       71          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sendmmsg                       269         /*      3.0 (03000000)     4.16 (04100000) */
#define __NR_sendmsg                        211         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sendto                         206         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_set_mempolicy                  237         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_set_robust_list                99          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_set_tid_address                96          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setdomainname                  162         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setfsgid                       152         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setfsuid                       151         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setgid                         144         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setgroups                      159         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sethostname                    161         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setitimer                      103         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setns                          268         /*      3.0 (03000000)     4.16 (04100000) */
#define __NR_setpgid                        154         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setpriority                    140         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setregid                       143         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setresgid                      149         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setresuid                      147         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setreuid                       145         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setrlimit                      164         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setsid                         157         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setsockopt                     208         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_settimeofday                   170         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setuid                         146         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_setxattr                       5           /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_shmat                          196         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_shmctl                         195         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_shmdt                          197         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_shmget                         194         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_shutdown                       210         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sigaltstack                    132         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_signalfd4                      74          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_socket                         198         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_socketpair                     199         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_splice                         76          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_statfs                         43          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_statx                          291         /*     4.11 (040b0000)     4.16 (04100000) */
#define __NR_swapoff                        225         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_swapon                         224         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_symlinkat                      36          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sync                           81          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_sync_file_range                84          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_syncfs                         267         /*   2.6.39 (02062700)     4.16 (04100000) */
#define __NR_sysinfo                        179         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_syslog                         116         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_tee                            77          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_tgkill                         131         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timer_create                   107         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timer_delete                   111         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timer_getoverrun               109         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timer_gettime                  108         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timer_settime                  110         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timerfd_create                 85          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timerfd_gettime                87          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_timerfd_settime                86          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_times                          153         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_tkill                          130         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_truncate                       45          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_umask                          166         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_umount2                        39          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_uname                          160         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_unlinkat                       35          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_unshare                        97          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_userfaultfd                    282         /*      4.3 (04030000)     4.16 (04100000) */
#define __NR_utimensat                      88          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_vhangup                        58          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_vmsplice                       75          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_wait4                          260         /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_waitid                         95          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_write                          64          /*   2.6.36 (02062400)     4.16 (04100000) */
#define __NR_writev                         66          /*   2.6.36 (02062400)     4.16 (04100000) */

#if !defined(__ASSEMBLER__) && !defined(__target_featuredef)

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/comparison/less.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>

long __syscall();

// arch-specific syscalls
void __sys_rt_sigreturn();

/* this is a simple way of casting all the arguments passed to a syscall to
 * long, without needing to define the function as taking longs */
#define __LONG(z,n,t)   ((long)(BOOST_PP_TUPLE_ELEM(n, t))) \
                            BOOST_PP_COMMA_IF(BOOST_PP_LESS( \
                                n, BOOST_PP_SUB(BOOST_PP_TUPLE_SIZE(t), 1) \
                            ))
#define __SC_ARGS(t)    BOOST_PP_REPEAT(BOOST_PP_TUPLE_SIZE(t), __LONG, t)
#define syscall(...)    __syscall(__SC_ARGS( \
                            BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__) \
                        ))

#endif // !__ASSEMBLER__ && !__target_featuredef

#endif // _LINUX_TILEGX_SYSCALL_H
