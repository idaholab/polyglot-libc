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

#include <sys/stat.h>

int fstatat(int fd, const char *pathname, struct stat *stbuf, int flag)
{
    /* if we aren't given a path, operate on the fd directly; note that Linux
     * usually does this somewhat differently ("" + AT_EMPTY_PATH), but that
     * neither behavior is POSIX-standard, so we picked one */
    if (pathname == NULL) {
        return fstat(fd, stbuf);
    } else {
        return __fstatat(fd, pathname, stbuf, flag);
    }
}

