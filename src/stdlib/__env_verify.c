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
#include <stdio.h>


void __env_dump(struct environ_impl *env)
{
    unsigned i;
    int idx_owned;

    printf("env[%p]\n", env);
    printf("  buffer = %p\n", env->buffer);
    printf("  count  = %u\n", env->count);
    printf("  total  = %u\n", env->total);
    printf("  owned  = %p\n", env->owned);

    if (env->buffer != NULL) {
        idx_owned = env->owned - env->buffer;
        printf("  entries:\n");
        printf("  -- [unowned] --\n");
        for (i = 0; i < env->total + 1; ++i) {
            if (i == env->count)
                printf("  -- [unset] --\n");
            if (i == idx_owned)
                printf("  -- [owned] --\n");
            if (env->buffer[i] == NULL) {
                printf("  [%u] -> NULL\n", i);
            } else {
                printf("  [%u] -> %p '%.*s'\n", i, env->buffer[i], strchrnul(env->buffer[i], '=') - env->buffer[i], env->buffer[i]);
            }
        }
    }
}


enum ENV_VERIFY_RESULT
{
    ENV_VALID = 0,
    ENV_INVALID,
    ENV_INVALID_BOUNDS,
    ENV_INVALID_POINTERS,
    ENV_INVALID_ENTRY,
};


int __env_verify(struct environ_impl *env)
{
    unsigned i;
    int r = ENV_VALID;

    // no pointer... what?
    if (env == NULL) {
        fprintf(stderr, "__env_verify: invalid pointer provided\n");
        return ENV_INVALID;
    }

    // if the buffer is empty, there's not a lot we can do
    if (env->buffer == NULL) {
        // these should both be zeroed out, ensure that's the case
        if ((env->count != 0) || (env->total != 0)) {
            fprintf(stderr, "__env_verify: invalid bounds, count/total should be zero for NULL buffer (count=%u, total=%u)\n", env->count, env->total);
            r = ENV_INVALID_BOUNDS;
            goto invalid;
        }
        goto valid;
    }

    // if we own the buffer, check validity of bounds/pointers
    if (env->total > 0) {
        if (env->count > env->total) {
            fprintf(stderr, "__env_verify: invalid bounds, count is greater than total (count=%u, total=%u)\n", env->count, env->total);
            r = ENV_INVALID_BOUNDS;
            goto invalid;
        }
        if ((env->owned - env->buffer) > env->count) {
            fprintf(stderr, "__env_verify: invalid pointer, owned is past count (owned=%u, count=%u, total=%u)\n", env->owned - env->buffer, env->count, env->total);
            r = ENV_INVALID_POINTERS;
            goto invalid;
        }

    // otherwise make sure things are correct for an unowned buffer
    } else {
        if (env->owned != NULL) {
            fprintf(stderr, "__env_verify: invalid pointer, owned is set for unowned buffer\n");
            r = ENV_INVALID_POINTERS;
            goto invalid;
        }
    }

    // make sure everything within count is set, and everything outside is null
    for (i = 0; i < env->count; ++i) {
        if (env->buffer[i] == NULL) {
            fprintf(stderr, "__env_verify: invalid entry, null pointer inside count\n");
            r = ENV_INVALID_ENTRY;
            goto invalid;
        }
    }
    for (i = env->count; i < env->total; ++i) {
        if (env->buffer[i] != NULL) {
            fprintf(stderr, "__env_verify: invalid entry, non-null pointer outside count\n");
            r = ENV_INVALID_ENTRY;
            goto invalid;
        }
    }

    goto valid;

invalid:
    __env_dump(env);
valid:
    return r;
}

