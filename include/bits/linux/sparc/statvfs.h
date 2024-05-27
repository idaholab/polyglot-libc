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

#ifndef _LINUX_SPARC_STATVFS_H
#define _LINUX_SPARC_STATVFS_H _LINUX_SPARC_STATVFS_H

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

struct __kernel_statvfs {
    unsigned long f_bsize;
    unsigned long f_frsize;
    unsigned long f_blocks;
    unsigned long f_bfree;
    unsigned long f_bavail;
    unsigned long f_files;
    unsigned long f_ffree;
    unsigned long f_favail;
    unsigned long f_fsid;
    int __f_unused;
    unsigned long f_flag;
    unsigned long f_namemax;
    int __f_spare[6];
};

struct __kernel_statvfs64 {
    unsigned long f_bsize;
    unsigned long f_frsize;
    unsigned long long f_blocks;
    unsigned long long f_bfree;
    unsigned long long f_bavail;
    unsigned long long f_files;
    unsigned long long f_ffree;
    unsigned long long f_favail;
    unsigned long f_fsid;
    int __f_unused;
    unsigned long f_flag;
    unsigned long f_namemax;
    int __f_spare[6];
};

#endif // _LINUX_SPARC_STATVFS_H
