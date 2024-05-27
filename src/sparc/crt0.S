/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/sparc/sparc32/start.S).

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

.section    ".text"
.align      4
.global     _start
.type       _start,#function
_start:
    /* Terminate the stack frame, and reserve space for functions to drop
     * their arguments. */
    mov     %g0, %fp
    sub     %sp, 6*4, %sp

    /* Extract the arguments and environment as encoded on the stack. The
     * argument info starts one register window (16 words) past the SP. */
    ld      [%sp+22*4], %o1 /* (arg 2) argc */
    add     %sp, 23*4, %o2  /* (arg 3) argc */

    /* Load the addresses of the user entry points. */
    set     main, %o0       /* (arg 1) main function */

    /* When starting a binary via the dynamic linker, %g1 contains the address
     * of the shared library termination function, which will be registered
     * with atexit(). If we are statically linked, this will be NULL. */
    mov     %g1, %o3        /* (arg 4) rtld_fini */
    mov     %sp, %o4        /* (arg 5) stack end */

    /* Let libc do the rest of the initialization, and call main. */
    call    __libc_main
      nop

    /* Die very horribly if exit returns. */
    unimp

.size       _start, .-_start

/* Define a symbol for the first piece of initialized data. */
.data
.globl      __data_start
__data_start:
    .long   0


