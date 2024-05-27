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

#ifndef _LINUX_MIPS_SYSCALL_SYSV_H
#define _LINUX_MIPS_SYSCALL_SYSV_H _LINUX_MIPS_SYSCALL_SYSV_H

#define __NR_SYSV                           1000        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_BSD_getime                1128        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_BSDgetpgrp                1143        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_BSDsetpgrp                1144        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_accept                    1089        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_access                    1033        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_acct                      1051        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_adjtime                   1127        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_advfs                     1070        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_alarm                     1027        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_async_daemon              1121        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_bind                      1090        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_brk                       1017        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_cachectl                  1151        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_cacheflush                1150        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_chdir                     1012        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_chmod                     1015        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_chown                     1016        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_chroot                    1061        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_close                     1006        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_connect                   1091        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_creat                     1008        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_dmi                       1186        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_dup                       1041        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_execv                     1011        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_execve                    1059        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_exit                      1001        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_exportfs                  1122        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fchdir                    1147        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fchmod                    1153        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fchown                    1152        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fcntl                     1062        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fork                      1002        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fstat                     1028        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fstatfs                   1038        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fstatvfs                  1175        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fsync                     1146        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ftruncate                 1113        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ftruncate64               1184        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_fxstat                    1160        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getcontext                1168        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getdents                  1081        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getdomainname             1110        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getfh                     1120        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getgid                    1047        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_gethostid                 1092        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_gethostname               1108        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getitimer                 1125        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getmsg                    1085        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getpagesize               1140        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getpeername               1093        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getpid                    1020        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getpmsg                   1176        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getrlimit                 1148        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getrlimit64               1075        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getsockname               1094        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getsockopt                1095        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_getuid                    1024        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_gtty                      1032        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ioctl                     1054        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_kill                      1037        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ksigaction                1162        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ksigqueue                 1180        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_lchown                    1178        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_libdetach                 1142        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_link                      1009        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_listen                    1096        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_lseek                     1019        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_lseek64                   1078        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_lstat                     1117        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_lxstat                    1159        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_madvise                   1138        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_mkdir                     1080        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_mknod                     1014        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_mmap                      1134        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_mmap64                    1185        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_mount                     1021        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_mprotect                  1136        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_msgsys                    1049        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_msync                     1137        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_munmap                    1135        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_nanosleep                 1077        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_nfsmount                  1118        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_nfssvc                    1119        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_nice                      1034        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_nuname                    1157        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_open                      1005        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_pagelock                  1139        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_pause                     1029        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_pipe                      1042        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_plock                     1045        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_poll                      1087        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_prctl                     1130        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_pread                     1187        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_priocntl                  1179        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_procblk                   1131        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_profil                    1044        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ptrace                    1026        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_putmsg                    1086        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_putpmsg                   1177        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_pwrite                    1188        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_quotactl                  1141        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_read                      1003        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_readlink                  1116        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_readv                     1181        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_recv                      1097        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_recvfrom                  1098        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_recvmsg                   1099        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_rename                    1114        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_rfstart                   1074        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_rmdir                     1079        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_rmount                    1072        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_rumount                   1073        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_select                    1100        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_semsys                    1053        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_send                      1101        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sendmsg                   1102        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sendto                    1103        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setcontext                1169        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setdomainname             1111        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setgid                    1046        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sethostid                 1104        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sethostname               1109        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setitimer                 1126        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setpgrp                   1039        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setregid                  1123        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setreuid                  1124        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setrlimit                 1149        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setrlimit64               1076        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setsockopt                1105        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_setuid                    1023        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sgigsc                    1133        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sgikopt                   1083        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sginap                    1082        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_shmsys                    1052        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_shutdown                  1106        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sig                       1048        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigaltstack               1172        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigpending                1163        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigpoll                   1166        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigprocmask               1164        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigreturn                 1088        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigsendset                1173        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigstack                  1171        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sigsuspend                1165        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_socket                    1107        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_socketpair                1155        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sproc                     1129        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sprocsp                   1132        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_stat                      1018        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_statfs                    1035        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_statvfs                   1174        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_stime                     1025        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_stty                      1031        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_swapctl                   1167        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_symlink                   1115        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sync                      1036        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_syscall                   1000        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sysfs                     1084        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sysinfo                   1156        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sysmips                   1050        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_sysmp                     1056        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_syssgi                    1040        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_time                      1013        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_times                     1043        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_truncate                  1112        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_truncate64                1183        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_uadmin                    1055        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_ulimit                    1063        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_umask                     1060        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_umount                    1022        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_unadvfs                   1071        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_unlink                    1010        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_utime                     1030        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_utssys                    1057        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_vhangup                   1145        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_wait                      1007        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_wait3                     1154        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_waitsys                   1170        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_write                     1004        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_writev                    1182        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_xmknod                    1161        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_SYSV_xstat                     1158        /*   1.3.48 (01033000)   2.3.51 (02033300) */

#endif // _LINUX_MIPS_SYSCALL_SYSV_H
