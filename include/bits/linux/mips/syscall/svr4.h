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

#ifndef _LINUX_MIPS_SYSCALL_SVR4_H
#define _LINUX_MIPS_SYSCALL_SVR4_H _LINUX_MIPS_SYSCALL_SVR4_H

#define __NR_SVR4                           0           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_PYRAMID_forcerr           144         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_PYRAMID_mpcntl            145         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_PYRAMID_statis            142         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_PYRAMID_tuning            143         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_acancel                   110         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_access                    33          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_adjtime                   138         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_advfs                     70          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_alarm                     27          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_aread                     201         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_areadv                    207         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_astatus                   205         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_async                     111         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_await                     206         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_awrite                    202         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_awritev                   208         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_chdir                     12          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_chmod                     15          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_chown                     16          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_chroot                    61          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_clocal                    127         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_close                     6           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_creat                     8           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_cxenix                    40          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_dup                       41          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_evsys                     101         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_evtrapret                 102         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_exch                      56          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_exec                      11          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_exece                     59          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_exit                      1           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fchdir                    120         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fchmod                    93          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fchown                    94          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fcntl                     62          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fork                      2           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fpathconf                 118         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fstat                     28          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fstatfs                   38          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fstatvfs                  104         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fsync                     58          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_fxstat                    125         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getdents                  81          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getgid                    47          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getgroups                 92          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getmsg                    85          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getpid                    20          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getpmsg                   132         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getrlimit                 129         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_getuid                    24          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_gtime                     13          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_gtty                      32          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_hrtsys                    109         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_ioctl                     54          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_kill                      37          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_lchown                    130         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_libattach                 82          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_libdetach                 83          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_link                      9           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_listio                    203         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_lseek                     19          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_lstat                     88          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_lxstat                    124         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_memcntl                   131         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mincore                   114         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mips_acancel              204         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mkdir                     80          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mknod                     14          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mmap                      115         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mount                     21          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_mprotect                  116         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_msgsys                    49          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_munmap                    117         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_nfssys                    106         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_nice                      34          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_nuname                    135         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_open                      5           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_pathconf                  113         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_pause                     29          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_pipe                      42          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_plock                     45          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_poll                      87          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_priocntlset               112         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_profil                    44          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_ptrace                    26          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_putmsg                    86          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_putpmsg                   133         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_rdebug                    76          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_read                      3           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_readlink                  90          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_readv                     121         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_rename                    134         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_rfstart                   74          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_rfstop                    77          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_rfsys                     78          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_rmdir                     79          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sbreak                    17          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_semsys                    53          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setcontext                100         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setegid                   136         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_seteuid                   141         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setgid                    46          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setgroups                 91          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setpgrp                   39          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setrlimit                 128         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_setuid                    23          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_shmsys                    52          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sig                       48          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sigaction                 98          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sigaltstack               97          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sigpending                99          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sigprocmask               95          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sigsendset                108         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sigsuspend                96          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_stat                      18          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_statfs                    35          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_statvfs                   103         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_stime                     25          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_stty                      31          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_symlink                   89          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sync                      36          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sysacct                   51          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_syscall                   0           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sysconf                   137         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sysfs                     84          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sysinfo                   139         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_sysmips                   50          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_times                     43          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_uadmin                    55          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_ulimit                    63          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_umask                     60          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_umount                    22          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_unadvfs                   71          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_unlink                    10          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_unused1                   72          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_unused2                   73          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_unused3                   75          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_utime                     30          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_utssys                    57          /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_vfork                     119         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_wait                      7           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_waitid                    107         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_write                     4           /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_writev                    122         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_xmknod                    126         /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SVR4_xstat                     123         /*   1.3.48 (01033000)   2.3.51 (02033300) */

#endif // _LINUX_MIPS_SYSCALL_SVR4_H
