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

#ifndef _LINUX_MIPS_SYSCALL_BSD43_H
#define _LINUX_MIPS_SYSCALL_BSD43_H _LINUX_MIPS_SYSCALL_BSD43_H

#define __NR_BSD43_acancel                  2187        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_accept                   2176        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_access                   2033        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_adjtime                  2140        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_alarm                    2027        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_aread                    2184        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_areadv                   2190        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_astatus                  2188        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_async_daemon             2163        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_await                    2189        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_awrite                   2185        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_awritev                  2191        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_bind                     2104        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_cachectl                 2153        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_cacheflush               2152        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_chdir                    2012        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_chmod                    2015        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_chown                    2016        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_chroot                   2061        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_close                    2006        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_connect                  2098        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_creat                    2008        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_debug                    2154        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_dup                      2041        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_dup2                     2090        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_exec                     2011        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_execve                   2059        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_exit                     2001        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_exportfs                 2172        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fchmod                   2124        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fchown                   2123        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fcntl                    2092        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_flock                    2131        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fork                     2002        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fstat                    2062        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fstatfs                  2161        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_fsync                    2095        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_ftime                    2035        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_ftruncate                2130        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getdirentries            2159        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getdomainname            2165        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getdopt                  2091        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getdtablesize            2089        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getgid                   2047        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getgroups                2079        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_gethostid                2142        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_gethostname              2087        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getitimer                2086        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getpagesize              2064        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getpeername              2182        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getpgrp                  2081        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getpid                   2020        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getpriority              2100        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getrlimit                2144        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getrusage                2117        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getsockname              2183        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getsockopt               2118        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_gettimeofday             2116        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_getuid                   2024        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_gtty                     2032        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_ioctl                    2054        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_kill                     2037        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_killpg                   2146        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_libattach                2174        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_libdetach                2175        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_link                     2009        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_listen                   2106        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_listio                   2186        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_lock                     2053        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_lseek                    2019        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_lstat                    2040        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_madvise                  2075        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mincore                  2078        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mipshwconf               2171        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mkdir                    2136        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mknod                    2014        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mmap                     2071        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mount                    2021        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mprotect                 2074        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mpxchan                  2056        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_mremap                   2065        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_msgsys                   2045        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_munmap                   2073        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_nfs_getfh                2164        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_nfs_mount                2157        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_nfs_svc                  2158        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_nfsfh_open               2173        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_nice                     2034        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_open                     2005        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_pause                    2029        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_pcfs_mount               2167        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_phys                     2052        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_pipe                     2042        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_profil                   2044        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_ptrace                   2026        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_qquota                   2149        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_quota                    2148        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_quotactl                 2168        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_read                     2003        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_readlink                 2058        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_readv                    2120        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_reboot                   2055        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_recv                     2102        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_recvfrom                 2180        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_recvmsg                  2179        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_rename                   2128        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_rmdir                    2137        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sbreak                   2017        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sbrk                     2069        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_select                   2093        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_semsys                   2132        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_send                     2101        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sendmsg                  2181        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sendto                   2133        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setdomainname            2166        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setdopt                  2094        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setgid                   2046        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setgroups                2080        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sethostid                2143        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sethostname              2088        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setitimer                2083        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setpgrp                  2082        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setpriority              2096        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setregid                 2127        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setreuid                 2126        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setrlimit                2145        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setsockopt               2105        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_settimeofday             2122        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_setuid                   2023        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_shmsys                   2147        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_shutdown                 2134        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigblock                 2109        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigcleanup               2139        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigpause                 2111        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigreturn                2103        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigsetmask               2110        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigstack                 2112        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sigvec                   2108        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_smount                   2170        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_socket                   2097        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_socketpair               2135        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_ssig                     2048        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sstk                     2070        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_stat                     2038        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_statfs                   2160        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_stime                    2025        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_stty                     2031        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_swapon                   2085        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_symlink                  2057        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sync                     2036        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sysacct                  2051        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_syscall                  2000        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_sysmips                  2151        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_time                     2013        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_times                    2043        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_truncate                 2129        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_umask                    2060        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_umount                   2022        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_unlink                   2010        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_unmount                  2162        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_utime                    2030        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_utimes                   2138        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vadvise                  2072        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vfork                    2066        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vhangup                  2076        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vlimit                   2077        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vread                    2067        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vtimes                   2107        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vtrace                   2115        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_vwrite                   2068        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_wait                     2007        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_wait3                    2084        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_write                    2004        /*   1.3.48 (01033000)   2.3.51 (02033300) */
#define __NR_BSD43_writev                   2121        /*   1.3.48 (01033000)   2.3.51 (02033300) */

#endif // _LINUX_MIPS_SYSCALL_BSD43_H
