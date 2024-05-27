/* Startup support for ELF initializers/finalizers in the main executable.

   This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (csu/libc-start.S).

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED
   Copyright (C) 1995-2024 Free Software Foundation, Inc.

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

/* CHANGES: This file has been reworked from upstream to remove extraneous bits
        that are either not supported or extraneous due to the limited scope of
        Polyglot vs. glibc. In general, it's also been modified to fit within
        the Polyglot C Library's infrastructure. */

#include <stddef.h>

#if __target_binfmt_elf

/* These magic symbols are provided by the linker. */
extern void _init (void);
extern void _fini (void);
extern void (*__preinit_array_start[])(int, char **, char **);
extern void (*__preinit_array_end  [])(int, char **, char **);
extern void (*__init_array_start   [])(int, char **, char **);
extern void (*__init_array_end     [])(int, char **, char **);
extern void (*__fini_array_start   [])(void);
extern void (*__fini_array_end     [])(void);

void __libc_run_preinit(int argc, char **argv, char **envp)
{
    const size_t preinit_size = __preinit_array_end - __preinit_array_start;
    for (size_t i = 0; i < preinit_size; i++) {
        (*__preinit_array_start[i])(argc, argv, envp);
    }
}

void __libc_run_init(int argc, char **argv, char **envp)
{
    _init();

    const size_t size = __init_array_end - __init_array_start;
    for (size_t i = 0; i < size; i++) {
        (*__init_array_start [i]) (argc, argv, envp);
    }
}

void __libc_init(int argc, char **argv, char **envp)
{
    __libc_run_preinit(argc, argv, envp);
    __libc_run_init(argc, argv, envp);
}

void __libc_fini(void)
{
    size_t i = __fini_array_end - __fini_array_start;
    while (i-- > 0) {
        (*__fini_array_start[i])();
    }

    _fini();
}

#else

void __libc_init(int argc, char **argv, char **envp)
{}

void __libc_run_preinit(int argc, char **argv, char **envp)
{}

void __libc_run_init(int argc, char **argv, char **envp)
{}

void __libc_fini(void)
{}

#endif // __target_binfmt_elf

