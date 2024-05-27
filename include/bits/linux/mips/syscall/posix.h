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

#ifndef _LINUX_MIPS_SYSCALL_POSIX_H
#define _LINUX_MIPS_SYSCALL_POSIX_H _LINUX_MIPS_SYSCALL_POSIX_H

#define __NR_POSIX                          3000        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_BSD_getpagesize          3158        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_blkproc              3131        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_bsdgettime           3128        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_getpagesize          3140        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_getpgrp              3143        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_libattach            3141        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_libdetach            3142        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_madvise              3138        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_mmap                 3134        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_mpin                 3139        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_mprotect             3136        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_msync                3137        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_munmap               3135        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_prctl                3130        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_setpgrp              3144        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_setregid             3123        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_setreuid             3124        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_sgigsc               3133        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_SGI_sproc                3129        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_accept                   3089        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_access                   3033        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_adjtime                  3127        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_advfs                    3070        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_alarm                    3027        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_async_daemon             3121        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_bind                     3090        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_cachectl                 3151        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_cacheflush               3150        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_chdir                    3012        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_chmod                    3015        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_chown                    3016        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_chroot                   3061        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_close                    3006        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_connect                  3091        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_creat                    3008        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_dup                      3041        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_dup2                     3169        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_exch                     3056        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_exec                     3011        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_exece                    3059        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_exit                     3001        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_exportfs                 3122        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_fchmod                   3153        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_fchown                   3152        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_fcntl                    3062        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_fork                     3002        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_fstat                    3028        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_fstatfs                  3038        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_ftruncate                3113        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getdents                 3081        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getdomainname            3110        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getgid                   3047        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getgroups                3162        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_gethostid                3092        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_gethostname              3108        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getitimer                3125        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getmaxsig                3264        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getmsg                   3085        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getpeername              3093        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getpgrp                  3039        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getpid                   3020        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getrlimit                3166        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getrusage                3165        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getsockname              3094        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getsockopt               3095        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_gettimeofday             3164        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_getuid                   3024        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_gtime                    3013        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_gtty                     3032        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_ioctl                    3054        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_kill                     3037        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_link                     3009        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_listen                   3096        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_lock                     3045        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_lseek                    3019        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_lstat                    3117        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_madvise                  3157        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_mkdir                    3080        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_mknod                    3014        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_mmap                     3155        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_mount                    3021        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_msgsys                   3049        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_munmap                   3156        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_netboot                  3260        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_netunboot                3261        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_nfs_getfh                3120        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_nfs_mount                3118        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_nfs_svc                  3119        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_nice                     3034        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_open                     3005        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_pause                    3029        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_pipe                     3042        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_poll                     3087        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_profil                   3044        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_ptrace                   3026        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_putmsg                   3086        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rdebug                   3076        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rdump                    3262        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_read                     3003        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_readlink                 3116        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_recv                     3097        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_recvfrom                 3098        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_recvmsg                  3099        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rename                   3114        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rfstart                  3074        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rfstop                   3077        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rfsys                    3078        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rmdir                    3079        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rmount                   3072        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_rumount                  3073        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sbreak                   3017        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_select                   3100        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_semsys                   3053        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_send                     3101        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sendmsg                  3102        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sendto                   3103        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setdomainname            3111        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setgid                   3046        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setgroups                3163        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sethostid                3104        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sethostname              3109        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setitimer                3126        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setpgid                  3161        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setregid                 3160        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setreuid                 3159        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setrlimit                3167        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setsid                   3263        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setsockopt               3105        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_setuid                   3023        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sgikopt                  3083        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sginap                   3082        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_shmsys                   3052        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_shutdown                 3106        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sig                      3048        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sigaction                3268        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sigpending               3265        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sigprocmask              3266        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sigreturn                3088        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sigsuspend               3267        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_socket                   3107        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_stat                     3018        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_statfs                   3035        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_stime                    3025        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_stty                     3031        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_symlink                  3115        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sync                     3036        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sysacct                  3051        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_syscall                  3000        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sysfs                    3084        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_sysmips                  3050        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_syssgi                   3040        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_times                    3043        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_truncate                 3112        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_uadmin                   3055        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_ulimit                   3063        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_umask                    3060        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_umount                   3022        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_unadvfs                  3071        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_unlink                   3010        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_utime                    3030        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_utssys                   3057        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_wait                     3007        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_wait3                    3154        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_waitpid                  3168        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_POSIX_write                    3004        /*   1.3.48 (01033000)   2.3.51 (02033300) */

#endif // _LINUX_MIPS_SYSCALL_POSIX_H
