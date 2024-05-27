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


int __env_unset(struct environ_impl *env, const char *name)
{
    int idx, idx_owned;

    // if the name doesn't exist, we just bail with success
    if ((idx = __env_get_idx(env, name)) == -1)
        return 0;

    // make sure we own the environment, since we're modifying it
    if (__env_ensure_writable(env))
        return -1;
    // find our divider
    idx_owned = env->owned - env->buffer;

    // we always remove one element, putting it here simplifies below
    --env->count;

    if (idx < idx_owned) {
        // shift the unowned barrier
        --env->owned;
        --idx_owned;
        // swap the last unowned record into our spot
        env->buffer[idx] = env->buffer[idx_owned];
        // swap the last owned record to the beginning of its set
        env->buffer[idx_owned] = env->buffer[env->count];

    } else {
        // we own the pointer, so free it
        free(env->buffer[idx]);
        // swap the last owned record into our spot
        env->buffer[idx] = env->buffer[env->count];
    }

    // we've successfully shifted the unoccupied record to the end, adjust
    env->buffer[env->count] = NULL;

    return 0;
}


int unsetenv(const char *name)
{
    return __env_unset(&__environ_impl, name);
}

