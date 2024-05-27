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

#ifndef _UNISTD_H
#define _UNISTD_H _UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>

// Target-specific definitions
#include <target/unistd.h>

// Non-Posix, but platforms seem to do this across the board
#include <target/seek.h>

// Get sysconf definitions
#include <target/sysconf.h>

/* MACRO DEFINITIONS **********************************************************/

#define _POSIX_VERSION                      200809L
#define _POSIX2_VERSION                     200809L
#define _XOPEN_VERSION                      700

/* CONSTANTS FOR FUNCTIONS ****************************************************/

// This mirrors what's in PDClib in order to not duplicate NULL
#if !defined(_PDCLIB_NULL_DEFINED) && !defined(NULL)
#define _PDCLIB_NULL_DEFINED _PDCLIB_NULL_DEFINED
#define NULL                                ((void*)0)
#endif

/* Constants for access(). */
#define F_OK                                0
#define X_OK                                1
#define W_OK                                2
#define R_OK                                4

/* Constants for seeking (defined in <stdio.h>). */
#include <target/seek.h>

/* Constants for lockf(). */
#define F_ULOCK                             0
#define F_LOCK                              1
#define F_TLOCK                             2
#define F_TEST                              3

/* File numbers for standard I/O. */
#define STDIN_FILENO                        0
#define STDOUT_FILENO                       1
#define STDERR_FILENO                       2

// FIXME: This seems to hold for both glibc/solaris, but verify?
#define _POSIX_VDISABLE                     0

/* Constants for confstr(). */
#define _CS_PATH                              1
#define _CS_POSIX_V7_ILP32_OFF32_CFLAGS       2
#define _CS_POSIX_V7_ILP32_OFF32_LDFLAGS      3
#define _CS_POSIX_V7_ILP32_OFF32_LIBS         4
#define _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS      5
#define _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS     6
#define _CS_POSIX_V7_ILP32_OFFBIG_LIBS        7
#define _CS_POSIX_V7_LP64_OFF64_CFLAGS        8
#define _CS_POSIX_V7_LP64_OFF64_LDFLAGS       9
#define _CS_POSIX_V7_LP64_OFF64_LIBS         10
#define _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS     11
#define _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS    12
#define _CS_POSIX_V7_LPBIG_OFFBIG_LIBS       13
#define _CS_POSIX_V7_THREADS_CFLAGS          14
#define _CS_POSIX_V7_THREADS_LDFLAGS         15
#define _CS_POSIX_V7_WIDTH_RESTRICTED_ENVS   16
#define _CS_V7_ENV                           17
#define _CS_POSIX_V6_ILP32_OFF32_CFLAGS      18
#define _CS_POSIX_V6_ILP32_OFF32_LDFLAGS     19
#define _CS_POSIX_V6_ILP32_OFF32_LIBS        20
#define _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS     21
#define _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS    22
#define _CS_POSIX_V6_ILP32_OFFBIG_LIBS       23
#define _CS_POSIX_V6_LP64_OFF64_CFLAGS       24
#define _CS_POSIX_V6_LP64_OFF64_LDFLAGS      25
#define _CS_POSIX_V6_LP64_OFF64_LIBS         26
#define _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS     27
#define _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS    28
#define _CS_POSIX_V6_LPBIG_OFFBIG_LIBS       29
#define _CS_POSIX_V6_WIDTH_RESTRICTED_ENVS   30
#define _CS_V6_ENV                           31

/* Constants for pathconf(). */
#define _PC_2_SYMLINKS                        1
#define _PC_ALLOC_SIZE_MIN                    2
#define _PC_ASYNC_IO                          3
#define _PC_CHOWN_RESTRICTED                  4
#define _PC_FILESIZEBITS                      5
#define _PC_LINK_MAX                          6
#define _PC_MAX_CANON                         7
#define _PC_MAX_INPUT                         8
#define _PC_NAME_MAX                          9
#define _PC_NO_TRUNC                         10
#define _PC_PATH_MAX                         11
#define _PC_PIPE_BUF                         12
#define _PC_PRIO_IO                          13
#define _PC_REC_INCR_XFER_SIZE               14
#define _PC_REC_MAX_XFER_SIZE                15
#define _PC_REC_MIN_XFER_SIZE                16
#define _PC_REC_XFER_ALIGN                   17
#define _PC_SYMLINK_MAX                      18
#define _PC_SYNC_IO                          19
#define _PC_TIMESTAMP_RESOLUTION             20
#define _PC_VDISABLE                         21

/* TYPE DEFINITIONS ***********************************************************/

typedef __INTPTR_TYPE__ intptr_t;

/* VARIABLE DEFINITIONS *******************************************************/

extern char *optarg;
extern int opterr, optind, optopt;

/* NON-POSIX FUNCTION PROTOTYPES **********************************************/

int brk(void *);
size_t getpagesize();
void *sbrk(size_t);

/* POSIX FUNCTION PROTOTYPES **************************************************/

void _exit(int);
int access(const char *, int);
unsigned alarm(unsigned);
int chdir(const char *);
int close(int);
int dup(int);
int dup2(int, int);
int execve(const char *, char * const*, char * const*);
int fchdir(int);
pid_t fork(void);
int fsync(int);
char *getcwd(char *, size_t);
uid_t geteuid(void);
gid_t getegid(void);
gid_t getgid(void);
int gethostname(char *, size_t);
pid_t getpid(void);
pid_t getpgid(pid_t);
pid_t getppid(void);
pid_t getsid(pid_t);
uid_t getuid(void);
int isatty(int);
off_t lseek(int, off_t, int);
off_t lseek64(int, off_t, int);
int pipe(int*);
ssize_t read(int, void *, size_t);
ssize_t readlink(const char *restrict, char *restrict, size_t);
int rmdir(const char *);
int setegid(gid_t);
int seteuid(uid_t);
int setgid(gid_t);
int setregid(gid_t, gid_t);
int setreuid(uid_t, uid_t);
pid_t setsid(void);
int setuid(uid_t);
unsigned sleep(unsigned);
int sync(void);
long sysconf(int);
int unlink(const char *);
int unlinkat(int, const char *, int);
int usleep(useconds_t);
ssize_t write(int, const void *, size_t);

/* FIXME: these are slated for implementation, we need some of the function
 * definitions now though, so we build them in here */
int chown(const char *, uid_t, gid_t);
int faccessat(int, const char *, int, int);
int fchown(int, uid_t, gid_t);
int fchownat(int, const char *, uid_t, gid_t, int);
int lchown(const char *, uid_t, gid_t);
int link(const char *, const char *);
int linkat(int, const char *, int, const char *, int);
ssize_t readlinkat(int, const char *restrict, char *restrict, size_t);
int symlink(const char *, const char *);
int symlinkat(const char *, int, const char *);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - size_t confstr(int, char *, size_t);
 *   - int execl(const char *, const char *, ...);
 *   - int execle(const char *, const char *, ...);
 *   - int execlp(const char *, const char *, ...);
 *   - int execv(const char *, char *const []);
 *   - int execvp(const char *, char *const []);
 *   - int fexecve(int, char *const [], char *const []);
 *   - long fpathconf(int, int);
 *   - int ftruncate(int, off_t);
 *   - int getgroups(int, gid_t []);
 *   - long gethostid(void);
 *   - char *getlogin(void);
 *   - int getlogin_r(char *, size_t);
 *   - int getopt(int, char * const [], const char *);
 *   - pid_t getpgrp(void);
 *   - int lockf(int, int, off_t);
 *   - int nice(int);
 *   - long pathconf(const char *, int);
 *   - int pause(void);
 *   - ssize_t pread(int, void *, size_t, off_t);
 *   - ssize_t pwrite(int, const void *, size_t, off_t);
 *   - int setpgid(pid_t, pid_t);
 *   - pid_t setpgrp(void);
 *   - void swab(const void *restrict, void *restrict, ssize_t);
 *   - pid_t tcgetpgrp(int);
 *   - int tcsetpgrp(int, pid_t);
 *   - int truncate(const char *, off_t);
 *   - char *ttyname(int);
 *   - int ttyname_r(int, char *, size_t);
 *   - char *crypt(const char *, const char *);
 *   - void encrypt(char [64], int);
 *   - int fdatasync(int);
 */

/******************************************************************************/

char *__getcwd_generic(char*, size_t);

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _UNISTD_H
