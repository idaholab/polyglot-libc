/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/arm/setjmp.S).

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

#include <bits/arm/setjmp.h>

.text

.globl      setjmp
.type       setjmp,%function
setjmp:
    mov     r1, #1
    b       sigsetjmp

.globl      _setjmp
.type       _setjmp,%function
_setjmp:
    mov     r1, #0
    b       sigsetjmp

.globl      sigsetjmp
.type       sigsetjmp,%function
sigsetjmp:
    /* Move the address of our jmp_buf into ip */
    mov     ip, r0

    /* Store sp and lr */
    str     sp, [ip], #4
    str     lr, [ip], #4
    /* Store the other standard registers */
    stmia   ip!, { r4-r11 }

    /* Tail-call our signal-mask-saving function */
    b       __setjmp_sig_save


