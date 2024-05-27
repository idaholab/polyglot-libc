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

#ifndef _LINUX_MIPS64_STAT_H
#define _LINUX_MIPS64_STAT_H _LINUX_MIPS64_STAT_H

#include <bits/linux/types.h>
#include <sys/stat.h>

#define __kernel_stat __kernel_stat
#define __kernel_stat64 __kernel_stat
struct __kernel_stat {
    unsigned int        st_dev;
    unsigned int        __unused0[3];
    unsigned long       st_ino;
    __kernel_mode_t     st_mode;
    unsigned int        st_nlink;
    __kernel_uid_t      st_uid;
    __kernel_gid_t      st_gid;
    unsigned int        st_rdev;
    unsigned int        __unused1[3];
    long                st_size;
    unsigned int        st_atim;
    unsigned int        st_atim_nsec;
    unsigned int        st_mtim;
    unsigned int        st_mtim_nsec;
    unsigned int        st_ctim;
    unsigned int        st_ctim_nsec;
    unsigned int        st_blksize;
    unsigned int        __unused2;
    unsigned long       st_blocks;
};

void __copy_stat(struct __kernel_stat*, struct stat*);

#endif // _LINUX_MIPS64_STAT_H
