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

//#include <polyglot/syscall_choice.h>
#include <polyglot/heap.h>
#include <stdlib.h>
#include <stddef.h>


extern char **__environ;
extern int __argc;
extern char **__argv;

extern __attribute__((weak)) void __heap_init() {}
extern __attribute__((weak)) void __heap_cleanup() {}
extern void __check_version();
extern void __platform_init();

extern void (*__debug_init)();

extern void __libc_run_preinit(int, char **, char **);
extern void __libc_run_init(int, char **, char **);
extern void __libc_fini(void);


__attribute__((noreturn))
void __libc_main(int (*main)(int, char**, char**),
                 long argc, char **argv,
                 __attribute__((unused)) void (*rtld_fini)(void),
                 __attribute__((unused)) void *stack_end)
{
    /* XXX: IMPLEMENTATION NOTES (consolidated from previous comments)
     *   - We ignore rtld_fini() here because it seems to cause problems on
     *     older Linux systems (not sure why exactly), but where we don't use
     *     any shared libraries at all, it seems like this probably is okay.
     *   - We removed our heap initialization code (see following) because we
     *     shimmed in dlmalloc instead; I'm still not sure that that's the right
     *     call to do that, but it works and our implementation ended up having
     *     some interesting bugs in corner cases.
     *       __heap_init();
     *       atexit(__heap_cleanup);
     *       __heap_begin = __heap_get_initial();
     *       __heap_end = __heap_begin;
     *   - We used to use our own __exit_funcs_init(), but with PDClib
     *     integration (yes, that was forever ago, thanks), it has been removed
     *     since they handle the exit function bits themselves.
     */

    /* Store our argc/argv globally so we can access them later; also setup the
     * environment pointer so get/setenv() work properly. */
    __argc = argc;
    __argv = argv;

    /* Let our specific platform initialize itself; these have a basic, dumb
     * definition generically, but some targets use them to set up important
     * things to make sure syscalls work. Notably, we do this before handling
     * any of the preinit functions so that syscalls function and the
     * environment in general is set up roughly as expected. */
    __check_version();
    __platform_init();

    // Set things up so our heap sould work (in theory)
    __heap_begin = __heap_get_initial();
    __heap_end = __heap_begin;

    /* Run the preinit functions before we've setup the platform/heap; this
     * lets us handle setting up debug stuff before we use any syscalls */
    __libc_run_preinit(argc, argv, __environ);

    // Set up debugging after preinit, but before further initialization
    if (__debug_init != NULL)
        __debug_init();

    // Register the finalization functions to run on exit
    atexit(__libc_fini);
    // Run the init functions after we've setup the platform/heap
    __libc_run_init(argc, argv, __environ);

    // Nothing fancy, just call the function.
    exit(main(argc, argv, __environ));
    __builtin_unreachable();
}


