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

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

extern char **__argv;

#define path_last_element(path) \
    ({ \
        const char *c = (path); \
        const char *p = (const char *)strrchr(path, '/'); \
        (p == NULL ? c : p + 1 ); \
    })

void __err_print(int append_err, const char *fmt, va_list args)
{
    fprintf(stderr, "%s: ", path_last_element(__argv[0]));
    if (fmt != NULL) {
        vfprintf(stderr, fmt, args);
        if (append_err) {
            fprintf(stderr, ": ");
        }
    }
    fprintf(stderr, "%s", strerror(errno));
}

