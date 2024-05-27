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
#include <errno.h>

#if (defined(HAS_NATIVE_fchmod) && defined(HAS_NATIVE_chmod))

int __fchmodat_via_chmod(int fd, const char *path, mode_t mode, int flags)
{
    int cur_fd, result;

    /* if we aren't given a path, we operate on the fd directly; this is
     * somewhat non-standard behavior, but Solaris needs it, so we're making
     * "standard" within Polyglot anyway. */
    if (path == NULL) {
        return fchmod(fd, mode);

    /* otherwise we operate on dirfd + path */
    } else {
        /* Linux has no way of handling AT_SYMLINK_NOFOLLOW, because it doesn't
         * have an lchmod() syscall (never has, never will), so we just die */
        if (flags & AT_SYMLINK_NOFOLLOW) {
            errno = EINVAL;
            return -1;
        }

        if (__file_at_push(&cur_fd, fd) == -1)
            return -1;

        result = chmod(path, mode);

        if (__file_at_pop(cur_fd) == -1)
            return -1;

        return result;
    }
}

#endif
