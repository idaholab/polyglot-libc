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


/* long __syscall(); */

.text
.global __syscall
.type   __syscall,@function
.align  8
__syscall:
    move r10, r0        /* get syscall into r10 */
    move r0, r1         /* shift registers */
    move r1, r2         /* ... */
    move r2, r3         /* ... */
    move r3, r4         /* ... */
    move r4, r5         /* ... */
    move r5, r6         /* ... */
    move r6, r7         /* ... */
    swint1              /* do syscall */
    bnez r1, 0f         /* branch on fail */
    jrp lr              /* return on success */
0:
    sub r0, zero, r0    /* negate errno */
    j __syscall_error   /* tail-call handler */

