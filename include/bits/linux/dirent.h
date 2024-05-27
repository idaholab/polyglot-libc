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

#ifndef _LINUX_DIRENT_H
#define _LINUX_DIRENT_H _LINUX_DIRENT_H 

#define __NEED_DIRENT_TYPES 1
#define __NEED_DIRENT 1
#define __NEED_DIRENT64 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(dirent.h))
#include __target_os_arch_header(dirent.h)
#endif

#include <bits/linux/types.h>
#include <polyglot/dirent.h>

#ifdef __NEED_DIRENT_TYPES
#define __KERNEL_DT_UNKNOWN 0
#define __KERNEL_DT_FIFO    1
#define __KERNEL_DT_CHR     2
#define __KERNEL_DT_DIR     4
#define __KERNEL_DT_BLK     6
#define __KERNEL_DT_REG     8
#define __KERNEL_DT_LNK     10
#define __KERNEL_DT_SOCK    12
#define __KERNEL_DT_WHT     14
#endif

#ifdef __NEED_DIRENT
struct __kernel_dirent {
    long                d_ino;
    __kernel_off_t      d_off;
    unsigned short      d_reclen;
    char                d_name[];
};
#endif

#ifdef __NEED_DIRENT64
struct __kernel_dirent64 {
    unsigned long long  d_ino;
    long long           d_off;
    unsigned short      d_reclen;
    unsigned char       d_type;
    char                d_name[];
};
#endif

#undef __NEED_DIRENT_TYPES
#undef __NEED_DIRENT
#undef __NEED_DIRENT64

#endif // _LINUX_DIRENT_H
