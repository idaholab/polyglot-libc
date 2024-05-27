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

#include <bits/linux/stat.h>
#include <sys/stat.h>
#include <strings.h>

#ifdef __kernel_stat
void __copy_stat(struct __kernel_stat *k_stbuf, struct stat *stbuf)
{
    bzero(stbuf, sizeof(struct stat));
    stbuf->st_dev           = k_stbuf->st_dev;
    stbuf->st_ino           = k_stbuf->st_ino;
    stbuf->st_mode          = k_stbuf->st_mode;
    stbuf->st_nlink         = k_stbuf->st_nlink;
    stbuf->st_uid           = k_stbuf->st_uid;
    stbuf->st_gid           = k_stbuf->st_gid;
    stbuf->st_rdev          = k_stbuf->st_rdev;
    stbuf->st_size          = k_stbuf->st_size;
    stbuf->st_atim.tv_sec   = k_stbuf->st_atim;
    stbuf->st_atim.tv_nsec  = k_stbuf->st_atim_nsec;
    stbuf->st_mtim.tv_sec   = k_stbuf->st_mtim;
    stbuf->st_mtim.tv_nsec  = k_stbuf->st_mtim_nsec;
    stbuf->st_ctim.tv_sec   = k_stbuf->st_ctim;
    stbuf->st_ctim.tv_nsec  = k_stbuf->st_ctim_nsec;
    stbuf->st_blksize       = k_stbuf->st_blksize;
    stbuf->st_blocks        = k_stbuf->st_blocks;
}
#endif

#ifdef __kernel_stat64
void __copy_stat64(struct __kernel_stat64 *k_stbuf, struct stat *stbuf)
{
    bzero(stbuf, sizeof(struct stat));
    stbuf->st_dev           = k_stbuf->st_dev;
    stbuf->st_ino           = k_stbuf->st_ino;
    stbuf->st_mode          = k_stbuf->st_mode;
    stbuf->st_nlink         = k_stbuf->st_nlink;
    stbuf->st_uid           = k_stbuf->st_uid;
    stbuf->st_gid           = k_stbuf->st_gid;
    stbuf->st_rdev          = k_stbuf->st_rdev;
    stbuf->st_size          = k_stbuf->st_size;
    stbuf->st_atim.tv_sec   = k_stbuf->st_atim;
    stbuf->st_atim.tv_nsec  = k_stbuf->st_atim_nsec;
    stbuf->st_mtim.tv_sec   = k_stbuf->st_mtim;
    stbuf->st_mtim.tv_nsec  = k_stbuf->st_mtim_nsec;
    stbuf->st_ctim.tv_sec   = k_stbuf->st_ctim;
    stbuf->st_ctim.tv_nsec  = k_stbuf->st_ctim_nsec;
    stbuf->st_blksize       = k_stbuf->st_blksize;
    stbuf->st_blocks        = k_stbuf->st_blocks;
}
#endif

#ifdef __kernel_old_stat
void __copy_old_stat(struct __kernel_old_stat *k_stbuf, struct stat *stbuf)
{
    bzero(stbuf, sizeof(struct stat));
    stbuf->st_dev           = k_stbuf->st_dev;
    stbuf->st_ino           = k_stbuf->st_ino;
    stbuf->st_mode          = k_stbuf->st_mode;
    stbuf->st_nlink         = k_stbuf->st_nlink;
    stbuf->st_uid           = k_stbuf->st_uid;
    stbuf->st_gid           = k_stbuf->st_gid;
    stbuf->st_rdev          = k_stbuf->st_rdev;
    stbuf->st_size          = k_stbuf->st_size;
    stbuf->st_atim.tv_sec   = k_stbuf->st_atim;
    stbuf->st_atim.tv_nsec  = 0 /* not present */;
    stbuf->st_mtim.tv_sec   = k_stbuf->st_mtim;
    stbuf->st_mtim.tv_nsec  = 0 /* not present */;
    stbuf->st_ctim.tv_sec   = k_stbuf->st_ctim;
    stbuf->st_ctim.tv_nsec  = 0 /* not present */;
    stbuf->st_blksize       = 0 /* not present */;
    stbuf->st_blocks        = 0 /* not present */;
}
#endif

