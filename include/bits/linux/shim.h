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

#ifndef _LINUX_SHIM_H
#define _LINUX_SHIM_H 1

#include <bits/linux/features.h>

#if defined(HAS_NATIVE_dup3)
int __dup2_via_dup3(int, int);
#endif
#if defined(HAS_NATIVE_fchmod) && defined(HAS_NATIVE_chmod)
int __fchmodat_via_chmod(int, const char*, mode_t, int);
#endif
#if defined(HAS_NATIVE_clone)
pid_t __fork_via_clone();
#endif
#if defined(HAS_NATIVE_sync)
int __fsync_via_sync(int);
#endif
size_t __getpagesize_nosys();
#if defined(HAS_NATIVE_mmap2)
void *__mmap_via_mmap2(void*, size_t, int, int, int, off_t);
#endif
#if defined(HAS_NATIVE_openat)
int __open_via_openat_v(const char*, int, va_list);
#endif
#if defined(HAS_NATIVE_open)
int __openat_via_open_v(int, const char*, int, va_list);
#endif
#if defined(HAS_NATIVE_pipe2)
int __pipe_via_pipe2(int*);
#endif
#if defined(HAS_NATIVE_ppoll)
int __poll_via_ppoll(struct pollfd[], nfds_t, int);
#endif
#if defined(HAS_NATIVE_poll)
int __ppoll_via_poll(struct pollfd[], nfds_t, const struct timespec*, const sigset_t*);
#endif
#if defined(HAS_NATIVE_readlink)
ssize_t __readlinkat_via_readlink(int, const char*, char*, size_t);
#endif
#if defined(HAS_NATIVE_readlinkat)
ssize_t __readlink_via_readlinkat(const char*, char*, size_t);
#endif
#if defined(HAS_NATIVE_unlink)
int __unlinkat_via_unlink(int, const char*, int);
#endif
#if defined(HAS_NATIVE_unlinkat)
int __unlink_via_unlinkat(const char*);
int __rmdir_via_unlinkat(const char*);
#endif
#if defined(HAS_NATIVE_prlimit64)
int __getrlimit_via_prlimit64(int, struct rlimit*);
int __setrlimit_via_prlimit64(int, const struct rlimit*);
#endif
#if defined(HAS_NATIVE__llseek)
off_t __lseek64_via__llseek(int, off_t, unsigned int);
#endif
#if defined(HAS_NATIVE_lseek)
off_t __lseek64_via_lseek(int, off_t, unsigned int);
#endif
#if defined(HAS_NATIVE_socketcall)
int __shutdown_via_socketcall(int, int);
int __socket_via_socketcall(int, int, int);
int __bind_via_socketcall(int, const struct sockaddr*, socklen_t);
int __connect_via_socketcall(int, const struct sockaddr*, socklen_t);
int __getpeername_via_socketcall(int, struct sockaddr*, socklen_t*);
int __getsockname_via_socketcall(int, struct sockaddr*, socklen_t*);
int __listen_via_socketcall(int, int);
int __setsockopt_via_socketcall(int, int, int, const void*, socklen_t);
int __accept_via_socketcall(int, struct sockaddr*, socklen_t*);
int __accept4_via_socketcall(int, struct sockaddr*, socklen_t*, int);
ssize_t __recv_via_socketcall(int, void*, size_t, int);
ssize_t __recvfrom_via_socketcall(int, void*, size_t, int, struct sockaddr*, socklen_t*);
ssize_t __send_via_socketcall(int, const void*, size_t, int);
ssize_t __sendto_via_socketcall(int, const void*, size_t, int, const struct sockaddr*, socklen_t);
#endif
// XXX: see note in accept()
#if defined(HAS_NATIVE_accept4)
int __accept_via_accept4(int, struct sockaddr*, socklen_t*);
#endif
// XXX: see note in accept()
#if defined(HAS_NATIVE_recvfrom)
ssize_t __recv_via_recvfrom(int, void*, size_t, int);
#endif
// XXX: see note in accept()
#if defined(HAS_NATIVE_sendto)
ssize_t __send_via_sendto(int, const void*, size_t, int);
#endif
#if defined(HAS_NATIVE_ipc)
void *__shmat_via_ipc(int, const void*, int);
int __shmctl_via_ipc(int, int, void*);
int __shmdt_via_ipc(const void*);
int __shmget_via_ipc(key_t, size_t, int);
int __semctl_via_ipc(int, int, int, long);
int __semget_via_ipc(key_t, int, int);
int __semop_via_ipc(int, struct sembuf*, size_t);
int __msgctl_via_ipc(int, int, struct msqid_ds*);
int __msgget_via_ipc(key_t, int);
ssize_t __msgrcv_via_ipc(int, void *, size_t, long int, int);
int __msgsnd_via_ipc(int, const void *, size_t, int);
#endif
#if defined(HAS_NATIVE_pselect)
int __select_via_pselect(int, fd_set*, fd_set*, fd_set*, struct timeval*);
#endif
#if defined(HAS_NATIVE_select)
int __pselect_via_select(int, fd_set*, fd_set*, fd_set*, const struct timespec*, const sigset_t*);
#endif
#if defined(HAS_NATIVE_wait4)
pid_t __wait_via_wait4(int*);
pid_t __waitpid_via_wait4(pid_t, int*, int);
#endif
#if defined(HAS_NATIVE_gettimeofday)
time_t __time_via_gettimeofday(time_t*);
#endif
#if defined(HAS_NATIVE_setregid)
int __setegid_via_setregid(gid_t);
#endif
#if defined(HAS_NATIVE_setresgid)
int __setegid_via_setresgid(gid_t);
#endif
#if defined(HAS_NATIVE_setreuid)
int __seteuid_via_setreuid(uid_t);
#endif
#if defined(HAS_NATIVE_setresuid)
int __seteuid_via_setresuid(uid_t);
#endif
#if defined(HAS_NATIVE_mkdirat)
int __mkdir_via_mkdirat(const char*, mode_t);
#endif
#if defined(HAS_NATIVE_mkdir)
int __mkdirat_via_mkdir(int, const char*, mode_t);
#endif
#if defined(HAS_NATIVE_fstatat)
int __stat_via_fstatat(const char*, struct stat*);
int __lstat_via_fstatat(const char*, struct stat*);
#endif
#if defined(HAS_NATIVE_stat)
int __fstatat_via_stat(int, const char*, struct stat*, int);
#endif
#if defined(HAS_NATIVE_linkat)
int __link_via_linkat(const char*, const char*);
#endif
#if defined(HAS_NATIVE_link)
int __linkat_via_link(int, const char*, int, const char*, int);
#endif
#if defined(HAS_NATIVE_faccessat)
int __access_via_faccessat(const char*, int);
#endif
#if defined(HAS_fstatat)
int __faccessat_via_fstatat(int, const char*, int, int);
#endif

#endif // _LINUX_SHIM_H
