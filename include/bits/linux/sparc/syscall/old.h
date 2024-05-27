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

#ifndef _LINUX_SPARC_SYSCALL_OLD_H
#define _LINUX_SPARC_SYSCALL_OLD_H 1

#define __NR__llseek                        140         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR__newselect                     142         /*    1.3.0 (01030000)   1.3.10 (01030a00) */
#define __NR_access                         33          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_acct                           51          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_adjtimex                       124         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_afs_syscall                    137         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_alarm                          27          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_bdflush                        134         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_break                          17          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_brk                            45          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_chdir                          12          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_chmod                          15          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_chroot                         61          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_clone                          120         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_close                          6           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_creat                          8           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_create_module                  127         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_delete_module                  129         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_dup                            41          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_dup2                           63          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_execve                         11          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_exit                           1           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_fchdir                         133         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_fchmod                         94          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_fchown                         95          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_fcntl                          55          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_flock                          143         /*    1.3.0 (01030000)   1.3.10 (01030a00) */
#define __NR_fork                           2           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_fstat                          108         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_fstatfs                        100         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_fsync                          118         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ftime                          35          /*   1.1.73 (01014900)    2.2.3 (02020300) */
#define __NR_ftruncate                      93          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_get_kernel_syms                130         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getdents                       141         /*    1.3.0 (01030000)   1.3.10 (01030a00) */
#define __NR_getegid                        50          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_geteuid                        49          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_getgid                         47          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_getgroups                      80          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getitimer                      105         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getpgid                        132         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getpgrp                        65          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getpid                         20          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_getppid                        64          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getpriority                    96          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getrlimit                      76          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getrusage                      77          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_gettimeofday                   78          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_getuid                         24          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_gtty                           32          /*   1.1.73 (01014900)    2.2.3 (02020300) */
#define __NR_idle                           112         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_init_module                    128         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ioctl                          54          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_ioperm                         101         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_iopl                           110         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ipc                            117         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_kill                           37          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_link                           9           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_lock                           53          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_lseek                          19          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_lstat                          107         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_mkdir                          39          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_mknod                          14          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_mmap                           90          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_modify_ldt                     123         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_mount                          21          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_mprotect                       125         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_mpx                            56          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_munmap                         91          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_nice                           34          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_open                           5           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_pause                          29          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_personality                    136         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_phys                           52          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_pipe                           42          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_prof                           44          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_profil                         98          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ptrace                         26          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_quotactl                       131         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_read                           3           /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_readdir                        89          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_readlink                       85          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_reboot                         88          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_rename                         38          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_rmdir                          40          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_select                         82          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setdomainname                  121         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setfsgid                       139         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setfsuid                       138         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setgid                         46          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_setgroups                      81          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sethostname                    74          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setitimer                      104         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setpgid                        57          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setpriority                    97          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setregid                       71          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setreuid                       70          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setrlimit                      75          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setsid                         66          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_settimeofday                   79          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_setuid                         23          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_setup                          0           /*   1.1.73 (01014900)  2.1.123 (02017b00) */
#define __NR_sgetmask                       68          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sigaction                      67          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_signal                         48          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_sigpending                     73          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sigprocmask                    126         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sigreturn                      119         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sigsuspend                     72          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_socketcall                     102         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ssetmask                       69          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_stat                           106         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_statfs                         99          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_stime                          25          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_stty                           31          /*   1.1.73 (01014900)    2.2.3 (02020300) */
#define __NR_swapoff                        115         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_swapon                         87          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_symlink                        83          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sync                           36          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_sysfs                          135         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_sysinfo                        116         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_syslog                         103         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_time                           13          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_times                          43          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_truncate                       92          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ulimit                         58          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_umask                          60          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_umount                         22          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_uname                          122         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_unlink                         10          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_uselib                         86          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_ustat                          62          /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_utime                          30          /*   1.1.73 (01014900)     5.12 (050c0000) */
#define __NR_vhangup                        111         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_vm86                           113         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_wait4                          114         /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_waitpid                        7           /*   1.1.73 (01014900)   1.3.10 (01030a00) */
#define __NR_write                          4           /*   1.1.73 (01014900)     5.12 (050c0000) */

#endif // _LINUX_SPARC_SYSCALL_OLD_H
