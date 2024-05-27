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

#ifndef _LINUX_X86_64_STAT_H
#define _LINUX_X86_64_STAT_H _LINUX_X86_64_STAT_H

#include <bits/linux/types.h>
#include <sys/stat.h>

#define __kernel_stat __kernel_stat
struct __kernel_stat
{
    __kernel_ulong_t    st_dev;
    __kernel_ulong_t    st_ino;
    __kernel_ulong_t    st_nlink;
    unsigned int        st_mode;
    unsigned int        st_uid;
    unsigned int        st_gid;
    unsigned int        __pad0;
    __kernel_ulong_t    st_rdev;
    __kernel_long_t     st_size;
    __kernel_long_t     st_blksize;
    __kernel_long_t     st_blocks;
    __kernel_ulong_t    st_atim;
    __kernel_ulong_t    st_atim_nsec;
    __kernel_ulong_t    st_mtim;
    __kernel_ulong_t    st_mtim_nsec;
    __kernel_ulong_t    st_ctim;
    __kernel_ulong_t    st_ctim_nsec;
    __kernel_long_t     __unused[3];
};

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
    unsigned int        st_size;
    unsigned int        st_atim;
    unsigned int        st_mtim;
    unsigned int        st_ctim;
};

void __copy_stat(struct __kernel_stat*, struct stat*);
void __copy_old_stat(struct __kernel_old_stat*, struct stat*);

#endif // _LINUX_X86_64_STAT_H
