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
#include <stddef.h>
#include <string.h>


/* this is a generic getenv that returns an index rather than a string, so that
 * we can use it across a variety of circumstances, including rebuilding the
 * environment with putenv() */
int __env_get_idx(struct environ_impl *env, const char *name)
{
    int i, namelen;
    char *end, *var, *val;

    // can't find a variable in an empty environment
    if (env->buffer == NULL)
        return -1;

    // find either a separator or a trailing null
    end = strchrnul(name, '=');
    namelen = end - name;

    // try to find a matching element
    for (i = 0; env->buffer[i]; ++i) {
        var = env->buffer[i];
        val = strchr(var, '=');
        // make sure the keys are the same length, and they match
        if (((val - var) == namelen) && (strncmp(name, var, namelen) == 0)) {
            return i;
        }
    }

    return -1;
}

char *__env_get(struct environ_impl *env, const char *name)
{
    int idx;
    if ((idx = __env_get_idx(env, name)) == -1)
        return NULL;
    return strchr(env->buffer[idx], '=') + 1;
}

char *getenv(const char *name)
{
    return __env_get(&__environ_impl, name);
}

