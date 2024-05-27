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

#include <polyglot/file_at.h>
#include <bits/linux/syscall.h>
#include <bits/linux/features.h>
#include <unistd.h>
#include <fcntl.h>

#ifdef HAS_NATIVE_unlink

int __unlinkat_via_unlink(int fd, const char *path, int flags)
{
    int cur_fd, result;

    if (__file_at_push(&cur_fd, fd) == -1)
        return -1;

    if (flags & AT_REMOVEDIR) {
        result = rmdir(path);
    } else {
        result = __sys_unlink(path);
    }

    if (__file_at_pop(cur_fd) == -1)
        return -1;

    return result;
}

#endif
