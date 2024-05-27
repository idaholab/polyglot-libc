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

#ifndef _SYS_STATFS_H
#define _SYS_STATFS_H _SYS_STATFS_H

#include <sys/types.h>

struct statfs {
    unsigned long f_type;       /* Type of filesystem (see below) */
    unsigned long f_bsize;      /* Optimal transfer block size */
    fsblkcnt_t f_blocks;        /* Total data blocks in filesystem */
    fsblkcnt_t f_bfree;         /* Free blocks in filesystem */
    fsblkcnt_t f_bavail;        /* Free blocks available to unprivileged user */
    fsfilcnt_t f_files;         /* Total inodes in filesystem */
    fsfilcnt_t f_ffree;         /* Free inodes in filesystem */
    fsid_t f_fsid;              /* Filesystem ID */
    unsigned long f_namelen;    /* Maximum length of filenames */
    unsigned long f_frsize;     /* Fragment size */
    unsigned long f_flags;      /* Mount flags of filesystem */
};

int statfs(const char*, struct statfs*);
int fstatfs(int, struct statfs*);

#endif // _SYS_STATFS_H
