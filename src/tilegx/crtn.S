/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/tile/crtn.S).

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED
   Copyright (C) 1995-2018 Free Software Foundation, Inc.

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


#define REGSIZE 8

.section .init,"ax",@progbits
    addi r29, sp, (2 * REGSIZE)
    {
        addi sp, sp, (2 * REGSIZE)
        ld lr, r29
    }
    jrp lr

.section .fini,"ax",@progbits
    addi r29, sp, (2 * REGSIZE)
    {
        addi sp, sp, (2 * REGSIZE)
        ld lr, r29
    }
    jrp lr
