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

#include <bits/linux/syscall.h>

#ifdef __NR_fork

/* long __syscall_fork(); */

.globl      __syscall_fork
.type       __syscall_fork,@function
__syscall_fork:
    mov     __NR_fork, %g1
    ta      0x10
    bcc     0f
      nop
    ba      __syscall_error
      nop

0:
    cmp     %o1, 0
    /* if %o1 == 0, we are the parent -> return %o0 */
    be      1f
      nop
    /* we are the child -> return 0 */
    mov     0, %o0

1:
    retl
      nop

#endif
