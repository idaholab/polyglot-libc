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


.text
.globl          __syscall
.type           __syscall,@function
__syscall:
    /* The o32 calling convention defines a generic syscall (the 0-syscall) that
     * takes all the arguments in the normal registers/stack (o32 puts arguments
     * into $a0-$a3, then on the stack) so you can just turn around and syscall
     * without having to prep the arguments at all. Neat! */
    li          $v0, __NR_syscall
    syscall
    /* The $a3 register is set to 1 on error; in order to not need to compare a
     * register to a register, we use bgtz (branch if greater than zero). */
    move        $a0, $v0
    bgtz        $a3, __syscall_error
      nop
    j           $ra
      nop


