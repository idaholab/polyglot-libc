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


/* long __syscall() */

.globl          __syscall
.type           __syscall,@function
__syscall:
    mov         %o0, %g1
    mov         %o1, %o0
    mov         %o2, %o1
    mov         %o3, %o2
    mov         %o4, %o3
    mov         %o5, %o4
    ld          [%sp + 92], %o5
    ta          0x10
    bcc         success
      nop
    ba          __syscall_error
      nop
success:
    retl
      nop

