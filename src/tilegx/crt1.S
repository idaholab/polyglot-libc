/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/tile/start.S).

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED
   Copyright (C) 1995-2018 Free Software Foundation, Inc.
   Contributed to glibc by Chris Metcalf <cmetcalf@tilera.com>, 2011.

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

/* (pulled from glibc @ 7a6f74787132aca8e3809cae8d9e7bc7bfd55ce1)
/* CHANGES: This file has been reworked from upstream to remove extraneous bits
        that are either not supported or extraneous due to the limited scope of
        Polyglot vs. glibc. In general, it's also been modified to fit within
        the Polyglot C Library's infrastructure. */

/* On entry r0 points to the shared library termination function, or 0 if there
 * isn't one; we generally ignore this because we are static. */

#define INFO_OP_CANNOT_BACKTRACE 2
#define REGSIZE 8

.text
.global _start
.type   _start,@function
.align  8
_start:
    ld r1, sp                       /* (arg) argc */
    move r52, sp                    /* save incoming sp */
    addi r12, sp, -(2 * REGSIZE)    /* allocate stack frame callee space */
    andi sp, r12, -8                /* align sp */
    addi r12, sp, REGSIZE           /* __libc_main frame pointer */
    st sp, zero                     /* zero out callee space for ret addr */
    st r12, zero                    /* zero out __libc_main frame pointer */
    move lr, zero                   /* zero out lr to terminate backtrace */
    addi r2, r52, REGSIZE           /* (arg) argv */
    move r3, r0                     /* (arg) rtld_fini */
    addi r6, sp, (2 * REGSIZE)      /* (arg) stack end */
    moveli r0, hw3(main)            /* (arg) main */
    shl16insli r0, r0, hw2(main)    /* ... */
    shl16insli r0, r0, hw1(main)    /* ... */
    shl16insli r0, r0, hw0(main)    /* ... */
    j __libc_main                   /* call __libc_main */
    info INFO_OP_CANNOT_BACKTRACE   /* mark end of backtrace */

.data
.global __data_start
.align 8
__data_start:
    .long 0
    .weak data_start
    data_start = __data_start

