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

#ifdef HAS_NATIVE_mkdir

int __mkdirat_via_mkdir(int fd, const char *path, mode_t mode)
{
    int cur_fd, result = -1;

    if (__file_at_push(&cur_fd, fd) == -1)
        return -1;

    result = mkdir(path, mode);

    if (__file_at_pop(cur_fd) == -1)
        return -1;

    return result;
}

#endif
