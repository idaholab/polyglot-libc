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

#ifndef _LINUX_FEATURES_H
#define _LINUX_FEATURES_H _LINUX_FEATURES_H

#include <_platform.h>
#if __has_include(__target_os_arch_header(features.h))
#include __target_os_arch_header(features.h)
#endif

#include <bits/linux/syscall.h>

/* DIRENT *********************************************************************/

/* getdents64
 * getdents
 * readdir
 *  -> *readdir
 */
#if (defined(__NR_getdents64) \
    || defined(__NR_getdents) \
    || defined(__NR_readdir))
#define HAS_NATIVE_readdir 1
#define HAS_readdir 1
#endif

/* FCNTL **********************************************************************/

/* fcntl
 *  -> *fcntl
 */
#if defined(__NR_fcntl)
#define HAS_NATIVE_fcntl 1
#define HAS_fcntl 1
#endif

/* open
 *  -> *open
 * +fchdir
 *  ->  openat
 */
#if defined(__NR_open)
#define HAS_NATIVE_open 1
#define HAS_open 1
#if defined(HAS_fchdir)
#define HAS_openat 1
#endif
#endif

/* openat
 *  -> *openat
 *  ->  open
 */
#if defined(__NR_openat)
#define HAS_NATIVE_openat 1
#define HAS_openat 1
#define HAS_open 1
#endif

/* POLL ***********************************************************************/

/* poll
 *  -> *poll
 *  ->  ppoll
 */
#if defined(__NR_poll)
#define HAS_NATIVE_poll 1
#define HAS_poll 1
#define HAS_ppoll 1
#endif

/* ppoll
 *  -> *ppoll
 *  ->  poll
 */
#if defined(__NR_ppoll)
#define HAS_NATIVE_ppoll 1
#define HAS_ppoll 1
#define HAS_poll 1
#endif

/* SCHED **********************************************************************/

/* clone
 *  -> *clone
 *  ->  fork
 */
#if defined(__NR_clone)
#define HAS_NATIVE_clone 1
#define HAS_clone 1
#define HAS_fork 1 /* <unistd.h> */
#endif

/* SIGNAL *********************************************************************/

/* alarm
 *  -> *alarm
 */
#if defined(__NR_alarm)
#define HAS_NATIVE_alarm 1
#define HAS_alarm 1
#endif

/* kill
 *  -> *kill
 */
#if defined(__NR_kill)
#define HAS_NATIVE_kill 1
#define HAS_kill 1
#endif

/* rt_sigaction
 * sigaction
 *  -> *sigaction
 */
#if (defined(__NR_rt_sigaction) \
    || defined(__NR_sigaction))
#define HAS_NATIVE_sigaction 1
#define HAS_sigaction 1
#endif

/* rt_sigprocmask
 * sigprocmask
 *  -> *sigprocmask
 */
#if (defined(__NR_rt_sigprocmask) \
    || defined(__NR_sigprocmask))
#define HAS_NATIVE_sigprocmask 1
#define HAS_sigprocmask 1
#endif

/* rt_sigsuspend
 * rt_sigsuspend_old
 * sigsuspend
 *  -> *sigsuspend
 */
#if (defined(__NR_rt_sigsuspend) \
    || defined(__NR_rt_sigsuspend_old) \
    || defined(__NR_sigsuspend))
#define HAS_NATIVE_sigsuspend 1
#define HAS_sigsuspend 1
#endif

/* STDLIB *********************************************************************/

/* SYS/IOCTL ******************************************************************/

/* ioctl
 *  -> *ioctl
 */
#if defined(__NR_ioctl)
#define HAS_NATIVE_ioctl 1
#define HAS_ioctl 1
#endif

/* SYS/MMAN *******************************************************************/

/* mmap
 * mmap_old
 *  -> *mmap
 */
#if (defined(__NR_mmap) \
    || defined(__NR_mmap_old))
#define HAS_NATIVE_mmap 1
#define HAS_mmap 1
#endif

/* mmap2
 *  -> *mmap2
 *  ->  mmap
 */
#if defined(__NR_mmap2)
#define HAS_NATIVE_mmap2 1
#define HAS_mmap2 1
#define HAS_mmap 1
#endif

/* mremap
 *  -> *mremap
 */
#if defined(__NR_mremap)
#define HAS_NATIVE_mremap 1
#define HAS_mremap 1
#endif

/* munmap
 *  -> *munmap
 */
#if defined(__NR_munmap)
#define HAS_NATIVE_munmap 1
#define HAS_munmap 1
#endif

/* SYS/RESOURCE ***************************************************************/

/* ugetrlimit
 * getrlimit
 *  -> *getrlimit
 */
#if (defined(__NR_ugetrlimit) \
    || defined(__NR_getrlimit))
#define HAS_NATIVE_getrlimit 1
#define HAS_getrlimit 1
#endif

/* getrusage
 * getrusage_old
 *  -> *getrusage
 */
#if (defined(__NR_getrusage) \
    || defined(__NR_getrusage_old))
#define HAS_NATIVE_getrusage 1
#define HAS_getrusage 1
#endif

/* prlimit64
 *  -> *prlimit64
 *  ->  getrlimit
 *  ->  setrlimit
 */
#if defined(__NR_prlimit64)
#define HAS_NATIVE_prlimit64 1
#define HAS_prlimit64 1
#define HAS_getrlimit 1
#define HAS_setrlimit 1
#endif

/* setrlimit
 *  -> *setrlimit
 */
#if defined(__NR_setrlimit)
#define HAS_NATIVE_setrlimit 1
#define HAS_setrlimit 1
#endif

/* SELECT *********************************************************************/

/* select
 * select_old
 *  -> *select
 *  ->  pselect
 */
#if (defined(__NR_select) \
    || defined(__NR_select_old))
#define HAS_NATIVE_select 1
#define HAS_select 1
#define HAS_pselect 1
#endif

/* pselect6
 * pselect6_time64
 *  -> *pselect
 *  ->  select
 */
#if (defined(__NR_pselect6) \
    || defined(__NR_pselect6_time64))
#define HAS_NATIVE_pselect 1
#define HAS_pselect 1
#define HAS_select 1
#endif

/* SYS/IPC ********************************************************************/

/* ipc
 *  -> *ipc
 *  ->  semctl
 *  ->  semget
 *  ->  semop
 *  ->  shmat
 *  ->  shmctl
 *  ->  shmdt
 *  ->  shmget
 */
#if defined(__NR_ipc)
#define HAS_NATIVE_ipc 1
#define HAS_ipc 1
#define HAS_semctl 1
#define HAS_semget 1
#define HAS_semop 1
#define HAS_shmat 1
#define HAS_shmctl 1
#define HAS_shmdt 1
#define HAS_shmget 1
#define HAS_msgctl 1
#define HAS_msgget 1
#define HAS_msgsnd 1
#define HAS_msgrcv 1
#endif

/* SYS/SEM ********************************************************************/

/* semctl
 *  -> *semctl
 */
#if defined(__NR_semctl)
#define HAS_NATIVE_semctl 1
#define HAS_semctl 1
#endif

/* semget
 *  -> *semget
 */
#if defined(__NR_semget)
#define HAS_NATIVE_semget 1
#define HAS_semget 1
#endif

/* semop
 *  -> *semop
 */
#if defined(__NR_semop)
#define HAS_NATIVE_semop 1
#define HAS_semop 1
#endif

/* SYS/SHM ********************************************************************/

/* shmat
 *  -> *shmat
 */
#if defined(__NR_shmat)
#define HAS_NATIVE_shmat 1
#define HAS_shmat 1
#endif

/* shmctl
 *  -> *shmctl
 */
#if defined(__NR_shmctl)
#define HAS_NATIVE_shmctl 1
#define HAS_shmctl 1
#endif

/* shmdt
 *  -> *shmdt
 */
#if defined(__NR_shmdt)
#define HAS_NATIVE_shmdt 1
#define HAS_shmdt 1
#endif

/* shmget
 *  -> *shmget
 */
#if defined(__NR_shmget)
#define HAS_NATIVE_shmget 1
#define HAS_shmget 1
#endif

/* SYS/MSG ********************************************************************/

/* msgctl
 *  -> *msgctl
 */
#if defined(__NR_msgctl)
#define HAS_NATIVE_msgctl 1
#define HAS_msgctl 1
#endif

/* msgget
 *  -> *msgget
 */
#if defined(__NR_msgget)
#define HAS_NATIVE_msgget 1
#define HAS_msgget 1
#endif

/* msgrcv
 *  -> *msgrcv
 */
#if defined(__NR_msgrcv)
#define HAS_NATIVE_msgrcv 1
#define HAS_msgrcv 1
#endif

/* msgsnd
 *  -> *msgsnd
 */
#if defined(__NR_msgsnd)
#define HAS_NATIVE_msgsnd 1
#define HAS_msgsnd 1
#endif

/* SOCKET *********************************************************************/

/* accept4
 * accept
 *  -> *accept
 */
#if defined(__NR_accept)
#define HAS_NATIVE_accept 1
#define HAS_accept 1
#endif

/* accept4
 *  -> *accept4
 *  ->  accept
 */
#if defined(__NR_accept4)
#define HAS_NATIVE_accept4 1
#define HAS_accept4 1
#define HAS_accept 1
#endif

/* bind
 *  -> *bind
 */
#if defined(__NR_bind)
#define HAS_NATIVE_bind 1
#define HAS_bind 1
#endif

/* connect
 *  -> *connect
 */
#if defined(__NR_connect)
#define HAS_NATIVE_connect 1
#define HAS_connect 1
#endif

/* getpeername
 *  -> *getpeername
 */
#if defined(__NR_getpeername)
#define HAS_NATIVE_getpeername 1
#define HAS_getpeername 1
#endif

/* getsockname
 *  -> *getsockname
 */
#if defined(__NR_getsockname)
#define HAS_NATIVE_getsockname 1
#define HAS_getsockname 1
#endif

/* listen
 *  -> *listen
 */
#if defined(__NR_listen)
#define HAS_NATIVE_listen 1
#define HAS_listen 1
#endif

/* recv
 *  -> *recv
 */
#if defined(__NR_recv)
#define HAS_NATIVE_recv 1
#define HAS_recv 1
#endif

/* recvfrom
 *  -> *recvfrom
 *  ->  recv
 */
#if defined(__NR_recvfrom)
#define HAS_NATIVE_recvfrom 1
#define HAS_recvfrom 1
#define HAS_recv 1
#endif

/* send
 *  -> *send
 */
#if defined(__NR_send)
#define HAS_NATIVE_send 1
#define HAS_send 1
#endif

/* sendto
 *  -> *sendto
 *  ->  send
 */
#if defined(__NR_sendto)
#define HAS_NATIVE_sendto 1
#define HAS_sendto 1
#define HAS_send 1
#endif

/* setsockopt
 *  -> *setsockopt
 */
#if defined(__NR_setsockopt)
#define HAS_NATIVE_setsockopt 1
#define HAS_setsockopt 1
#endif

/* shutdown
 *  -> *shutdown
 */
#if defined(__NR_shutdown)
#define HAS_NATIVE_shutdown 1
#define HAS_shutdown 1
#endif

/* socket
 *  -> *socket
 */
#if defined(__NR_socket)
#define HAS_NATIVE_socket 1
#define HAS_socket 1
#endif

/* socketcall
 *  -> *socketcall
 *  ->  accept
 *  ->  bind
 *  ->  connect
 *  ->  getpeername
 *  ->  getsockname
 *  ->  listen
 *  ->  recv
 *  ->  recvfrom
 *  ->  send
 *  ->  sendto
 *  ->  setsockopt
 *  ->  shutdown
 *  ->  socket
 */
#if defined(__NR_socketcall)
#define HAS_NATIVE_socketcall 1
#define HAS_socketcall 1
#define HAS_accept 1
#define HAS_bind 1
#define HAS_connect 1
#define HAS_getpeername 1
#define HAS_getsockname 1
#define HAS_listen 1
#define HAS_recv 1
#define HAS_recvfrom 1
#define HAS_send 1
#define HAS_sendto 1
#define HAS_setsockopt 1
#define HAS_shutdown 1
#define HAS_socket 1
#endif

/* SYS/STAT *******************************************************************/

/* fchmod
 *  -> *fchmod
 * +fchdir
 *  ->  fchmodat
 */
#if defined(__NR_fchmod)
#define HAS_NATIVE_fchmod 1
#define HAS_fchmod 1
#if defined(__NR_fchdir)
#define HAS_fchmodat 1
#endif
#endif

/* fchmodat
 *  -> *fchmodat
 *  ->  fchmod
 */
#if defined(__NR_fchmodat)
#define HAS_NATIVE_fchmodat 1
#define HAS_fchmodat 1
#define HAS_fchmod 1
#endif

/* fstat
 * fstat_old
 *  -> *fstat
 */
#if (defined(__NR_fstat) \
    || defined(__NR_fstat_old))
#define HAS_NATIVE_fstat 1
#define HAS_fstat 1
#endif

/* fstatat64
 * fstatat64_old
 * newfstatat
 * fstatat
 *  -> *fstatat
 *  ->  stat
 *  ->  fstat
 *  ->  lstat
 */
#if (defined(__NR_fstatat64) \
    || defined(__NR_newfstatat) \
    || defined(__NR_fstatat))
#define HAS_NATIVE_fstatat 1
#define HAS_fstatat 1
#define HAS_stat 1
#define HAS_fstat 1
#define HAS_lstat 1
#define HAS_faccessat 1
#endif

/* lstat
 * lstat_old
 *  -> *lstat
 */
#if (defined(__NR_lstat) \
    || defined(__NR_lstat_old))
#define HAS_NATIVE_lstat 1
#define HAS_lstat 1
#endif

/* mkdir
 *  -> *mkdir
 * +fchdir
 *  ->  mkdirat
 */
#if defined(__NR_mkdir)
#define HAS_NATIVE_mkdir 1
#define HAS_mkdir 1
#if defined(HAS_fchdir)
#define HAS_mkdirat 1
#endif
#endif

/* mkdirat
 *  -> *mkdirat
 *  ->  mkdir
 */
#if defined(__NR_mkdirat)
#define HAS_NATIVE_mkdirat 1
#define HAS_mkdirat 1
#define HAS_mkdir 1
#endif

/* stat
 * stat_old
 *  -> *stat
 * +fchdir
 *  ->  fstatat
 */
#if (defined(__NR_stat) \
    || defined(__NR_stat_old))
#define HAS_NATIVE_stat 1
#define HAS_stat 1
#if defined(HAS_fchdir)
#define HAS_fstatat 1
#endif
#endif

/* statx
 *  -> *statx
 *  ->  stat
 *  ->  fstat
 *  ->  lstat
 *  ->  fstatat
 */
#if defined(__NR_statx)
#define HAS_NATIVE_statx 1
#define HAS_statx 1
#define HAS_stat 1
#define HAS_fstat 1
#define HAS_lstat 1
#define HAS_fstatat 1
#endif

/* umask
 *  -> *umask
 */
#if defined(__NR_umask)
#define HAS_NATIVE_umask 1
#define HAS_umask 1
#endif

/* SYS/STATFS *****************************************************************/

/* statfs
 *  -> *statfs
 */
#if defined(__NR_statfs)
#define HAS_NATIVE_statfs 1
#define HAS_statfs 1
#endif

/* statfs64
 *  -> *statfs64
 *  ->  statfs
 */
#if defined(__NR_statfs64)
#define HAS_NATIVE_statfs64 1
#define HAS_statfs 1
#define HAS_statfs64 1
#endif

/* fstatfs
 *  -> *fstatfs
 */
#if defined(__NR_fstatfs)
#define HAS_NATIVE_fstatfs 1
#define HAS_fstatfs 1
#endif

/* fstatfs64
 *  -> *fstatfs64
 *  ->  fstatfs
 */
#if defined(__NR_fstatfs64)
#define HAS_NATIVE_fstatfs64 1
#define HAS_fstatfs 1
#define HAS_fstatfs64 1
#endif

/* SYS/TIME *******************************************************************/

/* gettimeofday
 * gettimeofday_old
 *  -> *gettimeofday
 *  ->  time
 */
#if (defined(__NR_gettimeofday) \
    || defined(__NR_gettimeofday_old))
#define HAS_NATIVE_gettimeofday 1
#define HAS_gettimeofday 1
#define HAS_time 1 /* <time.h> */
#endif

/* SYS/TIMES ******************************************************************/

/* times
 *  -> *times
 */
#if defined(__NR_times)
#define HAS_NATIVE_times 1
#define HAS_times 1
#endif

/* SYS/UTSNAME ****************************************************************/

/* uname
 * uname_old
 * uname_oldold
 *  -> *uname
 */
#if (defined(__NR_uname) \
    || defined(__NR_uname_old) \
    || defined(__NR_uname_oldold))
#define HAS_NATIVE_uname 1
#define HAS_uname 1
#endif

/* SYS/WAIT *******************************************************************/

/* wait4
 *  -> *wait4
 *  ->  wait
 *  ->  waitpid
 *  ->  waitid
 */
#if defined(__NR_wait4)
#define HAS_NATIVE_wait4 1
#define HAS_wait4 1
#define HAS_wait 1
#define HAS_waitpid 1
#define HAS_waitid 1
#endif

/* waitid
 *  -> *waitid
 *  ->  wait
 *  ->  waitpid
 */
#if defined(__NR_waitid)
#define HAS_NATIVE_waitid 1
#define HAS_waitid 1
#define HAS_wait 1
#define HAS_waitpid 1
#endif

/* waitpid
 *  -> *waitpid
 *  ->  wait
 *  ->  waitid
 */
#if defined(__NR_waitpid)
#define HAS_NATIVE_waitpid 1
#define HAS_waitpid 1
#define HAS_wait 1
#define HAS_waitid 1
#endif

/* TERMIOS ********************************************************************/

/* TIME ***********************************************************************/

/* clock_gettime32
 * clock_gettime64
 *  -> *clock_gettime
 */
#if (defined(__NR_clock_gettime32) \
    || defined(__NR_clock_gettime64))
#define HAS_NATIVE_clock_gettime 1
#endif

/* nanosleep
 *  -> *nanosleep
 */
#if defined(__NR_nanosleep)
#define HAS_NATIVE_nanosleep 1
#define HAS_nanosleep 1
#endif

/* time
 *  -> *time
 *  ->  gettimeofday
 */
#if defined(__NR_time)
#define HAS_NATIVE_time 1
#define HAS_time 1
#define HAS_gettimeofday 1 /* <sys/time.h> */
#endif

/* UNISTD *********************************************************************/

/* access
 *  -> *access
 */
#if defined(__NR_access)
#define HAS_NATIVE_access 1
#define HAS_access 1
#endif

/* brk
 *  -> *brk
 */
#if defined(__NR_brk)
#define HAS_NATIVE_brk 1
#define HAS_brk 1
#endif

/* chdir
 *  -> *chdir
 */
#if defined(__NR_chdir)
#define HAS_NATIVE_chdir 1
#define HAS_chdir 1
#endif

/* close
 *  -> *close
 */
#if defined(__NR_close)
#define HAS_NATIVE_close 1
#define HAS_close 1
#endif

/* dup
 *  -> *dup
 */
#if defined(__NR_dup)
#define HAS_NATIVE_dup 1
#define HAS_dup 1
#endif

/* dup2
 *  -> *dup2
 */
#if defined(__NR_dup2)
#define HAS_NATIVE_dup2 1
#define HAS_dup2 1
#endif

/* dup3
 *  -> *dup3
 *  ->  dup2
 */
#if defined(__NR_dup3)
#define HAS_NATIVE_dup3
#define HAS_dup3 1
#define HAS_dup2 1
#endif

/* execve
 *  -> *execve
 */
#if defined(__NR_execve)
#define HAS_NATIVE_execve 1
#define HAS_execve 1
#endif

/* exit
 *  -> *exit
 */
#if defined(__NR_exit)
#define HAS_NATIVE_exit 1
#define HAS_exit 1
#endif

/* faccessat
 *  -> *faccessat
 *  ->  access
 */
#if defined(__NR_faccessat) || defined(__NR_faccessat2)
#define HAS_NATIVE_faccessat 1
#define HAS_faccessat 1
#define HAS_access 1
#endif

/* fchdir
 *  -> *fchdir
 */
#if defined(__NR_fchdir)
#define HAS_NATIVE_fchdir 1
#define HAS_fchdir 1
#endif

/* fork
 *  -> *fork
 */
#if defined(__NR_fork)
#define HAS_NATIVE_fork 1
#define HAS_fork 1
#endif

/* fsync
 *  -> *fsync
 */
#if defined(__NR_fsync)
#define HAS_NATIVE_fsync 1
#define HAS_fsync 1
#endif

/* getcwd
 *  -> *getcwd
 */
#if defined(__NR_getcwd)
#define HAS_NATIVE_getcwd 1
#endif
/* XXX: we always have a version of some sort */
#define HAS_getcwd 1

/* getegid32
 * getegid
 *  -> *getegid
 */
#if (defined(__NR_getegid32) \
    || defined(__NR_getegid))
#define HAS_NATIVE_getegid 1
#define HAS_getegid 1
#endif

/* geteuid32
 * geteuid
 *  -> *geteuid
 */
#if (defined(__NR_geteuid32) \
    || defined(__NR_geteuid))
#define HAS_NATIVE_geteuid 1
#define HAS_geteuid 1
#endif

/* getgid32
 * getgid
 *  -> *getgid
 */
#if (defined(__NR_getgid32) \
    || defined(__NR_getgid))
#define HAS_NATIVE_getgid 1
#define HAS_getgid 1
#endif

/* getpagesize
 *  -> *getpagesize
 */
#if defined(__NR_getpagesize)
#define HAS_NATIVE_getpagesize 1
#endif
/* XXX: we almost never have a native version; we can get from the ELF auxv or
 * use a hard-coded constant value for the others */
#define HAS_getpagesize 1

/* getpid
 *  -> *getpid
 */
#if defined(__NR_getpid)
#define HAS_NATIVE_getpid 1
#define HAS_getpid 1
#endif

/* getppid
 *  -> *getppid
 */
#if defined(__NR_getppid)
#define HAS_NATIVE_getppid 1
#define HAS_getppid 1
#endif

/* getsid
 *  -> *getsid
 */
#if defined(__NR_getsid)
#define HAS_NATIVE_getsid 1
#define HAS_getsid 1
#endif

/* getuid32
 * getuid
 *  -> *getuid
 */
#if (defined(__NR_getuid32) \
    || defined(__NR_getuid))
#define HAS_NATIVE_getuid 1
#define HAS_getuid 1
#endif

/* link
 *  -> *link
 *  ->  linkat
 */
#if defined(__NR_link)
#define HAS_NATIVE_link 1
#define HAS_link 1
#define HAS_linkat 1
#endif

/* linkat
 *  -> *linkat
 *  ->  link
 */
#if defined(__NR_linkat)
#define HAS_NATIVE_linkat 1
#define HAS_linkat 1
#define HAS_link 1
#endif

/* lseek
 *  -> *lseek
 */
#if defined(__NR_lseek)
#define HAS_NATIVE_lseek 1
#define HAS_lseek 1
#endif

/* _llseek
 *  -> *_llseek
 *  ->  lseek
 */
#if defined(__NR_llseek)
#define HAS_NATIVE__llseek 1
#define HAS__llseek 1
#define HAS_lseek 1
#endif

/* pipe
 *  -> *pipe
 */
#if defined(__NR_pipe)
#define HAS_NATIVE_pipe 1
#define HAS_pipe 1
#endif

/* pipe2
 *  -> *pipe2
 *  ->  pipe
 */
#if defined(__NR_pipe2)
#define HAS_NATIVE_pipe2 1
#define HAS_pipe2 1
#define HAS_pipe 1
#endif

/* read
 *  -> *read
 */
#if defined(__NR_read)
#define HAS_NATIVE_read 1
#define HAS_read 1
#endif

/* readlink
 *  -> *readlink
 * +fchdir
 *  ->  readlinkat
 */
#if defined(__NR_readlink)
#define HAS_NATIVE_readlink 1
#define HAS_readlink 1
#if defined(HAS_fchdir)
#define HAS_readlinkat 1
#endif
#endif

/* readlinkat
 *  -> *readlinkat
 *  ->  readlink
 */
#if defined(__NR_readlinkat)
#define HAS_NATIVE_readlinkat 1
#define HAS_readlinkat 1
#define HAS_readlink 1
#endif

/* setgid32
 * setgid
 *  -> *setgid
 */
#if (defined(__NR_setgid32) \
    || defined(__NR_setgid))
#define HAS_NATIVE_setgid 1
#define HAS_setgid 1
#endif

/* setregid32
 * setregid
 *  -> *setregid
 *  ->  setegid
 */
#if (defined(__NR_setregid32) \
    || defined(__NR_setregid))
#define HAS_NATIVE_setregid 1
#define HAS_setregid 1
#define HAS_setegid 1
#endif

/* setresgid32
 * setresgid
 *  -> *setresgid
 *  ->  setregid
 *  ->  setegid
 */
#if (defined(__NR_setresgid32) \
    || defined(__NR_setresgid))
#define HAS_NATIVE_setresgid 1
#define HAS_setresgid 1
#define HAS_setregid 1
#define HAS_setegid 1
#endif

/* setreuid32
 * setreuid
 *  -> *setreuid
 *  ->  seteuid
 */
#if (defined(__NR_setreuid32) \
    || defined(__NR_setreuid))
#define HAS_NATIVE_setreuid 1
#define HAS_setreuid 1
#define HAS_seteuid 1
#endif

/* setresuid32
 * setresuid
 *  -> *setresuid
 *  ->  setreuid
 *  ->  seteuid
 */
#if (defined(__NR_setresuid32) \
    || defined(__NR_setresuid))
#define HAS_NATIVE_setresuid 1
#define HAS_setresuid 1
#define HAS_setreuid 1
#define HAS_seteuid 1
#endif

/* setsid
 *  -> *setsid
 */
#if defined(__NR_setsid)
#define HAS_NATIVE_setsid 1
#define HAS_setsid 1
#endif

/* setuid32
 * setuid
 *  -> *setuid
 */
#if (defined(__NR_setuid32) \
    || defined(__NR_setuid))
#define HAS_NATIVE_setuid 1
#define HAS_setuid 1
#endif

/* sync
 *  -> *sync
 *  ->  fsync
 */
#if defined(__NR_sync)
#define HAS_NATIVE_sync 1
#define HAS_sync 1
#define HAS_fsync 1
#endif

/* unlink
 *  -> *unlink
 * +fchdir
 *  ->  unlinkat
 */
#if defined(__NR_unlink)
#define HAS_NATIVE_unlink 1
#define HAS_unlink 1
#if defined(HAS_fchdir)
#define HAS_unlinkat 1
#endif
#endif

/* unlinkat
 *  -> *unlinkat
 *  ->  unlink
 */
#if defined(__NR_unlinkat)
#define HAS_NATIVE_unlinkat 1
#define HAS_unlinkat 1
#define HAS_unlink 1
#endif

/* write
 *  -> *write
 */
#if defined(__NR_write)
#define HAS_NATIVE_write 1
#define HAS_write 1
#endif

/******************************************************************************/

#endif // _LINUX_FEATURES_H
