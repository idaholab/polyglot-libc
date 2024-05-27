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

#ifndef _LINUX_ARM_SYSCALL_EABI_H
#define _LINUX_ARM_SYSCALL_EABI_H _LINUX_ARM_SYSCALL_EABI_H 

#define __NR_SYSCALL_BASE                   0
#define __NR__llseek                        140         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_select                         142         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR__sysctl                        149         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_accept                         285         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_accept4                        366         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_access                         33          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_acct                           51          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_add_key                        309         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_adjtimex                       124         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_alarm                          27          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_arm_fadvise64_64               270         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_arm_sync_file_range            341         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_bdflush                        134         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_bind                           282         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_bpf                            386         /*     3.18 (03120000)     5.12 (050c0000) */
#define __NR_brk                            45          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_capget                         184         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_capset                         185         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_chdir                          12          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_chmod                          15          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_chown                          182         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_chown32                        212         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_chroot                         61          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_clock_adjtime                  372         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_clock_adjtime64                405         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_getres                   264         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_clock_getres_time64            406         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_gettime32                263         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_clock_gettime64                403         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_nanosleep                265         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_clock_nanosleep_time64         407         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_settime32                262         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_clock_settime64                404         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clone                          120         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_clone3                         435         /*      5.3 (05030000)     5.12 (050c0000) */
#define __NR_close                          6           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_close_range                    436         /*      5.9 (05090000)     5.12 (050c0000) */
#define __NR_connect                        283         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_copy_file_range                391         /*      4.5 (04050000)     5.12 (050c0000) */
#define __NR_creat                          8           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_delete_module                  129         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_dup                            41          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_dup2                           63          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_dup3                           358         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_epoll_create                   250         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_epoll_create1                  357         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_epoll_ctl                      251         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_epoll_pwait                    346         /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_epoll_pwait2                   441         /*     5.11 (050b0000)     5.12 (050c0000) */
#define __NR_epoll_wait                     252         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_eventfd                        351         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_eventfd2                       356         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_execve                         11          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_execveat                       387         /*     3.19 (03130000)     5.12 (050c0000) */
#define __NR_exit                           1           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_exit_group                     248         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_faccessat                      334         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_faccessat2                     439         /*      5.8 (05080000)     5.12 (050c0000) */
#define __NR_fallocate                      352         /*   2.6.24 (02061800)     5.12 (050c0000) */
#define __NR_fanotify_init                  367         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_fanotify_mark                  368         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_fchdir                         133         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fchmod                         94          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fchmodat                       333         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_fchown                         95          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fchown32                       207         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fchownat                       325         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_fcntl                          55          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fcntl64                        221         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fdatasync                      148         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fgetxattr                      231         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_finit_module                   379         /*      3.8 (03080000)     5.12 (050c0000) */
#define __NR_flistxattr                     234         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_flock                          143         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fork                           2           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fremovexattr                   237         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fsconfig                       431         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fsetxattr                      228         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fsmount                        432         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fsopen                         430         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fspick                         433         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fstat                          108         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fstat64                        197         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fstatat64                      327         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_fstatfs                        100         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fstatfs64                      267         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_fsync                          118         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ftruncate                      93          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ftruncate64                    194         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_futex                          240         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_futex_time64                   422         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_futimesat                      326         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_get_mempolicy                  320         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_get_robust_list                339         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_getcpu                         345         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_getcwd                         183         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getdents                       141         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getdents64                     217         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getegid                        50          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getegid32                      202         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_geteuid                        49          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_geteuid32                      201         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getgid                         47          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getgid32                       200         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getgroups                      80          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getgroups32                    205         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getitimer                      105         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getpeername                    287         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getpgid                        132         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getpgrp                        65          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getpid                         20          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getppid                        64          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getpriority                    96          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getrandom                      384         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_getresgid                      171         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getresgid32                    211         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getresuid                      165         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getresuid32                    209         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getrlimit                      76          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_getrusage                      77          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getsid                         147         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getsockname                    286         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getsockopt                     295         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_gettid                         224         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_gettimeofday                   78          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getuid                         24          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getuid32                       199         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_getxattr                       229         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_init_module                    128         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_inotify_add_watch              317         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_inotify_init                   316         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_inotify_init1                  360         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_inotify_rm_watch               318         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_io_cancel                      247         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_io_destroy                     244         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_io_getevents                   245         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_io_pgetevents                  399         /*     4.19 (04130000)     5.12 (050c0000) */
#define __NR_io_pgetevents_time64           416         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_setup                       243         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_io_submit                      246         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_io_uring_enter                 426         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_uring_register              427         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_uring_setup                 425         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_ioctl                          54          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ioprio_get                     315         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ioprio_set                     314         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ipc                            117         /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_kcmp                           378         /*      3.9 (03090000)     5.12 (050c0000) */
#define __NR_kexec_file_load                401         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_kexec_load                     347         /*   2.6.21 (02061500)     5.12 (050c0000) */
#define __NR_keyctl                         311         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_kill                           37          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lchown                         16          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lchown32                       198         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lgetxattr                      230         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_link                           9           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_linkat                         330         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_listen                         284         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_listxattr                      232         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_llistxattr                     233         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lookup_dcookie                 249         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lremovexattr                   236         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lseek                          19          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lsetxattr                      227         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lstat                          107         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_lstat64                        196         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_madvise                        220         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mbind                          319         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_membarrier                     389         /*      4.3 (04030000)     5.12 (050c0000) */
#define __NR_memfd_create                   385         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_migrate_pages                  400         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_mincore                        219         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mkdir                          39          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mkdirat                        323         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_mknod                          14          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mknodat                        324         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_mlock                          150         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mlock2                         390         /*      4.4 (04040000)     5.12 (050c0000) */
#define __NR_mlockall                       152         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mmap                           90          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_mmap2                          192         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mount                          21          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mount_setattr                  442         /*     5.12 (050c0000)     5.12 (050c0000) */
#define __NR_move_mount                     429         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_move_pages                     344         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_mprotect                       125         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mq_getsetattr                  279         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mq_notify                      278         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mq_open                        274         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mq_timedreceive                277         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mq_timedreceive_time64         419         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_mq_timedsend                   276         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mq_timedsend_time64            418         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_mq_unlink                      275         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_mremap                         163         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_msgctl                         304         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_msgget                         303         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_msgrcv                         302         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_msgsnd                         301         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_msync                          144         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_munlock                        151         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_munlockall                     153         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_munmap                         91          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_name_to_handle_at              370         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_nanosleep                      162         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_nfsservctl                     169         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_nice                           34          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_open                           5           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_open_by_handle_at              371         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_open_tree                      428         /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_openat                         322         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_openat2                        437         /*      5.6 (05060000)     5.12 (050c0000) */
#define __NR_pause                          29          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pciconfig_iobase               271         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pciconfig_read                 272         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pciconfig_write                273         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_perf_counter_open              364         /*   2.6.31 (02061f00)   2.6.31 (02061f00) */
#define __NR_perf_event_open                364         /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_personality                    136         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pidfd_getfd                    438         /*      5.6 (05060000)     5.12 (050c0000) */
#define __NR_pidfd_open                     434         /*      5.3 (05030000)     5.12 (050c0000) */
#define __NR_pidfd_send_signal              424         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_pipe                           42          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pipe2                          359         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_pivot_root                     218         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pkey_alloc                     395         /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_pkey_free                      396         /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_pkey_mprotect                  394         /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_poll                           168         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ppoll                          336         /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_ppoll_time64                   414         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_prctl                          172         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pread64                        180         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_preadv                         361         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_preadv2                        392         /*      4.6 (04060000)     5.12 (050c0000) */
#define __NR_prlimit64                      369         /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_process_madvise                440         /*     5.10 (050a0000)     5.12 (050c0000) */
#define __NR_process_vm_readv               376         /*      3.2 (03020000)     5.12 (050c0000) */
#define __NR_process_vm_writev              377         /*      3.2 (03020000)     5.12 (050c0000) */
#define __NR_pselect6                       335         /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_pselect6_time64                413         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_ptrace                         26          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pwrite64                       181         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_pwritev                        362         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_pwritev2                       393         /*      4.6 (04060000)     5.12 (050c0000) */
#define __NR_quotactl                       131         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_read                           3           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_readahead                      225         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_readdir                        89          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_readlink                       85          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_readlinkat                     332         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_readv                          145         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_reboot                         88          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_recv                           291         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_recvfrom                       292         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_recvmmsg                       365         /*   2.6.33 (02062100)     5.12 (050c0000) */
#define __NR_recvmmsg_time64                417         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_recvmsg                        297         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_remap_file_pages               253         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_removexattr                    235         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rename                         38          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_renameat                       329         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_renameat2                      382         /*     3.15 (030f0000)     5.12 (050c0000) */
#define __NR_request_key                    310         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_restart_syscall                0           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rmdir                          40          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rseq                           398         /*     4.18 (04120000)     5.12 (050c0000) */
#define __NR_rt_sigaction                   174         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigpending                  176         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigprocmask                 175         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigqueueinfo                178         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigreturn                   173         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigsuspend                  179         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigtimedwait                177         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_rt_sigtimedwait_time64         421         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_rt_tgsigqueueinfo              363         /*   2.6.31 (02061f00)     5.12 (050c0000) */
#define __NR_sched_get_priority_max         159         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_get_priority_min         160         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_getaffinity              242         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_getattr                  381         /*     3.14 (030e0000)     5.12 (050c0000) */
#define __NR_sched_getparam                 155         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_getscheduler             157         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_rr_get_interval          161         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_rr_get_interval_time64   423         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_sched_setaffinity              241         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_setattr                  380         /*     3.14 (030e0000)     5.12 (050c0000) */
#define __NR_sched_setparam                 154         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_setscheduler             156         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sched_yield                    158         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_seccomp                        383         /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_select_old                     82          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_semctl                         300         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_semget                         299         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_semop                          298         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_semtimedop                     312         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_semtimedop_time64              420         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_send                           289         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sendfile                       187         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sendfile64                     239         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sendmmsg                       374         /*      3.0 (03000000)     5.12 (050c0000) */
#define __NR_sendmsg                        296         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sendto                         290         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_set_mempolicy                  321         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_set_robust_list                338         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_set_tid_address                256         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setdomainname                  121         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setfsgid                       139         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setfsgid32                     216         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setfsuid                       138         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setfsuid32                     215         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setgid                         46          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setgid32                       214         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setgroups                      81          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setgroups32                    206         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sethostname                    74          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setitimer                      104         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setns                          375         /*      3.0 (03000000)     5.12 (050c0000) */
#define __NR_setpgid                        57          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setpriority                    97          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setregid                       71          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setregid32                     204         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setresgid                      170         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setresgid32                    210         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setresuid                      164         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setresuid32                    208         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setreuid                       70          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setreuid32                     203         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setrlimit                      75          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setsid                         66          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setsockopt                     294         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_settimeofday                   79          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setuid                         23          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setuid32                       213         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_setxattr                       226         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_shmat                          305         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_shmctl                         308         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_shmdt                          306         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_shmget                         307         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_shutdown                       293         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sigaction                      67          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sigaltstack                    186         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_signalfd                       349         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_signalfd4                      355         /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_sigpending                     73          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sigprocmask                    126         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sigreturn                      119         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sigsuspend                     72          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_socket                         281         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_socketcall                     102         /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_socketpair                     288         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_splice                         340         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_stat                           106         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_stat64                         195         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_statfs                         99          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_statfs64                       266         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_statx                          397         /*     4.11 (040b0000)     5.12 (050c0000) */
#define __NR_stime                          25          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_swapoff                        115         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_swapon                         87          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_symlink                        83          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_symlinkat                      331         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_sync                           36          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sync_file_range2               341         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_syncfs                         373         /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_syscall                        113         /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_sysfs                          135         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_sysinfo                        116         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_syslog                         103         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_tee                            342         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_tgkill                         268         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_time                           13          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_timer_create                   257         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_timer_delete                   261         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_timer_getoverrun               260         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_timer_gettime                  259         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_timer_gettime64                408         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_timer_settime                  258         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_timer_settime64                409         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_timerfd                        350         /*   2.6.22 (02061600)   2.6.25 (02061900) */
#define __NR_timerfd_create                 350         /*   2.6.26 (02061a00)     5.12 (050c0000) */
#define __NR_timerfd_gettime                354         /*   2.6.26 (02061a00)     5.12 (050c0000) */
#define __NR_timerfd_gettime64              410         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_timerfd_settime                353         /*   2.6.26 (02061a00)     5.12 (050c0000) */
#define __NR_timerfd_settime64              411         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_times                          43          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_tkill                          238         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_truncate                       92          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_truncate64                     193         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_ugetrlimit                     191         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_umask                          60          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_umount                         22          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_umount2                        52          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_uname                          122         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_unlink                         10          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_unlinkat                       328         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_unshare                        337         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_uselib                         86          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_userfaultfd                    388         /*      4.3 (04030000)     5.12 (050c0000) */
#define __NR_ustat                          62          /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_utime                          30          /*   2.6.16 (02061000)   2.6.16 (02061000) */
#define __NR_utimensat                      348         /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_utimensat_time64               412         /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_utimes                         269         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_vfork                          190         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_vhangup                        111         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_vmsplice                       343         /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_vserver                        313         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_wait4                          114         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_waitid                         280         /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_write                          4           /*   2.6.16 (02061000)     5.12 (050c0000) */
#define __NR_writev                         146         /*   2.6.16 (02061000)     5.12 (050c0000) */

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

#endif // _LINUX_ARM_SYSCALL_EABI_H
