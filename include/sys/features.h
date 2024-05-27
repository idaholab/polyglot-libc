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

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H _SYS_FEATURES_H

#include <target/features.h>

/* default any features that weren't defined one way or another so that the
 * macros are always defined, no matter if the feature is supported or not, and
 * so that we don't have to do this in every target's header... */

#ifndef HAS_accept
#define HAS_accept 0
#endif
#ifndef HAS_alarm
#define HAS_alarm 0
#endif
#ifndef HAS_bind
#define HAS_bind 0
#endif
#ifndef HAS_brk
#define HAS_brk 0
#endif
#ifndef HAS_chdir
#define HAS_chdir 0
#endif
#ifndef HAS_clone
#define HAS_clone 0
#endif
#ifndef HAS_close
#define HAS_close 0
#endif
#ifndef HAS_connect
#define HAS_connect 0
#endif
#ifndef HAS_dup
#define HAS_dup 0
#endif
#ifndef HAS_dup2
#define HAS_dup2 0
#endif
#ifndef HAS_dup3
#define HAS_dup3 0
#endif
#ifndef HAS_execve
#define HAS_execve 0
#endif
#ifndef HAS_exit
#define HAS_exit 0
#endif
#ifndef HAS_fchdir
#define HAS_fchdir 0
#endif
#ifndef HAS_fchmod
#define HAS_fchmod 0
#endif
#ifndef HAS_fchmodat
#define HAS_fchmodat 0
#endif
#ifndef HAS_fcntl
#define HAS_fcntl 0
#endif
#ifndef HAS_fork
#define HAS_fork 0
#endif
#ifndef HAS_fstat
#define HAS_fstat 0
#endif
#ifndef HAS_fstatat
#define HAS_fstatat 0
#endif
#ifndef HAS_fsync
#define HAS_fsync 0
#endif
#ifndef HAS_getcwd
#define HAS_getcwd 0
#endif
#ifndef HAS_getegid
#define HAS_getegid 0
#endif
#ifndef HAS_geteuid
#define HAS_geteuid 0
#endif
#ifndef HAS_getgid
#define HAS_getgid 0
#endif
#ifndef HAS_getpagesize
#define HAS_getpagesize 0
#endif
#ifndef HAS_getpeername
#define HAS_getpeername 0
#endif
#ifndef HAS_getpid
#define HAS_getpid 0
#endif
#ifndef HAS_getppid
#define HAS_getppid 0
#endif
#ifndef HAS_getrlimit
#define HAS_getrlimit 0
#endif
#ifndef HAS_getrusage
#define HAS_getrusage 0
#endif
#ifndef HAS_getsid
#define HAS_getsid 0
#endif
#ifndef HAS_getsockname
#define HAS_getsockname 0
#endif
#ifndef HAS_gettimeofday
#define HAS_gettimeofday 0
#endif
#ifndef HAS_getuid
#define HAS_getuid 0
#endif
#ifndef HAS_ioctl
#define HAS_ioctl 0
#endif
#ifndef HAS_kill
#define HAS_kill 0
#endif
#ifndef HAS_listen
#define HAS_listen 0
#endif
#ifndef HAS_lseek
#define HAS_lseek 0
#endif
#ifndef HAS_lstat
#define HAS_lstat 0
#endif
#ifndef HAS_mkdir
#define HAS_mkdir 0
#endif
#ifndef HAS_mkdirat
#define HAS_mkdirat 0
#endif
#ifndef HAS_mmap
#define HAS_mmap 0
#endif
#ifndef HAS_msgctl
#define HAS_msgctl 0
#endif
#ifndef HAS_msgget
#define HAS_msgget 0
#endif
#ifndef HAS_msgrcv
#define HAS_msgrcv 0
#endif
#ifndef HAS_msgsnd
#define HAS_msgsnd 0
#endif
#ifndef HAS_munmap
#define HAS_munmap 0
#endif
#ifndef HAS_nanosleep
#define HAS_nanosleep 0
#endif
#ifndef HAS_open
#define HAS_open 0
#endif
#ifndef HAS_openat
#define HAS_openat 0
#endif
#ifndef HAS_pipe
#define HAS_pipe 0
#endif
#ifndef HAS_pipe2
#define HAS_pipe2 0
#endif
#ifndef HAS_poll
#define HAS_poll 0
#endif
#ifndef HAS_ppoll
#define HAS_ppoll 0
#endif
#ifndef HAS_prlimit64
#define HAS_prlimit64 0
#endif
#ifndef HAS_pselect
#define HAS_pselect 0
#endif
#ifndef HAS_read
#define HAS_read 0
#endif
#ifndef HAS_readdir
#define HAS_readdir 0
#endif
#ifndef HAS_readlink
#define HAS_readlink 0
#endif
#ifndef HAS_readlinkat
#define HAS_readlinkat 0
#endif
#ifndef HAS_recv
#define HAS_recv 0
#endif
#ifndef HAS_recvfrom
#define HAS_recvfrom 0
#endif
#ifndef HAS_select
#define HAS_select 0
#endif
#ifndef HAS_semctl
#define HAS_semctl 0
#endif
#ifndef HAS_semget
#define HAS_semget 0
#endif
#ifndef HAS_semop
#define HAS_semop 0
#endif
#ifndef HAS_send
#define HAS_send 0
#endif
#ifndef HAS_sendto
#define HAS_sendto 0
#endif
#ifndef HAS_setegid
#define HAS_setegid 0
#endif
#ifndef HAS_seteuid
#define HAS_seteuid 0
#endif
#ifndef HAS_setgid
#define HAS_setgid 0
#endif
#ifndef HAS_setregid
#define HAS_setregid 0
#endif
#ifndef HAS_setresgid
#define HAS_setresgid 0
#endif
#ifndef HAS_setresuid
#define HAS_setresuid 0
#endif
#ifndef HAS_setreuid
#define HAS_setreuid 0
#endif
#ifndef HAS_setrlimit
#define HAS_setrlimit 0
#endif
#ifndef HAS_setsid
#define HAS_setsid 0
#endif
#ifndef HAS_setsockopt
#define HAS_setsockopt 0
#endif
#ifndef HAS_setuid
#define HAS_setuid 0
#endif
#ifndef HAS_shmat
#define HAS_shmat 0
#endif
#ifndef HAS_shmctl
#define HAS_shmctl 0
#endif
#ifndef HAS_shmdt
#define HAS_shmdt 0
#endif
#ifndef HAS_shmget
#define HAS_shmget 0
#endif
#ifndef HAS_shutdown
#define HAS_shutdown 0
#endif
#ifndef HAS_sigaction
#define HAS_sigaction 0
#endif
#ifndef HAS_sigprocmask
#define HAS_sigprocmask 0
#endif
#ifndef HAS_sigsuspend
#define HAS_sigsuspend 0
#endif
#ifndef HAS_socket
#define HAS_socket 0
#endif
#ifndef HAS_stat
#define HAS_stat 0
#endif
#ifndef HAS_statx
#define HAS_statx 0
#endif
#ifndef HAS_sync
#define HAS_sync 0
#endif
#ifndef HAS_time
#define HAS_time 0
#endif
#ifndef HAS_times
#define HAS_times 0
#endif
#ifndef HAS_umask
#define HAS_umask 0
#endif
#ifndef HAS_uname
#define HAS_uname 0
#endif
#ifndef HAS_unlink
#define HAS_unlink 0
#endif
#ifndef HAS_unlinkat
#define HAS_unlinkat 0
#endif
#ifndef HAS_wait
#define HAS_wait 0
#endif
#ifndef HAS_wait4
#define HAS_wait4 0
#endif
#ifndef HAS_waitid
#define HAS_waitid 0
#endif
#ifndef HAS_waitpid
#define HAS_waitpid 0
#endif
#ifndef HAS_write
#define HAS_write 0
#endif

/******************************************************************************/

#endif // _SYS_FEATURES_H
