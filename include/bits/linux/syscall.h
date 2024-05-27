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

#ifndef _LINUX_SYSCALL_H
#define _LINUX_SYSCALL_H _LINUX_SYSCALL_H

/* SYSCALL NUMBERS ************************************************************/

#include <_platform.h>
#if __has_include(__target_os_arch_header(syscall.h))
#include __target_os_arch_header(syscall.h)
#else
#error "No architecture-specific <bits/linux/syscall.h> header available"
#endif

#define __SYSCALL_MAX_ARGS 6

#if !defined(__ASSEMBLER__) && !defined(__target_featuredef)

#include <sys/types.h>
#include <sys/types.h>
#include <poll.h>
#include <signal.h>
#include <polyglot/dirent.h>
#include <stdarg.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sys/times.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/select.h>

/* USEFUL ENOSYS DEFINITIONS **************************************************/

#if 0
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#define __ENOSYS_DEF(_0,n,_2) \
    long BOOST_PP_IF(n, \
        __enosys##n(BOOST_PP_REPEAT(n, __ENOSYS_ARG, nothing)), \
        __enosys0(void)) \
    __attribute__((warning("__enosys" #n " explicitly used")));
#define __ENOSYS_ARG(_0,n,_2) \
    BOOST_PP_COMMA_IF(n) long

// this one is aliased in the code
long __enosys(void);
// this generates a number of __enosysN(long * N) prototypes
BOOST_PP_REPEAT(__SYSCALL_MAX_ARGS, __ENOSYS_DEF, nothing)

// they're all defined, so we can clean up afterwards
#undef __ENOSYS_DEF
#undef __ENOSYS_ARG
#endif

/* SYSCALL FUNCTION PROTOTYPES ************************************************/

#ifdef __NR__llseek
int __sys__llseek(int, off_t, off_t*, unsigned int);
#endif
#ifdef __NR_accept4
int __sys_accept(int, struct sockaddr*, socklen_t*);
#endif
#ifdef __NR_accept4
int __sys_accept4(int, struct sockaddr*, socklen_t*, int);
#endif
#ifdef __NR_access
int __sys_access(const char*, int);
#endif
#ifdef __NR_alarm
unsigned __sys_alarm(unsigned);
#endif
#ifdef __NR_bind
int __sys_bind(int, const struct sockaddr*, socklen_t);
#endif
#ifdef __NR_brk
int __sys_brk(void*);
#endif
#ifdef __NR_chdir
int __sys_chdir(const char*);
#endif
#ifdef __NR_clock_gettime32
int __sys_clock_gettime32(clockid_t, struct timespec*);
#endif
#ifdef __NR_clock_gettime64
int __sys_clock_gettime64(clockid_t, struct timespec*);
#endif
#ifdef __NR_clone
pid_t __sys_clone(unsigned long, void*, int, int*, int*, unsigned long);
#endif
#ifdef __NR_close
int __sys_close(int);
#endif
#ifdef __NR_connect
int __sys_connect(int, const struct sockaddr*, socklen_t);
#endif
#ifdef __NR_dup
int __sys_dup(int);
#endif
#ifdef __NR_dup2
int __sys_dup2(int, int);
#endif
#ifdef __NR_dup3
int __sys_dup3(int, int, int);
#endif
#ifdef __NR_execve
int __sys_execve(const char*, char * const*, char * const*);
#endif
#ifdef __NR_faccessat
int __sys_faccessat(int, const char*, int, int);
#endif
#ifdef __NR_faccessat2
int __sys_faccessat2(int, const char*, int, int);
#endif
#ifdef __NR_fchdir
int __sys_fchdir(int);
#endif
#ifdef __NR_fchmod
int __sys_fchmod(int, mode_t);
#endif
#ifdef __NR_fchmodat
int __sys_fchmodat(int, const char*, mode_t, int);
#endif
#ifdef __NR_fcntl
int __sys_fcntl_v(int, int, va_list);
#endif
#ifdef __NR_fcntl64
int __sys_fcntl64_v(int, int, va_list);
#endif
#ifdef __NR_fork
pid_t __sys_fork();
#endif
#ifdef __NR_fstat
int __sys_fstat(int, struct stat*);
#endif
#ifdef __NR_fstat64
int __sys_fstat64(int, struct stat*);
#endif
#ifdef __NR_fstat_old
int __sys_fstat_old(int, struct stat*);
#endif
#ifdef __NR_fstatat64
int __sys_fstatat64(int, const char*, struct stat*, int);
#endif
#ifdef __NR_fstatfs
int __sys_fstatfs(int, struct statfs*);
#endif
#ifdef __NR_fstatfs64
int __sys_fstatfs64(int, struct statfs*);
#endif
#ifdef __NR_fsync
int __sys_fsync(int);
#endif
#ifdef __NR_getcwd
char *__sys_getcwd(char*, size_t);
#endif
#ifdef __NR_getdents
int __sys_getdents(struct __polyglot_dir*);
#endif
#ifdef __NR_getdents64
int __sys_getdents64(struct __polyglot_dir*);
#endif
#ifdef __NR_getegid
gid_t __sys_getegid(void);
#endif
#ifdef __NR_getegid32
gid_t __sys_getegid32(void);
#endif
#ifdef __NR_geteuid
uid_t __sys_geteuid(void);
#endif
#ifdef __NR_geteuid32
uid_t __sys_geteuid32(void);
#endif
#ifdef __NR_getgid
gid_t __sys_getgid(void);
#endif
#ifdef __NR_getgid32
gid_t __sys_getgid32(void);
#endif
#ifdef __NR_getpagesize
size_t __sys_getpagesize();
#endif
#ifdef __NR_getpeername
int __sys_getpeername(int, struct sockaddr*, socklen_t*);
#endif
#ifdef __NR_getpid
pid_t __sys_getpid(void);
#endif
#ifdef __NR_getpgid
pid_t __sys_getpgid(pid_t);
#endif
#ifdef __NR_getppid
pid_t __sys_getppid(void);
#endif
#ifdef __NR_getpriority
int __sys_getpriority(int, id_t);
#endif
#ifdef __NR_getsid
pid_t __sys_getsid(pid_t);
#endif
#ifdef __NR_getrlimit
int __sys_getrlimit(int, struct rlimit*);
#endif
#ifdef __NR_getrusage
int __sys_getrusage(int, struct rusage*);
#endif
#ifdef __NR_getsockname
int __sys_getsockname(int, struct sockaddr*, socklen_t*);
#endif
#ifdef __NR_gettimeofday
int __sys_gettimeofday(struct timeval*, void*);
#endif
#ifdef __NR_getuid
uid_t __sys_getuid(void);
#endif
#ifdef __NR_getuid32
uid_t __sys_getuid32(void);
#endif
#ifdef __NR_ioctl
int __sys_ioctl_v(int, unsigned long, va_list);
#endif
#ifdef __NR_ipc
long __sys_ipc(long, long, long, long, long);
#endif
#ifdef __NR_kill
int __sys_kill(pid_t, int);
#endif
#ifdef __NR_link
int __sys_link(const char*, const char*);
#endif
#ifdef __NR_linkat
int __sys_linkat(int, const char*, int, const char*, int);
#endif
#ifdef __NR_listen
int __sys_listen(int, int);
#endif
#ifdef __NR_lseek
long __sys_lseek(int, off_t, unsigned int);
#endif
#ifdef __NR_lstat
int __sys_lstat(const char*, struct stat*);
#endif
#ifdef __NR_lstat64
int __sys_lstat64(const char*, struct stat*);
#endif
#ifdef __NR_lstat_old
int __sys_lstat_old(const char*, struct stat*);
#endif
#ifdef __NR_madvise
int __sys_madvise(void*, size_t, int);
#endif
#ifdef __NR_mkdir
int __sys_mkdir(const char*, mode_t);
#endif
#ifdef __NR_mkdirat
int __sys_mkdirat(int, const char*, mode_t);
#endif
#ifdef __NR_mmap
void *__sys_mmap(void*, size_t, int, int, int, off_t);
#endif
#ifdef __NR_mmap2
void *__sys_mmap2(void*, size_t, int, int, int, off_t);
#endif
#ifdef __NR_mmap_old
void *__sys_mmap_old(void*, size_t, int, int, int, off_t);
#endif
#ifdef __NR_mremap
void *__sys_mremap(void*, size_t, size_t, int, void*);
#endif
#ifdef __NR_msgctl
int __sys_msgctl(int, int, struct msqid_ds*);
#endif
#ifdef __NR_msgget
int __sys_msgget(key_t, int);
#endif
#ifdef __NR_msgrcv
int __sys_msgrcv(int, void*, size_t, long int, int);
#endif
#ifdef __NR_msgsnd
int __sys_msgsnd(int, const void*, size_t, int);
#endif
#ifdef __NR_munmap
int __sys_munmap(void*, size_t);
#endif
#ifdef __NR_nanosleep
int __sys_nanosleep(const struct timespec*, struct timespec*);
#endif
#ifdef __NR_newfstatat
int __sys_newfstatat(int, const char*, struct stat*, int);
#endif
#ifdef __NR_open
int __sys_open_v(const char*, int, va_list);
#endif
#ifdef __NR_openat
int __sys_openat_v(int, const char*, int, va_list);
#endif
#ifdef __NR_pipe
int __sys_pipe(int*);
#endif
#ifdef __NR_pipe2
int __sys_pipe2(int*, int);
#endif
#ifdef __NR_poll
int __sys_poll(struct pollfd[], nfds_t, int);
#endif
#ifdef __NR_ppoll
int __sys_ppoll(struct pollfd[], nfds_t, const struct timespec*, const sigset_t*);
#endif
#ifdef __NR_prlimit64
int __sys_prlimit64(pid_t, int, const struct rlimit*, struct rlimit*);
#endif
#ifdef __NR_pselect6
int __sys_pselect6(int, fd_set*, fd_set*, fd_set*, const struct timespec*, const sigset_t*);
#endif
#ifdef __NR_pselect6_time64
int __sys_pselect6_time64(int, fd_set*, fd_set*, fd_set*, const struct timespec*, const sigset_t*);
#endif
#ifdef __NR_readdir
int __sys_readdir(struct __polyglot_dir*);
#endif
#ifdef __NR_read
ssize_t __sys_read(int, void*, size_t);
#endif
#ifdef __NR_readlink
ssize_t __sys_readlink(const char*, char*, size_t);
#endif
#ifdef __NR_readlinkat
ssize_t __sys_readlinkat(int, const char*, char*, size_t);
#endif
#ifdef __NR_recv
ssize_t __sys_recv(int, void*, size_t, int);
#endif
#ifdef __NR_recvfrom
ssize_t __sys_recvfrom(int, void*, size_t, int, struct sockaddr*, socklen_t*);
#endif
#ifdef __NR_rmdir
int __sys_rmdir(const char*);
#endif
#ifdef __NR_rt_sigaction
int __sys_rt_sigaction(int, const struct sigaction*, struct sigaction*);
#endif
#ifdef __NR_rt_sigprocmask
int __sys_rt_sigprocmask(int, const sigset_t*, sigset_t*);
#endif
#ifdef __NR_rt_sigsuspend
int __sys_rt_sigsuspend(const sigset_t*);
#endif
#ifdef __NR_select
int __sys_select(int, fd_set*, fd_set*, fd_set*, struct timeval*);
#endif
#ifdef __NR_select
int __sys_select_old(int, fd_set*, fd_set*, fd_set*, struct timeval*);
#endif
#ifdef __NR_semctl
int __sys_semctl(int, int, int, long);
#endif
#ifdef __NR_semget
int __sys_semget(key_t, int, int);
#endif
#ifdef __NR_semop
int __sys_semop(int, struct sembuf*, size_t);
#endif
#ifdef __NR_send
ssize_t __sys_send(int, const void*, size_t, int);
#endif
#ifdef __NR_sendto
ssize_t __sys_sendto(int, const void*, size_t, int, const struct sockaddr*, socklen_t);
#endif
#ifdef __NR_setgid
int __sys_setgid(gid_t);
#endif
#ifdef __NR_setgid32
int __sys_setgid32(gid_t);
#endif
#ifdef __NR_setregid
int __sys_setregid(gid_t, gid_t);
#endif
#ifdef __NR_setregid32
int __sys_setregid32(gid_t, gid_t);
#endif
#ifdef __NR_setresgid
int __sys_setresgid(gid_t, gid_t, gid_t);
#endif
#ifdef __NR_setresgid32
int __sys_setresgid32(gid_t, gid_t, gid_t);
#endif
#ifdef __NR_setresuid
int __sys_setresuid(uid_t, uid_t, uid_t);
#endif
#ifdef __NR_setresuid32
int __sys_setresuid32(uid_t, uid_t, uid_t);
#endif
#ifdef __NR_setreuid
int __sys_setreuid(uid_t, uid_t);
#endif
#ifdef __NR_setreuid32
int __sys_setreuid32(uid_t, uid_t);
#endif
#ifdef __NR_setrlimit
int __sys_setrlimit(int, const struct rlimit*);
#endif
#ifdef __NR_setsid
pid_t __sys_setsid(void);
#endif
#ifdef __NR_setsockopt
int __sys_setsockopt(int, int, int, const void*, socklen_t);
#endif
#ifdef __NR_setuid
int __sys_setuid(uid_t);
#endif
#ifdef __NR_setuid32
int __sys_setuid32(uid_t);
#endif
#ifdef __NR_shmat
void *__sys_shmat(int, const void*, int);
#endif
#ifdef __NR_shmctl
int __sys_shmctl(int, int, void*);
#endif
#ifdef __NR_shmdt
int __sys_shmdt(const void*);
#endif
#ifdef __NR_shmget
int __sys_shmget(key_t, size_t, int);
#endif
#ifdef __NR_shutdown
int __sys_shutdown(int, int);
#endif
#ifdef __NR_sigaction
int __sys_sigaction(int, const struct sigaction*, struct sigaction*);
#endif
#ifdef __NR_sigprocmask
int __sys_sigprocmask(int, const sigset_t*, sigset_t*);
#endif
#ifdef __NR_sigsuspend
int __sys_sigsuspend(const sigset_t*);
#endif
#ifdef __NR_socket
int __sys_socket(int, int, int);
#endif
#ifdef __NR_socketcall
int __sys_socketcall(int, long**);
#endif
#ifdef __NR_stat
int __sys_stat(const char*, struct stat*);
#endif
#ifdef __NR_stat64
int __sys_stat64(const char*, struct stat*);
#endif
#ifdef __NR_stat_old
int __sys_stat_old(const char*, struct stat*);
#endif
#ifdef __NR_statfs
int __sys_statfs(const char*, struct statfs*);
#endif
#ifdef __NR_statfs64
int __sys_statfs64(const char*, struct statfs*);
#endif
#ifdef __NR_sync
int __sys_sync();
#endif
#ifdef __NR_time
time_t __sys_time(time_t*);
#endif
#ifdef __NR_times
clock_t __sys_times(struct tms*);
#endif
#ifdef __NR_ugetrlimit
int __sys_ugetrlimit(int, struct rlimit*);
#endif
#ifdef __NR_umask
mode_t __sys_umask(mode_t);
#endif
#ifdef __NR_uname
int __sys_uname(struct utsname*);
#endif
#ifdef __NR_uname_old
int __sys_uname_old(struct utsname*);
#endif
#ifdef __NR_uname_oldold
int __sys_uname_oldold(struct utsname*);
#endif
#ifdef __NR_unlink
int __sys_unlink(const char*);
#endif
#ifdef __NR_unlinkat
int __sys_unlinkat(int, const char*, int);
#endif
#ifdef __NR_wait4
pid_t __sys_wait4(pid_t, int*, int, struct rusage*);
#endif
#ifdef __NR_waitid
int __sys_waitid(idtype_t, id_t, siginfo_t*, int);
#endif
#ifdef __NR_waitpid
pid_t __sys_waitpid(pid_t, int*, int);
#endif
#ifdef __NR_write
ssize_t __sys_write(int, const void*, size_t);
#endif

#endif // !__ASSEMBLER__ && !__target_featuredef

#endif // _LINUX_SYSCALL_H
