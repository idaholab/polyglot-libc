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

#ifndef _LINUX_ARM_STATVFS_H
#define _LINUX_ARM_STATVFS_H _LINUX_ARM_STATVFS_H 

#define ST_RDONLY       0x0001
#define ST_NOSUID       0x0002
#define ST_NODEV        0x0004
#define ST_NOEXEC       0x0008
#define ST_SYNCHRONOUS  0x0010
#define ST_VALID        0x0020
#define ST_MANDLOCK     0x0040
#define ST_NOATIME      0x0400
#define ST_NODIRATIME   0x0800
#define ST_RELATIME     0x1000

#include <sys/types.h>
#include <bits/linux/types.h>

struct __kernel_statvfs {
    long f_type;
    long f_bsize;
    uint64_t f_blocks;
    uint64_t f_bfree;
    uint64_t f_bavail;
    uint64_t f_files;
    uint64_t f_ffree;
    __kernel_fsid_t f_fsid;
    long f_namelen;
    long f_frsize;
    long f_flags;
    long f_spare[4];
};

#endif // _LINUX_ARM_STATVFS_H
