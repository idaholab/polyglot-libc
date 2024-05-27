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

#ifndef _LINUX_MIPS_STAT_H
#define _LINUX_MIPS_STAT_H _LINUX_MIPS_STAT_H

#include <bits/linux/types.h>
#include <sys/stat.h>

#define __kernel_stat64 __kernel_stat64
struct __kernel_stat64 {
    unsigned long       st_dev;
    unsigned long       __unused0[3];
    unsigned long long  st_ino;
    __kernel_mode_t     st_mode;
    unsigned int        st_nlink;
    __kernel_uid_t      st_uid;
    __kernel_gid_t      st_gid;
    unsigned long       st_rdev;
    unsigned long       __unused1[3];
    long long           st_size;
    long                st_atim;
    unsigned long       st_atim_nsec;
    long                st_mtim;
    unsigned long       st_mtim_nsec;
    long                st_ctim;
    unsigned long       st_ctim_nsec;
    unsigned long       st_blksize;
    unsigned long       __unused2;
    long long           st_blocks;
};

#define __kernel_stat __kernel_stat
struct __kernel_stat {
    unsigned int        st_dev;
    long                __unused0[3];
    __kernel_ino_t      st_ino;
    __kernel_mode_t     st_mode;
    unsigned int        st_nlink;
    __kernel_uid_t      st_uid;
    __kernel_gid_t      st_gid;
    unsigned int        st_rdev;
    long                __unused1[2];
    long                st_size;
    long                __unused2;
    long                st_atim;
    long                st_atim_nsec;
    long                st_mtim;
    long                st_mtim_nsec;
    long                st_ctim;
    long                st_ctim_nsec;
    long                st_blksize;
    long                st_blocks;
    long                __unused3[14];
};

/* FIXME: check this? */
#define __kernel_old_stat __kernel_old_stat
struct __kernel_old_stat
{
    unsigned short      st_dev;
    unsigned short      st_ino;
    unsigned short      st_mode;
    unsigned short      st_nlink;
    unsigned short      st_uid;
    unsigned short      st_gid;
    unsigned short      st_rdev;
    unsigned long       st_size;
    unsigned long       st_atim;
    unsigned long       st_mtim;
    unsigned long       st_ctim;
};

void __copy_stat(struct __kernel_stat*, struct stat*);
void __copy_stat64(struct __kernel_stat64*, struct stat*);
void __copy_old_stat(struct __kernel_old_stat*, struct stat*);

#endif // _LINUX_MIPS_STAT_H
