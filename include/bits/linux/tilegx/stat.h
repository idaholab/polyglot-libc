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

#ifndef _LINUX_TILEGX_STAT_H
#define _LINUX_TILEGX_STAT_H _LINUX_TILEGX_STAT_H

#include <bits/linux/types.h>
#include <sys/stat.h>

#define __kernel_stat __kernel_stat
struct __kernel_stat {
    unsigned long   st_dev;
    unsigned long   st_ino;
    unsigned int    st_mode;
    unsigned int    st_nlink;
    unsigned int    st_uid;
    unsigned int    st_gid;
    unsigned long   st_rdev;
    unsigned long   __pad1;
    long            st_size;
    int             st_blksize;
    int             __pad2;
    long            st_blocks;
    long            st_atim;
    unsigned long   st_atim_nsec;
    long            st_mtim;
    unsigned long   st_mtim_nsec;
    long            st_ctim;
    unsigned long   st_ctim_nsec;
    unsigned int    __unused4;
    unsigned int    __unused5;
};

void __copy_stat(struct __kernel_stat*, struct stat*);

#endif // _LINUX_TILEGX_STAT_H
