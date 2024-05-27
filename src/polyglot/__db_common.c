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


void __db_find_next_token(char **line, const char *sep, const char *null)
{
    char *p = (char *)-1, *n;

    // sep -> ' \t/'
    // null -> ' \t/'

    // Find the next separator token
    for (const char *s = sep; *s; ++s) {
        n = strchr(*line, *s);
        if (n && (n < p))
            p = n;
    }

    if (p == (char *)-1) {
        *line = NULL;
    } else {
        // Null out the separator and continuous nullable characters
        *(p++) = 0;
        while (*p) {
            if (strchr(null, *p) == NULL)
                break;
            *(p++) = 0;
        }
        *line = p;
    }
}


void __db_strip_whitespace(char **line)
{
    char c, *p = *line;
    size_t len;

    // Initially figure out how long the line is for trimming
    len = strlen(p);

    // Strip whitespace from left/right
    while (1) {
        c = *p;
        if ((c != ' ') && (c != '\t'))
            break;
        *p = 0;
        ++p;
        --len;
    }
    while (1) {
        c = *(p + len - 1);
        if ((c != ' ') && (c != '\t') && (c != '\r') && (c != '\n'))
            break;
        *(p + len - 1) = 0;
        --len;
    }

    *line = p;
}


void __db_strip_comment(char *p)
{
    // Remove a trailing comment
    if ((p = strchr(p, '#'))) {
        *p = 0;
    }
}


