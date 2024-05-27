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

#include <polyglot/environ.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


int __env_set(struct environ_impl *env, const char *name, const char *value, int overwrite)
{
    char *string;
    size_t total;

    // validate for sanity
    if ((name == NULL) || (value == NULL)) {
        errno = EINVAL;
        return -1;
    }

    // if the name exists in the environment and we don't overwrite, success
    if ((__env_get_idx(env, name) != -1) && !overwrite)
        return 0;

    // figure out how long the total string ought to be, then allocate
    total = strlen(name) + strlen(value) + 2;
    if ((string = malloc(total)) == NULL)
        return -1;
    bzero(string, total);
    // write combination to new string
    snprintf(string, total, "%s=%s", name, value);
    // chain to putenv to do the real heavy lifting
    return __env_put(env, string, 1);
}


int setenv(const char *name, const char *value, int overwrite)
{
    return __env_set(&__environ_impl, name, value, overwrite);
}

