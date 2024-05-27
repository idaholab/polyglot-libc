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


// These are specific to us, so they are actually defined here
void **__auxv;

// These are generically available, so they're defined elsewhere
extern int __argc;
extern char **__argv;


void __platform_init(void)
{
    int envc;

    // Save our starting environment
    __start_environ = &__argv[__argc + 1];

#if (__target_binfmt_elf == 1)
    /* Locate the ELF auxiliary vector structure; this isn't used everywhere,
     * but shows up a number of places with platform-specific stuff. */
    __auxv = (void**)__start_environ;
    while (*__auxv)
        ++__auxv;
    ++__auxv;
    /* We can figure out how many environment variables there are without
     * counting, since we already walked it */
    envc = __auxv - (void**)__start_environ - 1;
#else
    // We need to count environment variables...
    for (envc = 0; __start_environ[envc]; ++envc);
#endif

    // Instantiate starting environment structure
    __environ_impl = (struct environ_impl){
        .buffer = __start_environ,
        .count = envc,
        .total = 0,
        .owned = NULL,
    };
}

__attribute__((destructor))
void __environ_free(void)
{
    clearenv();
}

