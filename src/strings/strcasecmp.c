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

#define COMPARE_CHAR(a, b) \
    ( \
        ((a) == (b)) \
        || (((a) >= 'A') && ((a) <= 'Z') && (((a) + ('a' - 'A')) == (b))) \
        || (((a) >= 'a') && ((a) <= 'z') && (((a) - ('a' - 'A')) == (b))) \
    )

/* FIXME: this should do the subtraction based on lower-case chars, since the
 * POSIX spec says that it "shall behave as if the strings had been converted
 * to lowercase and then a byte comparison performed" */

int strcasecmp(const char * s1, const char * s2)
{
    while ((*s1) && COMPARE_CHAR(*s1, *s2)) {
        ++s1;
        ++s2;
    }

    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

