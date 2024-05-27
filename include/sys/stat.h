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

#if !defined(_SYS_STAT_H)
#define _SYS_STAT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <time.h>

/* MACRO DEFINITIONS **********************************************************/

#define st_atime            st_atim.tv_sec
#define st_mtime            st_mtim.tv_sec
#define st_ctime            st_ctim.tv_sec

#define S_IFMT              0xf000
#define S_IFBLK             0x6000
#define S_IFCHR             0x2000
#define S_IFIFO             0x1000
#define S_IFREG             0x8000
#define S_IFDIR             0x4000
#define S_IFLNK             0xa000
#define S_IFSOCK            0xc000

#define S_IRWXU             00700
#define S_IRUSR             00400
#define S_IWUSR             00200
#define S_IXUSR             00100
#define S_IRWXG             00070
#define S_IRGRP             00040
#define S_IWGRP             00020
#define S_IXGRP             00010
#define S_IRWXO             00007
#define S_IROTH             00004
#define S_IWOTH             00002
#define S_IXOTH             00001
#define S_ISUID             04000
#define S_ISGID             02000
#define S_ISVTX             01000

#define S_ISBLK(m)          (((m) & S_IFMT) == S_IFBLK)
#define S_ISCHR(m)          (((m) & S_IFMT) == S_IFCHR)
#define S_ISDIR(m)          (((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m)         (((m) & S_IFMT) == S_IFIFO)
#define S_ISREG(m)          (((m) & S_IFMT) == S_IFREG)
#define S_ISLNK(m)          (((m) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(m)         (((m) & S_IFMT) == S_IFSOCK)

/* TYPE DEFINITIONS ***********************************************************/

/* This is a common stat structure that will be filled out by the different
 * stat() functions in order to have the widest possible fields. (See
 * <polyglot/stat.h> for the kernel structures for specific platforms.) */
#define __STRUCT_STAT_MEMBERS \
    dev_t           st_dev; \
    ino_t           st_ino; \
    mode_t          st_mode; \
    nlink_t         st_nlink; \
    uid_t           st_uid; \
    gid_t           st_gid; \
    dev_t           st_rdev; \
    off_t           st_size; \
    struct timespec st_atim; \
    struct timespec st_mtim; \
    struct timespec st_ctim; \
    struct timespec st_birthtim; \
    blksize_t       st_blksize; \
    blkcnt_t        st_blocks;
struct stat
{
    __STRUCT_STAT_MEMBERS
};
struct stat64
{
    __STRUCT_STAT_MEMBERS
};
#undef __STRUCT_STAT_MEMBERS

/******************************************************************************/

#include <target/stat.h>

/* NON-POSIX FUNCTION PROTOTYPES **********************************************/

int fstat64(int, struct stat64 *restrict);
int lstat64(const char *restrict, struct stat64 *restrict);
int stat64(const char *restrict, struct stat64 *restrict);

/* POSIX FUNCTION PROTOTYPES **************************************************/

int chmod(const char *, mode_t);
int fchmod(int, mode_t);
int fchmodat(int, const char *, mode_t, int);
int fstat(int, struct stat *);
int fstatat(int, const char *restrict, struct stat *restrict, int);
int lstat(const char *restrict, struct stat *restrict);
int mkdir(const char *, mode_t);
int mkdirat(int, const char *, mode_t);
int stat(const char *restrict, struct stat *restrict);
mode_t umask(mode_t);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - int futimens(int, const struct timespec [2]);
 *   - int mkfifo(const char *, mode_t);
 *   - int mkfifoat(int, const char *, mode_t);
 *   - int mknod(const char *, mode_t, dev_t);
 *   - int mknodat(int, const char *, mode_t, dev_t);
 *   - int utimensat(int, const char *, const struct timespec [2], int);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_STAT_H
