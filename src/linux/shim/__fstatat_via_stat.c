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

#include <bits/linux/features.h>
#include <polyglot/file_at.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Based on our analysis of the Linux syscalls, we *should* always have stat()
 * (since 0.10 anyway, so functionally always), and almost assuredly have
 * lstat() too (since 0.12), so we are operating under the assumption that this
 * should always work if we don't have fstatat(). */

#ifdef HAS_NATIVE_stat

int __fstatat_via_stat(int fd, const char *path, struct stat *stbuf, int flags)
{
    int cur_fd, result;

    // make sure we're not in a recursion loop
    if (fd != AT_FDCWD) {
        if (__file_at_push(&cur_fd, fd) == -1)
            return -1;
    }

    if (flags & AT_SYMLINK_NOFOLLOW) {
#ifdef HAS_NATIVE_lstat
        result = lstat(path, stbuf);
#else
        errno = EINVAL;
        result = -1;
#endif
    } else {
        result = stat(path, stbuf);
    }

    if (__file_at_pop(cur_fd) == -1)
        return -1;

    return result;
}

#endif
