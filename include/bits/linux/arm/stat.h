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

#ifndef _LINUX_ARM_STAT_H
#define _LINUX_ARM_STAT_H _LINUX_ARM_STAT_H 

#include <bits/linux/types.h>
#include <sys/stat.h>

#define __kernel_old_stat __kernel_old_stat
struct __kernel_old_stat
{
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

#define __kernel_stat __kernel_stat
struct __kernel_stat
{
#if defined(__ARMEB__)
    unsigned short  st_dev;
    unsigned short  __pad1;
#else
    unsigned long   st_dev;
#endif
    unsigned long   st_ino;
    unsigned short  st_mode;
    unsigned short  st_nlink;
    unsigned short  st_uid;
    unsigned short  st_gid;
#if defined(__ARMEB__)
    unsigned short  st_rdev;
    unsigned short  __pad2;
#else
    unsigned long   st_rdev;
#endif
    unsigned long   st_size;
    unsigned long   st_blksize;
    unsigned long   st_blocks;
    unsigned long   st_atim;
    unsigned long   st_atim_nsec;
    unsigned long   st_mtim;
    unsigned long   st_mtim_nsec;
    unsigned long   st_ctim;
    unsigned long   st_ctim_nsec;
    unsigned long   __unused4;
    unsigned long   __unused5;
};

#define __kernel_stat64 __kernel_stat64
struct __kernel_stat64
{
    unsigned long long  st_dev;
    unsigned char       __pad0[4];
    unsigned long       __st_ino_broken;
    unsigned int        st_mode;
    unsigned int        st_nlink;
    unsigned long       st_uid;
    unsigned long       st_gid;
    unsigned long long  st_rdev;
    unsigned char       __pad3[4];
    long long           st_size;
    unsigned long       st_blksize;
    unsigned long long  st_blocks;
    unsigned long       st_atim;
    unsigned long       st_atim_nsec;
    unsigned long       st_mtim;
    unsigned long       st_mtim_nsec;
    unsigned long       st_ctim;
    unsigned long       st_ctim_nsec;
    unsigned long long  st_ino;
};

void __copy_old_stat(struct __kernel_old_stat*, struct stat*);
void __copy_stat(struct __kernel_stat*, struct stat*);
void __copy_stat64(struct __kernel_stat64*, struct stat*);

#endif // _LINUX_ARM_STAT_H
