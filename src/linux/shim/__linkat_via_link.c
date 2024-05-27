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

#ifdef HAS_NATIVE_link

#warning "FIXME: __linkat_via_link is not implemented properly!"
// temporary for abort()
#include <stdlib.h>

int __linkat_via_link(int fd1, const char *path1,
                      int fd2, const char *path2, int flags)
{
    // FIXME: this needs to be implemented properly...
    if (flags)
        abort();
    if ((fd1 != AT_FDCWD) || (fd2 != AT_FDCWD))
        abort();

    return __sys_link(path1, path2);
}

#endif
