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

#ifndef _LINUX_MIPS64_STATFS_H
#define _LINUX_MIPS64_STATFS_H _LINUX_MIPS64 _STATFS_H

#undef __NEED_KERNEL_STATFS
#undef __NEED_KERNEL_STATFS64
#undef __NEED_KERNEL_COMPAT_STATFS64

struct __kernel_statfs {
    long f_type;
    long f_bsize;
    long f_frsize;
    long f_blocks;
    long f_bfree;
    long f_files;
    long f_ffree;
    long f_bavail;
    __kernel_fsid_t f_fsid;
    long f_namelen;
    long f_flags;
    long f_spare[5]
};
#define __HAS_KERNEL_STATFS 1

struct __kernel_statfs64 {
    long f_type;
    long f_bsize;
    long f_frsize;
    long f_blocks;
    long f_bfree;
    long f_files;
    long f_ffree;
    long f_bavail;
    __kernel_fsid_t f_fsid;
    long f_namelen;
    long f_flags;
    long f_spare[5];
};
#define __HAS_KERNEL_STATFS64 1

struct __kernel_compat_statfs64 {
    uint32_t f_type;
    uint32_t f_bsize;
    uint32_t f_frsize;
    uint32_t __pad;
    uint64_t f_blocks;
    uint64_t f_bfree;
    uint64_t f_files;
    uint64_t f_ffree;
    uint64_t f_bavail;
    __kernel_fsid_t f_fsid;
    uint32_t f_namelen;
    uint32_t f_flags;
    uint32_t f_spare[5];
};
#define __HAS_KERNEL_COMPAT_STATFS64 1

#endif // _LINUX_MIPS64_STATFS_H
