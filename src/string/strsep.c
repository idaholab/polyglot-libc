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

#include <string.h>

char *strsep(char **stringp, const char *delim)
{
    char *origp, *p;
    origp = p = *stringp;

    if (origp == NULL)
        return NULL;

    for (; *p; ++p) {
        for (const char *d = delim; *d; ++d) {
            if (*p == *d) {
                *p = 0;
                *stringp = p + 1;
                return origp;
            }
        }
    }

    *stringp = NULL;
    return origp;
}

