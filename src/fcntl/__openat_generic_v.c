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
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>

#ifdef __NR_open

int __openat_generic_v(int fd, const char *path, int oflag, va_list ap)
{
    int cur_fd, result = -1;

    if (__file_at_push(&cur_fd, fd) == -1)
        goto cleanup;

    result = __sys_open_v(path, oflag, ap);

    if (__file_at_pop(cur_fd) == -1)
        goto cleanup;

    return result;

cleanup:
    if (result != -1) {
        close(result);
    }
    return -1;
}

#endif
