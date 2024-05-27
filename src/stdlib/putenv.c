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
#include <string.h>
#include <strings.h>
#include <errno.h>


int __env_ensure_writable(struct environ_impl *env)
{
    char **new;

    // if the env total is zero, either it's read-only, or it's cleared
    if (!env->total) {
        if ((new = malloc(sizeof(char*) * (env->count + 1))) == NULL)
            return -1;
        memcpy(new, env->buffer, sizeof(char*) * (env->count + 1));
        env->buffer = new;
        env->total = env->count;
        env->owned = env->buffer + env->count;
    }

    return 0;
}


int __env_put(struct environ_impl *env, char *string, int owned)
{
    int idx, idx_owned;
    char *p;
    char **newbuf;

    // make sure environment is legit
    if (string == NULL) {
        errno = EINVAL;
        return -1;
    }

    // make sure we own the environment, since we're modifying it
    if (__env_ensure_writable(env))
        return -1;
    // find our divider
    idx_owned = env->owned - env->buffer;

    // if we already have an entry for it, replace it
    if ((idx = __env_get_idx(env, string)) != -1) {
        // if we own the new pointer, swap it into the right place
        if (owned) {
            // we don't own it yet, let's rearrange
            if (idx < idx_owned) {
                p = env->buffer[idx];
                env->buffer[idx] = env->buffer[idx_owned - 1];
                env->buffer[idx_owned - 1] = p;
                --env->owned;
                idx = idx_owned - 1;
            // we do own it, free the pointer
            } else {
                free(env->buffer[idx]);
            }
        // we don't own the new pointer, swap it into the right spot
        } else {
            // we own it, so we need to rearrange to not own it
            if (idx >= idx_owned) {
                p = env->buffer[idx];
                env->buffer[idx] = env->buffer[0];
                env->buffer[0] = p;
                ++env->owned;
                idx = 0;
                // free the pointer we own
                free(p);
            }
        }

    // we don't already have it, we need to rearrange/resize our buffer
    } else {
        // if we don't have any remaining space, reallocate
        if (env->count >= env->total) {
            // we always have one extra null element at the end
            newbuf = realloc(env->buffer, sizeof(char*) * (env->total + 9));
            if (newbuf == NULL)
                return -1;
            // clear out the new space
            bzero(newbuf + env->total, sizeof(char*) * 9);
            // move owned boundary into the new memory region
            env->owned = newbuf + (env->owned - env->buffer);
            // store our new buffer information
            env->buffer = newbuf;
            env->total += 8;
        }
        // if we own this pointer, it just goes on the end, easy
        if (owned) {
            idx = env->count;
        // if we don't, swap the first owned to the end and shift the boundary
        } else {
            idx = idx_owned;
            env->buffer[env->count] = env->buffer[idx_owned];
            ++env->owned;
        }
        // we always add a new element
        ++env->count;
    }

    // the index is correct, go ahead and set the string
    env->buffer[idx] = string;

    return 0;
}


int putenv(char *string)
{
    return __env_put(&__environ_impl, string, 0);
}

