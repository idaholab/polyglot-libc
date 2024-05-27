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

#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int gethostname(char *name, size_t namelen)
{
    struct utsname uts;
    size_t len;

    if (uname(&uts) == -1)
        return -1;

    len = strlen(uts.nodename) + 1;
    memcpy(name, uts.nodename, len > namelen ? namelen : len);

    if (len > namelen) {
        errno = ENAMETOOLONG;
        return -1;
    }

    return 0;
}

