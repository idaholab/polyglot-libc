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

#ifndef _LINUX_SPARC_STAT_H
#define _LINUX_SPARC_STAT_H _LINUX_SPARC_STAT_H

#include <bits/linux/types.h>
#include <sys/stat.h>

#define __kernel_stat __kernel_stat
struct __kernel_stat {
    unsigned short  st_dev;
    unsigned long   st_ino;
    unsigned short  st_mode;
    short           st_nlink;
    unsigned short  st_uid;
    unsigned short  st_gid;
    unsigned short  st_rdev;
    long            st_size;
    long            st_atim;
    unsigned long   st_atim_nsec;
    long            st_mtim;
    unsigned long   st_mtim_nsec;
    long            st_ctim;
    unsigned long   st_ctim_nsec;
    long            st_blksize;
    long            st_blocks;
    unsigned long   __unused4[2];
};

#define __kernel_stat64 __kernel_stat64
struct __kernel_stat64 {
    unsigned long long  st_dev;
    unsigned long long  st_ino;
    unsigned int        st_mode;
    unsigned int        st_nlink;
    unsigned int        st_uid;
    unsigned int        st_gid;
    unsigned long long  st_rdev;
    unsigned char       __pad3[8];
    long long           st_size;
    unsigned int        st_blksize;
    unsigned char       __pad4[8];
    unsigned int        st_blocks;
    unsigned int        st_atim;
    unsigned int        st_atim_nsec;
    unsigned int        st_mtim;
    unsigned int        st_mtim_nsec;
    unsigned int        st_ctim;
    unsigned int        st_ctim_nsec;
    unsigned int        __unused4;
    unsigned int        __unused5;
};

#define __kernel_old_stat __kernel_old_stat
struct __kernel_old_stat {
    unsigned short  st_dev;
    unsigned short  st_ino;
    unsigned short  st_mode;
    unsigned short  st_nlink;
    unsigned short  st_uid;
    unsigned short  st_gid;
    unsigned short  st_rdev;
    unsigned long   st_size;
    unsigned long   st_atim;
    unsigned long   st_mtim;
    unsigned long   st_ctim;
};

void __copy_stat(struct __kernel_stat*, struct stat*);
void __copy_stat64(struct __kernel_stat64*, struct stat*);
void __copy_old_stat(struct __kernel_old_stat*, struct stat*);

#endif // _LINUX_SPARC_STAT_H
