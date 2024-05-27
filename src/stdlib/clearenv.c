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


int __env_clear(struct environ_impl *env)
{
    // if we own our environment, free things we own
    if ((env->buffer != __start_environ) && env->buffer) {
        // walk through stuff from the owned pointer onward
        if (env->owned) {
            for (char **v = env->owned; *v; ++v)
                free(*v);
        }
        // now we can free the overall buffer
        free(env->buffer);
    }
    // make sure things are properly cleaned up now
    *env = (struct environ_impl){
        .buffer = NULL,
        .count = 0,
        .total = 0,
        .owned = NULL,
    };
}

int clearenv(void)
{
    return __env_clear(&__environ_impl);
}

