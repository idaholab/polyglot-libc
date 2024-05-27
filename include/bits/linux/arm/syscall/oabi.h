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

#ifndef _LINUX_ARM_SYSCALL_OABI_H
#define _LINUX_ARM_SYSCALL_OABI_H _LINUX_ARM_SYSCALL_OABI_H

#define __NR_SYSCALL_BASE                   0x900000
#define __NR__llseek                        0x90008c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_select                         0x90008e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR__sysctl                        0x900095    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_accept                         0x90011d    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_accept4                        0x90016e    /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_access                         0x900021    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_acct                           0x900033    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_add_key                        0x900135    /*   2.6.12 (02060c00)     5.12 (050c0000) */
#define __NR_adjtimex                       0x90007c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_afs_syscall                    0x900089    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_alarm                          0x90001b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_arm_fadvise64_64               0x90010e    /*   2.6.14 (02060e00)     5.12 (050c0000) */
#define __NR_arm_sync_file_range            0x900155    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_bdflush                        0x900086    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_bind                           0x90011a    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_bpf                            0x900182    /*     3.18 (03120000)     5.12 (050c0000) */
#define __NR_break                          0x900011    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_brk                            0x90002d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_capget                         0x9000b8    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_capset                         0x9000b9    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_chdir                          0x90000c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_chmod                          0x90000f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_chown_old                      0x900010    /*   2.1.80 (02015000)  2.1.132 (02018400) */
#define __NR_chown                          0x9000b6    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_chown32                        0x9000d4    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_chroot                         0x90003d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_clock_adjtime                  0x900174    /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_clock_adjtime64                0x900195    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_getres                   0x900108    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_clock_getres_time64            0x900196    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_gettime32                0x900107    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_clock_gettime64                0x900193    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_nanosleep                0x900109    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_clock_nanosleep_time64         0x900197    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clock_settime32                0x900106    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_clock_settime64                0x900194    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_clone                          0x900078    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_clone3                         0x9001b3    /*      5.3 (05030000)     5.12 (050c0000) */
#define __NR_close                          0x900006    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_close_range                    0x9001b4    /*      5.9 (05090000)     5.12 (050c0000) */
#define __NR_connect                        0x90011b    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_copy_file_range                0x900187    /*      4.5 (04050000)     5.12 (050c0000) */
#define __NR_creat                          0x900008    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_create_module                  0x90007f    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_delete_module                  0x900081    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_dup                            0x900029    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_dup2                           0x90003f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_dup3                           0x900166    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_epoll_create                   0x9000fa    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_epoll_create1                  0x900165    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_epoll_ctl                      0x9000fb    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_epoll_pwait                    0x90015a    /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_epoll_pwait2                   0x9001b9    /*     5.11 (050b0000)     5.12 (050c0000) */
#define __NR_epoll_wait                     0x9000fc    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_eventfd                        0x90015f    /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_eventfd2                       0x900164    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_execve                         0x90000b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_execveat                       0x900183    /*     3.19 (03130000)     5.12 (050c0000) */
#define __NR_exit                           0x900001    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_exit_group                     0x9000f8    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_faccessat                      0x90014e    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_faccessat2                     0x9001b7    /*      5.8 (05080000)     5.12 (050c0000) */
#define __NR_fadvise64_64                   0x90010e    /*    2.6.1 (02060100)   2.6.13 (02060d00) */
#define __NR_fallocate                      0x900160    /*   2.6.24 (02061800)     5.12 (050c0000) */
#define __NR_fanotify_init                  0x90016f    /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_fanotify_mark                  0x900170    /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_fchdir                         0x900085    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fchmod                         0x90005e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fchmodat                       0x90014d    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_fchown                         0x90005f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fchown32                       0x9000cf    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_fchownat                       0x900145    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_fcntl                          0x900037    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fcntl64                        0x9000dd    /*    2.5.0 (02050000)     5.12 (050c0000) */
#define __NR_fdatasync                      0x900094    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fgetxattr                      0x9000e7    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_finit_module                   0x90017b    /*      3.8 (03080000)     5.12 (050c0000) */
#define __NR_flistxattr                     0x9000ea    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_flock                          0x90008f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fork                           0x900002    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fremovexattr                   0x9000ed    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_fsconfig                       0x9001af    /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fsetxattr                      0x9000e4    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_fsmount                        0x9001b0    /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fsopen                         0x9001ae    /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fspick                         0x9001b1    /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_fstat                          0x90006c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fstat64                        0x9000c5    /*   2.3.34 (02032200)     5.12 (050c0000) */
#define __NR_fstatat64                      0x900147    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_fstatfs                        0x900064    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_fstatfs64                      0x90010b    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_fsync                          0x900076    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_ftime                          0x900023    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_ftruncate                      0x90005d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_ftruncate64                    0x9000c2    /*   2.3.34 (02032200)     5.12 (050c0000) */
#define __NR_futex                          0x9000f0    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_futex_time64                   0x9001a6    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_futimesat                      0x900146    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_get_kernel_syms                0x900082    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_get_mempolicy                  0x900140    /*   2.6.14 (02060e00)     5.12 (050c0000) */
#define __NR_get_robust_list                0x900153    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_getcpu                         0x900159    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_getcwd                         0x9000b7    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_getdents                       0x90008d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getdents64                     0x9000d9    /*    2.5.0 (02050000)     5.12 (050c0000) */
#define __NR_getegid                        0x900032    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getegid32                      0x9000ca    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_geteuid                        0x900031    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_geteuid32                      0x9000c9    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_getgid                         0x90002f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getgid32                       0x9000c8    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_getgroups                      0x900050    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getgroups32                    0x9000cd    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_getitimer                      0x900069    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getpeername                    0x90011f    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_getpgid                        0x900084    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getpgrp                        0x900041    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getpid                         0x900014    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getppid                        0x900040    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getpriority                    0x900060    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getrandom                      0x900180    /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_getresgid                      0x9000ab    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getresgid32                    0x9000d3    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_getresuid                      0x9000a5    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getresuid32                    0x9000d1    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_getrlimit                      0x90004c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getrusage                      0x90004d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getsid                         0x900093    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getsockname                    0x90011e    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_getsockopt                     0x900127    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_gettid                         0x9000e0    /*    2.5.2 (02050200)     5.12 (050c0000) */
#define __NR_gettimeofday                   0x90004e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getuid                         0x900018    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_getuid32                       0x9000c7    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_getxattr                       0x9000e5    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_gtty                           0x900020    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_idle                           0x900070    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_init_module                    0x900080    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_inotify_add_watch              0x90013d    /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_inotify_init                   0x90013c    /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_inotify_init1                  0x900168    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_inotify_rm_watch               0x90013e    /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_io_cancel                      0x9000f7    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_io_destroy                     0x9000f4    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_io_getevents                   0x9000f5    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_io_pgetevents                  0x90018f    /*     4.19 (04130000)     5.12 (050c0000) */
#define __NR_io_pgetevents_time64           0x9001a0    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_setup                       0x9000f3    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_io_submit                      0x9000f6    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_io_uring_enter                 0x9001aa    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_uring_register              0x9001ab    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_io_uring_setup                 0x9001a9    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_ioctl                          0x900036    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_ioperm                         0x900065    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_iopl                           0x90006e    /*   2.1.80 (02015000)   2.3.51 (02033300) */
#define __NR_ioprio_get                     0x90013b    /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_ioprio_set                     0x90013a    /*   2.6.13 (02060d00)     5.12 (050c0000) */
#define __NR_ipc                            0x900075    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_kcmp                           0x90017a    /*      3.9 (03090000)     5.12 (050c0000) */
#define __NR_kexec_file_load                0x900191    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_kexec_load                     0x90015b    /*   2.6.21 (02061500)     5.12 (050c0000) */
#define __NR_keyctl                         0x900137    /*   2.6.12 (02060c00)     5.12 (050c0000) */
#define __NR_kill                           0x900025    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_lchown                         0x900010    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_lchown32                       0x9000c6    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_lgetxattr                      0x9000e6    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_link                           0x900009    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_linkat                         0x90014a    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_listen                         0x90011c    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_listxattr                      0x9000e8    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_llistxattr                     0x9000e9    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_lock                           0x900035    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_lookup_dcookie                 0x9000f9    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_lremovexattr                   0x9000ec    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_lseek                          0x900013    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_lsetxattr                      0x9000e3    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_lstat                          0x90006b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_lstat64                        0x9000c4    /*   2.3.34 (02032200)     5.12 (050c0000) */
#define __NR_madvise                        0x9000dc    /*    2.5.0 (02050000)     5.12 (050c0000) */
#define __NR_mbind                          0x90013f    /*   2.6.14 (02060e00)     5.12 (050c0000) */
#define __NR_membarrier                     0x900185    /*      4.3 (04030000)     5.12 (050c0000) */
#define __NR_memfd_create                   0x900181    /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_migrate_pages                  0x900190    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_mincore                        0x9000db    /*    2.5.0 (02050000)     5.12 (050c0000) */
#define __NR_mkdir                          0x900027    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_mkdirat                        0x900143    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_mknod                          0x90000e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_mknodat                        0x900144    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_mlock                          0x900096    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_mlock2                         0x900186    /*      4.4 (04040000)     5.12 (050c0000) */
#define __NR_mlockall                       0x900098    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_mmap2                          0x9000c0    /*   2.3.34 (02032200)     5.12 (050c0000) */
#define __NR_mmap_old                       0x90005a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_modify_ldt                     0x90007b    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_mount                          0x900015    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_mount_setattr                  0x9001ba    /*     5.12 (050c0000)     5.12 (050c0000) */
#define __NR_move_mount                     0x9001ad    /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_move_pages                     0x900158    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_mprotect                       0x90007d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_mpx                            0x900038    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_mq_getsetattr                  0x900117    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_mq_notify                      0x900116    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_mq_open                        0x900112    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_mq_timedreceive                0x900115    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_mq_timedreceive_time64         0x9001a3    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_mq_timedsend                   0x900114    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_mq_timedsend_time64            0x9001a2    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_mq_unlink                      0x900113    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_mremap                         0x9000a3    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_msgctl                         0x900130    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_msgget                         0x90012f    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_msgrcv                         0x90012e    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_msgsnd                         0x90012d    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_msync                          0x900090    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_munlock                        0x900097    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_munlockall                     0x900099    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_munmap                         0x90005b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_name_to_handle_at              0x900172    /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_nanosleep                      0x9000a2    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_nfsservctl                     0x9000a9    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_nice                           0x900022    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_open                           0x900005    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_open_by_handle_at              0x900173    /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_open_tree                      0x9001ac    /*      5.2 (05020000)     5.12 (050c0000) */
#define __NR_openat                         0x900142    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_openat2                        0x9001b5    /*      5.6 (05060000)     5.12 (050c0000) */
#define __NR_pause                          0x90001d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_pciconfig_iobase               0x90010f    /*    2.6.3 (02060300)     5.12 (050c0000) */
#define __NR_pciconfig_read                 0x900110    /*    2.6.3 (02060300)     5.12 (050c0000) */
#define __NR_pciconfig_write                0x900111    /*    2.6.3 (02060300)     5.12 (050c0000) */
#define __NR_perf_counter_open              0x90016c    /*   2.6.31 (02061f00)   2.6.31 (02061f00) */
#define __NR_perf_event_open                0x90016c    /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_personality                    0x900088    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_phys                           0x900034    /*   2.1.80 (02015000)    2.3.6 (02030600) */
#define __NR_pidfd_getfd                    0x9001b6    /*      5.6 (05060000)     5.12 (050c0000) */
#define __NR_pidfd_open                     0x9001b2    /*      5.3 (05030000)     5.12 (050c0000) */
#define __NR_pidfd_send_signal              0x9001a8    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_pipe                           0x90002a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_pipe2                          0x900167    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_pivot_root                     0x9000da    /*    2.5.0 (02050000)     5.12 (050c0000) */
#define __NR_pkey_alloc                     0x90018b    /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_pkey_free                      0x90018c    /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_pkey_mprotect                  0x90018a    /*      4.9 (04090000)     5.12 (050c0000) */
#define __NR_poll                           0x9000a8    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_ppoll                          0x900150    /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_ppoll_time64                   0x90019e    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_prctl                          0x9000ac    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_pread                          0x9000b4    /*   2.1.80 (02015000)   2.5.29 (02051d00) */
#define __NR_pread64                        0x9000b4    /*   2.5.30 (02051e00)     5.12 (050c0000) */
#define __NR_preadv                         0x900169    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_preadv2                        0x900188    /*      4.6 (04060000)     5.12 (050c0000) */
#define __NR_prlimit64                      0x900171    /*   2.6.36 (02062400)     5.12 (050c0000) */
#define __NR_process_madvise                0x9001b8    /*     5.10 (050a0000)     5.12 (050c0000) */
#define __NR_process_vm_readv               0x900178    /*      3.2 (03020000)     5.12 (050c0000) */
#define __NR_process_vm_writev              0x900179    /*      3.2 (03020000)     5.12 (050c0000) */
#define __NR_prof                           0x90002c    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_profil                         0x900062    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_pselect6                       0x90014f    /*   2.6.32 (02062000)     5.12 (050c0000) */
#define __NR_pselect6_time64                0x90019d    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_ptrace                         0x90001a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_pwrite                         0x9000b5    /*   2.1.80 (02015000)   2.5.29 (02051d00) */
#define __NR_pwrite64                       0x9000b5    /*   2.5.30 (02051e00)     5.12 (050c0000) */
#define __NR_pwritev                        0x90016a    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_pwritev2                       0x900189    /*      4.6 (04060000)     5.12 (050c0000) */
#define __NR_query_module                   0x9000a7    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_quotactl                       0x900083    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_read                           0x900003    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_readahead                      0x9000e1    /*    2.5.2 (02050200)     5.12 (050c0000) */
#define __NR_readdir                        0x900059    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_readlink                       0x900055    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_readlinkat                     0x90014c    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_readv                          0x900091    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_reboot                         0x900058    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_recv                           0x900123    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_recvfrom                       0x900124    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_recvmmsg                       0x90016d    /*   2.6.33 (02062100)     5.12 (050c0000) */
#define __NR_recvmmsg_time64                0x9001a1    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_recvmsg                        0x900129    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_remap_file_pages               0x9000fd    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_removexattr                    0x9000eb    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_rename                         0x900026    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_renameat                       0x900149    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_renameat2                      0x90017e    /*     3.15 (030f0000)     5.12 (050c0000) */
#define __NR_request_key                    0x900136    /*   2.6.12 (02060c00)     5.12 (050c0000) */
#define __NR_restart_syscall                0x900000    /*   2.5.55 (02053700)     5.12 (050c0000) */
#define __NR_rmdir                          0x900028    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rseq                           0x90018e    /*     4.18 (04120000)     5.12 (050c0000) */
#define __NR_rt_sigaction                   0x9000ae    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigpending                  0x9000b0    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigprocmask                 0x9000af    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigqueueinfo                0x9000b2    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigreturn                   0x9000ad    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigsuspend                  0x9000b3    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigtimedwait                0x9000b1    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_rt_sigtimedwait_time64         0x9001a5    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_rt_tgsigqueueinfo              0x90016b    /*   2.6.31 (02061f00)     5.12 (050c0000) */
#define __NR_sched_get_priority_max         0x90009f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_get_priority_min         0x9000a0    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_getaffinity              0x9000f2    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_sched_getattr                  0x90017d    /*     3.14 (030e0000)     5.12 (050c0000) */
#define __NR_sched_getparam                 0x90009b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_getscheduler             0x90009d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_rr_get_interval          0x9000a1    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_rr_get_interval_time64   0x9001a7    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_sched_setaffinity              0x9000f1    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_sched_setattr                  0x90017c    /*     3.14 (030e0000)     5.12 (050c0000) */
#define __NR_sched_setparam                 0x90009a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_setscheduler             0x90009c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sched_yield                    0x90009e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_seccomp                        0x90017f    /*     3.17 (03110000)     5.12 (050c0000) */
#define __NR_security                       0x9000df    /*    2.5.2 (02050200)   2.5.49 (02053100) */
#define __NR_select_old                     0x900052    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_semctl                         0x90012c    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_semget                         0x90012b    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_semop                          0x90012a    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_semtimedop                     0x900138    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_semtimedop_time64              0x9001a4    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_send                           0x900121    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_sendfile                       0x9000bb    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_sendfile64                     0x9000ef    /*   2.5.59 (02053b00)     5.12 (050c0000) */
#define __NR_sendmmsg                       0x900176    /*      3.0 (03000000)     5.12 (050c0000) */
#define __NR_sendmsg                        0x900128    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_sendto                         0x900122    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_set_mempolicy                  0x900141    /*   2.6.14 (02060e00)     5.12 (050c0000) */
#define __NR_set_robust_list                0x900152    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_set_tid_address                0x900100    /*   2.6.11 (02060b00)     5.12 (050c0000) */
#define __NR_setdomainname                  0x900079    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setfsgid                       0x90008b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setfsgid32                     0x9000d8    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setfsuid                       0x90008a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setfsuid32                     0x9000d7    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setgid                         0x90002e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setgid32                       0x9000d6    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setgroups                      0x900051    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setgroups32                    0x9000ce    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_sethostname                    0x90004a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setitimer                      0x900068    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setns                          0x900177    /*      3.0 (03000000)     5.12 (050c0000) */
#define __NR_setpgid                        0x900039    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setpriority                    0x900061    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setregid                       0x900047    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setregid32                     0x9000cc    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setresgid                      0x9000aa    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setresgid32                    0x9000d2    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setresuid                      0x9000a4    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setresuid32                    0x9000d0    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setreuid                       0x900046    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setreuid32                     0x9000cb    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setrlimit                      0x90004b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setsid                         0x900042    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setsockopt                     0x900126    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_settimeofday                   0x90004f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setuid                         0x900017    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_setuid32                       0x9000d5    /*   2.3.39 (02032700)     5.12 (050c0000) */
#define __NR_setup                          0x900000    /*   2.1.80 (02015000)   2.3.39 (02032700) */
#define __NR_setxattr                       0x9000e2    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_sgetmask                       0x900044    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_shmat                          0x900131    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_shmctl                         0x900134    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_shmdt                          0x900132    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_shmget                         0x900133    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_shutdown                       0x900125    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_sigaction                      0x900043    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sigaltstack                    0x9000ba    /*    2.2.0 (02020000)     5.12 (050c0000) */
#define __NR_signal                         0x900030    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_signalfd                       0x90015d    /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_signalfd4                      0x900163    /*   2.6.30 (02061e00)     5.12 (050c0000) */
#define __NR_sigpending                     0x900049    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sigprocmask                    0x90007e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sigreturn                      0x900077    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sigsuspend                     0x900048    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_socket                         0x900119    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_socketcall                     0x900066    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_socketpair                     0x900120    /*   2.6.17 (02061100)     5.12 (050c0000) */
#define __NR_splice                         0x900154    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_ssetmask                       0x900045    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_stat                           0x90006a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_stat64                         0x9000c3    /*   2.3.34 (02032200)     5.12 (050c0000) */
#define __NR_statfs                         0x900063    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_statfs64                       0x90010a    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_statx                          0x90018d    /*     4.11 (040b0000)     5.12 (050c0000) */
#define __NR_stime                          0x900019    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_stty                           0x90001f    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_swapoff                        0x900073    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_swapon                         0x900057    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_symlink                        0x900053    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_symlinkat                      0x90014b    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_sync                           0x900024    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sync_file_range2               0x900155    /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_syncfs                         0x900175    /*   2.6.39 (02062700)     5.12 (050c0000) */
#define __NR_syscall                        0x900071    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sysfs                          0x900087    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_sysinfo                        0x900074    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_syslog                         0x900067    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_tee                            0x900156    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_tgkill                         0x90010c    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_time                           0x90000d    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_timer_create                   0x900101    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_timer_delete                   0x900105    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_timer_getoverrun               0x900104    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_timer_gettime                  0x900103    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_timer_gettime64                0x900198    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_timer_settime                  0x900102    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_timer_settime64                0x900199    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_timerfd                        0x90015e    /*   2.6.22 (02061600)   2.6.25 (02061900) */
#define __NR_timerfd_create                 0x90015e    /*   2.6.26 (02061a00)     5.12 (050c0000) */
#define __NR_timerfd_gettime                0x900162    /*   2.6.26 (02061a00)     5.12 (050c0000) */
#define __NR_timerfd_gettime64              0x90019a    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_timerfd_settime                0x900161    /*   2.6.26 (02061a00)     5.12 (050c0000) */
#define __NR_timerfd_settime64              0x90019b    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_times                          0x90002b    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_tkill                          0x9000ee    /*    2.5.6 (02050600)     5.12 (050c0000) */
#define __NR_truncate                       0x90005c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_truncate64                     0x9000c1    /*   2.3.34 (02032200)     5.12 (050c0000) */
#define __NR_ugetrlimit                     0x9000bf    /*    2.5.0 (02050000)     5.12 (050c0000) */
#define __NR_ulimit                         0x90003a    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_umask                          0x90003c    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_umount                         0x900016    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_umount2                        0x900034    /*   2.2.18 (02021200)     5.12 (050c0000) */
#define __NR_uname                          0x90007a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_unlink                         0x90000a    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_unlinkat                       0x900148    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_unshare                        0x900151    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_uselib                         0x900056    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_userfaultfd                    0x900184    /*      4.3 (04030000)     5.12 (050c0000) */
#define __NR_ustat                          0x90003e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_utime                          0x90001e    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_utimensat                      0x90015c    /*   2.6.22 (02061600)     5.12 (050c0000) */
#define __NR_utimensat_time64               0x90019c    /*      5.1 (05010000)     5.12 (050c0000) */
#define __NR_utimes                         0x90010d    /*    2.6.1 (02060100)     5.12 (050c0000) */
#define __NR_vfork                          0x9000be    /*    2.2.8 (02020800)     5.12 (050c0000) */
#define __NR_vhangup                        0x90006f    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_vm86                           0x9000a6    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_vmsplice                       0x900157    /*   2.6.20 (02061400)     5.12 (050c0000) */
#define __NR_vserver                        0x900139    /*   2.6.12 (02060c00)     5.12 (050c0000) */
#define __NR_wait4                          0x900072    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_waitid                         0x900118    /*    2.6.9 (02060900)     5.12 (050c0000) */
#define __NR_waitpid                        0x900007    /*   2.1.80 (02015000)   2.5.75 (02054b00) */
#define __NR_write                          0x900004    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_writev                         0x900092    /*   2.1.80 (02015000)     5.12 (050c0000) */
#define __NR_xmknod                         0x9000b7    /*   2.1.94 (02015e00)  2.1.132 (02018400) */
#define __NR_xstat                          0x9000b6    /*   2.1.94 (02015e00)  2.1.132 (02018400) */

#if !defined(__ASSEMBLER__) && !defined(__target_featuredef)

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <polyglot/count_args.h>

long __syscall_error(long);
/* XXX: technically, this function does exist, but it doesn't consistently work
 * on ARM OABI for unknown reasons, so we are not defining it properly here */
// long __syscall();

#define __LOAD_ARGS_0()
#define __ASM_ARGS_0()
#define __LOAD_ARGS_1(a1) \
    register long _r0 asm ("r0") = (long)(a1);
#define __ASM_ARGS_1() "r" (_r0)
#define __LOAD_ARGS_2(a1, a2) \
    __LOAD_ARGS_1(a1) \
    register long _r1 asm ("r1") = (long)(a2);
#define __ASM_ARGS_2() __ASM_ARGS_1(), "r" (_r1)
#define __LOAD_ARGS_3(a1, a2, a3) \
    __LOAD_ARGS_2(a1, a2) \
    register long _r2 asm ("r2") = (long)(a3);
#define __ASM_ARGS_3() __ASM_ARGS_2(), "r" (_r2)
#define __LOAD_ARGS_4(a1, a2, a3, a4) \
    __LOAD_ARGS_3(a1, a2, a3) \
    register long _r3 asm ("r3") = (long)(a4);
#define __ASM_ARGS_4() __ASM_ARGS_3(), "r" (_r3)
#define __LOAD_ARGS_5(a1, a2, a3, a4, a5) \
    __LOAD_ARGS_4(a1, a2, a3, a4) \
    register long _r4 asm ("r4") = (long)(a5);
#define __ASM_ARGS_5() __ASM_ARGS_4(), "r" (_r4)
#define __LOAD_ARGS_6(a1, a2, a3, a4, a5, a6) \
    __LOAD_ARGS_5(a1, a2, a3, a4, a5) \
    register long _r5 asm ("r5") = (long)(a6);
#define __ASM_ARGS_6() __ASM_ARGS_5(), "r" (_r5)

#define syscall(s,...) \
    __syscall_argc(COUNT_ARGS(__VA_ARGS__), s, ##__VA_ARGS__)
#define __syscall_argc(nr, sys, ...) \
({ \
    register long _out asm ("r0"); \
    long _ret; \
    BOOST_PP_CAT(__LOAD_ARGS_, nr)(__VA_ARGS__); \
    asm volatile ( \
        "swi " BOOST_PP_STRINGIZE(sys) \
        : "=r" (_out) \
        : BOOST_PP_CAT(__ASM_ARGS_, nr)() \
        : "memory" \
    ); \
    _ret = _out; \
    if ((_ret < 0) && (_ret > -4096)) \
        _ret = __syscall_error(-_ret); \
    _ret; \
})

#endif // !__ASSEMBLER__ && !__target_featuredef

#endif // _LINUX_ARM_SYSCALL_OABI_H
