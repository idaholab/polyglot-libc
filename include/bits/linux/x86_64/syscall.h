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

#ifndef _LINUX_X86_64_SYSCALL_H
#define _LINUX_X86_64_SYSCALL_H _LINUX_X86_64_SYSCALL_H

#define __NR__sysctl                        156         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_accept                         43          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_accept4                        288         /*   2.6.28 (02061c00)     5.12 (050c0000) */
#define __NR_access                         21          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_acct                           163         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_add_key                        248         /*   2.6.11 (02060b00)     5.12 (050c0000) */
#define __NR_adjtimex                       159         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_afs_syscall                    183         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_alarm                          37          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_arch_prctl                     158         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_bind                           49          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_bpf                            321         /*     3.18 (03120000)     5.12 (050c0000) */
#define __NR_brk                            12          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_capget                         125         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_capset                         126         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_chdir                          80          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_chmod                          90          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_chown                          92          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_chroot                         161         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_clock_adjtime                  305         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_clock_getres                   229         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_clock_gettime64                228         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_clock_nanosleep                230         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_clock_settime64                227         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_clone                          56          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_clone3                         435         /*      5.3 (05030000)     5.12 (050c0000) */
#define __NR_close                          3           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_close_range                    436         /*      5.9 (05090000)     5.12 (050c0000) */
#define __NR_connect                        42          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_copy_file_range                326         /*      4.5 (04050000)     5.12 (050c0000) */
#define __NR_creat                          85          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_create_module                  174         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_delete_module                  176         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_dup                            32          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_dup2                           33          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_dup3                           292         /*   2.6.27 (02061b00)     5.12 (050c0000) */
#define __NR_epoll_create                   213         /*   2.5.53 (02053500)     5.12 (050c0000) */
#define __NR_epoll_create1                  291         /*   2.6.27 (02061b00)     5.12 (050c0000) */
#define __NR_epoll_ctl_old                  214         /*   2.5.53 (02053500)   2.5.73 (02054900) */
#define __NR_epoll_ctl                      233         /*   2.5.74 (02054a00)     5.12 (050c0000) */
#define __NR_epoll_pwait                    281         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_epoll_pwait2                   441         /*     5.11 (050b0000)     5.12 (050c0000) */
#define __NR_epoll_wait_old                 215         /*   2.5.53 (02053500)   2.5.73 (02054900) */
#define __NR_epoll_wait                     232         /*   2.5.74 (02054a00)     5.12 (050c0000) */
#define __NR_eventfd                        284         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_eventfd2                       290         /*   2.6.27 (02061b00)     5.12 (050c0000) */
#define __NR_execve                         59          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_execveat                       322         /*     3.19 (03130000)     5.12 (050c0000) */
#define __NR_exit                           60          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_exit_group                     231         /*   2.5.67 (02054300)     5.12 (050c0000) */
#define __NR_faccessat                      269         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_faccessat2                     439         /*      5.8 (05080000)     5.12 (050c0000) */
#define __NR_fadvise64                      221         /*   2.5.61 (02053d00)     5.12 (050c0000) */
#define __NR_fallocate                      285         /*   2.6.23 (02061700)     5.12 (050c0000) */
#define __NR_fanotify_init                  300         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_fanotify_mark                  301         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_fchdir                         81          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fchmod                         91          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fchmodat                       268         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fchown                         93          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fchownat                       260         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fcntl                          72          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fdatasync                      75          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fgetxattr                      193         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_finit_module                   313         /*      3.8 (03080000)     5.12 (050c0000) */
#define __NR_flistxattr                     196         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_flock                          73          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fork                           57          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fremovexattr                   199         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fsconfig                       431         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fsetxattr                      190         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fsmount                        432         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fsopen                         430         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fspick                         433         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fstat                          5           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fstatfs                        138         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_fsync                          74          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_ftruncate                      77          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_futex                          202         /*    2.5.9 (02050900)     5.12 (050c0000) */
#define __NR_futimesat                      261         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_get_kernel_syms                177         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_get_mempolicy                  239         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_get_robust_list                274         /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_get_thread_area                211         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_getcpu                         309         /*      3.1 (03010000)     5.12 (050c0000) */
#define __NR_getcwd                         79          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getdents                       78          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getdents64                     217         /*   2.5.53 (02053500)     5.12 (050c0000) */
#define __NR_getegid                        108         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_geteuid                        107         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getgid                         104         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getgroups                      115         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getitimer                      36          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getpeername                    52          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getpgid                        121         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getpgrp                        111         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getpid                         39          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getpmsg                        181         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getppid                        110         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getpriority                    140         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getrandom                      318         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_getresgid                      120         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getresuid                      118         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_ugetrlimit                     97          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getrusage                      98          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getsid                         124         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getsockname                    51          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getsockopt                     55          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_gettid                         186         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_gettimeofday                   96          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getuid                         102         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_getxattr                       191         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_init_module                    175         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_inotify_add_watch              254         /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_inotify_init                   253         /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_inotify_init1                  294         /*   2.6.27 (02061b00)     5.12 (050c0000) */
#define __NR_inotify_rm_watch               255         /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_io_cancel                      210         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_io_destroy                     207         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_io_getevents                   208         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_io_pgetevents                  333         /*     4.18 (04120000)     5.12 (050c0000) */
#define __NR_io_setup                       206         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_io_submit                      209         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_io_uring_enter                 426         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_uring_register              427         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_uring_setup                 425         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_ioctl                          16          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_ioperm                         173         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_iopl                           172         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_ioprio_get                     252         /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_ioprio_set                     251         /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_kcmp                           312         /*      3.5 (03050000)     5.12 (050c0000) */
#define __NR_kexec_file_load                320         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_kexec_load                     246         /*    2.6.7 (02060700)     5.12 (050c0000) */
#define __NR_keyctl                         250         /*   2.6.11 (02060b00)     5.12 (050c0000) */
#define __NR_kill                           62          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_lchown                         94          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_lgetxattr                      192         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_link                           86          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_linkat                         265         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_listen                         50          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_listxattr                      194         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_llistxattr                     195         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_lookup_dcookie                 212         /*   2.5.44 (02052c00)     5.12 (050c0000) */
#define __NR_lremovexattr                   198         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_lseek                          8           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_lsetxattr                      189         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_lstat                          6           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_madvise                        28          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mbind                          237         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_membarrier                     324         /*      4.3 (04030000)     5.12 (050c0000) */
#define __NR_memfd_create                   319         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_migrate_pages                  256         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mincore                        27          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mkdir                          83          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mkdirat                        258         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mknod                          133         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mknodat                        259         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mlock                          149         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mlock2                         325         /*      4.4 (04040000)     5.12 (050c0000) */
#define __NR_mlockall                       151         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mmap                           9           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_modify_ldt                     154         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mount                          165         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mount_setattr                  442         /*     5.12 (050c0000)     5.12 (050c0000) */
#define __NR_move_mount                     429         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_move_pages                     279         /*   2.6.18 (02061200)     5.12 (050c0000) */
#define __NR_mprotect                       10          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_mq_getsetattr                  245         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_mq_notify                      244         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_mq_open                        240         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_mq_timedreceive                243         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_mq_timedsend                   242         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_mq_unlink                      241         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_mremap                         25          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_msgctl                         71          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_msgget                         68          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_msgrcv                         70          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_msgsnd                         69          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_msync                          26          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_munlock                        150         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_munlockall                     152         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_munmap                         11          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_name_to_handle_at              303         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_nanosleep                      35          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_newfstatat                     262         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_nfsservctl                     180         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_open                           2           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_open_by_handle_at              304         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_open_tree                      428         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_openat                         257         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_openat2                        437         /*      5.6 (05060000)     5.12 (050c0000) */
#define __NR_paccept                        288         /*   2.6.27 (02061b00)   2.6.27 (02061b00) */
#define __NR_pause                          34          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_perf_counter_open              298         /*   2.6.31 (02061f00)   2.6.31 (02061f00) */
#define __NR_perf_event_open                298         /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_personality                    135         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_pidfd_getfd                    438         /*      5.6 (05060000)     5.12 (050c0000) */
#define __NR_pidfd_open                     434         /*      5.3 (05030000)     5.12 (050c0000) */
#define __NR_pidfd_send_signal              424         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_pipe                           22          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_pipe2                          293         /*   2.6.27 (02061b00)     5.12 (050c0000) */
#define __NR_pivot_root                     155         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_pkey_alloc                     330         /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_pkey_free                      331         /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_pkey_mprotect                  329         /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_poll                           7           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_ppoll                          271         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_prctl                          157         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_pread                          17          /*    2.5.5 (02050500)   2.5.29 (02051d00) */
#define __NR_pread64                        17          /*   2.5.30 (02051e00)     5.12 (050c0000) */
#define __NR_preadv                         295         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_preadv2                        327         /*      4.6 (04060000)     5.12 (050c0000) */
#define __NR_prlimit64                      302         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_process_madvise                440         /*     5.10 (050a0000)     5.12 (050c0000) */
#define __NR_process_vm_readv               310         /*      3.2 (03020000)     5.12 (050c0000) */
#define __NR_process_vm_writev              311         /*      3.2 (03020000)     5.12 (050c0000) */
#define __NR_pselect6                       270         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ptrace                         101         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_putpmsg                        182         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_pwrite                         18          /*    2.5.5 (02050500)   2.5.29 (02051d00) */
#define __NR_pwrite64                       18          /*   2.5.30 (02051e00)     5.12 (050c0000) */
#define __NR_pwritev                        296         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_pwritev2                       328         /*      4.6 (04060000)     5.12 (050c0000) */
#define __NR_query_module                   178         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_quotactl                       179         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_read                           0           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_readahead                      187         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_readlink                       89          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_readlinkat                     267         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_readv                          19          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_reboot                         169         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_recvfrom                       45          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_recvmmsg                       299         /*   2.6.33 (02062100)     5.12 (050c0000) */
#define __NR_recvmsg                        47          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_remap_file_pages               216         /*   2.5.53 (02053500)     5.12 (050c0000) */
#define __NR_removexattr                    197         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rename                         82          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_renameat                       264         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_renameat2                      316         /*     3.15 (030f0000)     5.12 (050c0000) */
#define __NR_request_key                    249         /*   2.6.11 (02060b00)     5.12 (050c0000) */
#define __NR_restart_syscall                219         /*   2.5.53 (02053500)     5.12 (050c0000) */
#define __NR_rmdir                          84          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rseq                           334         /*     4.18 (04120000)     5.12 (050c0000) */
#define __NR_rt_sigaction                   13          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_sigpending                  127         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_sigprocmask                 14          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_sigqueueinfo                129         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_sigreturn                   15          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_sigsuspend                  130         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_sigtimedwait                128         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_rt_tgsigqueueinfo              297         /*   2.6.31 (02061f00)     5.12 (050c0000) */
#define __NR_sched_get_priority_max         146         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_get_priority_min         147         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_getaffinity              204         /*    2.5.9 (02050900)     5.12 (050c0000) */
#define __NR_sched_getattr                  315         /*     3.14 (030e0000)     5.12 (050c0000) */
#define __NR_sched_getparam                 143         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_getscheduler             145         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_rr_get_interval          148         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_setaffinity              203         /*    2.5.9 (02050900)     5.12 (050c0000) */
#define __NR_sched_setattr                  314         /*     3.14 (030e0000)     5.12 (050c0000) */
#define __NR_sched_setparam                 142         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_setscheduler             144         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sched_yield                    24          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_seccomp                        317         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_security                       185         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_select                         23          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_semctl                         66          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_semget                         64          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_semop                          65          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_semtimedop                     220         /*   2.5.53 (02053500)     5.12 (050c0000) */
#define __NR_sendfile                       40          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sendmmsg                       307         /*      3.0 (03000000)     5.12 (050c0000) */
#define __NR_sendmsg                        46          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sendto                         44          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_set_mempolicy                  238         /*    2.6.6 (02060600)     5.12 (050c0000) */
#define __NR_set_robust_list                273         /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_set_thread_area                205         /*   2.5.43 (02052b00)     5.12 (050c0000) */
#define __NR_set_tid_address                218         /*   2.5.53 (02053500)     5.12 (050c0000) */
#define __NR_setdomainname                  171         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setfsgid                       123         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setfsuid                       122         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setgid                         106         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setgroups                      116         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sethostname                    170         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setitimer                      38          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setns                          308         /*      3.0 (03000000)     5.12 (050c0000) */
#define __NR_setpgid                        109         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setpriority                    141         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setregid                       114         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setresgid                      119         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setresuid                      117         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setreuid                       113         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setrlimit                      160         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setsid                         112         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setsockopt                     54          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_settimeofday                   164         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setuid                         105         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_setxattr                       188         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_shmat                          30          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_shmctl                         31          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_shmdt                          67          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_shmget                         29          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_shutdown                       48          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sigaltstack                    131         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_signalfd                       282         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_signalfd4                      289         /*   2.6.27 (02061b00)     5.12 (050c0000) */
#define __NR_socket                         41          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_socketpair                     53          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_splice                         275         /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_stat                           4           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_statfs                         137         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_statx                          332         /*     4.11 (040b0000)     5.12 (050c0000) */
#define __NR_swapoff                        168         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_swapon                         167         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_symlink                        88          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_symlinkat                      266         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sync                           162         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sync_file_range                277         /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_syncfs                         306         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_sysfs                          139         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_sysinfo                        99          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_syslog                         103         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_tee                            276         /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_tgkill                         234         /*    2.6.0 (02060000)     5.12 (050c0000) */
#define __NR_time                           201         /*    2.5.9 (02050900)     5.12 (050c0000) */
#define __NR_timer_create                   222         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_timer_delete                   226         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_timer_getoverrun               225         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_timer_gettime                  224         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_timer_settime                  223         /*   2.5.63 (02053f00)     5.12 (050c0000) */
#define __NR_timerfd                        283         /*   2.6.22 (02061600)   2.6.24 (02061800) */
#define __NR_timerfd_create                 283         /*   2.6.25 (02061900)     5.12 (050c0000) */
#define __NR_timerfd_gettime                287         /*   2.6.25 (02061900)     5.12 (050c0000) */
#define __NR_timerfd_settime                286         /*   2.6.25 (02061900)     5.12 (050c0000) */
#define __NR_times                          100         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_tkill                          200         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_truncate                       76          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_tuxcall                        184         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_umask                          95          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_umount2                        166         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_uname                          63          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_unlink                         87          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_unlinkat                       263         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_unshare                        272         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_uselib                         134         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_userfaultfd                    323         /*      4.3 (04030000)     5.12 (050c0000) */
#define __NR_ustat                          136         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_utime                          132         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_utimensat                      280         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_utimes                         235         /*    2.6.0 (02060000)     5.12 (050c0000) */
#define __NR_vfork                          58          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_vhangup                        153         /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_vmsplice                       278         /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_vserver                        236         /*    2.6.0 (02060000)     5.12 (050c0000) */
#define __NR_wait4                          61          /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_waitid                         247         /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_write                          1           /*    2.5.5 (02050500)     5.12 (050c0000) */
#define __NR_writev                         20          /*    2.5.5 (02050500)     5.12 (050c0000) */

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

#endif // _LINUX_X86_64_SYSCALL_H
