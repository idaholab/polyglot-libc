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
    /* We need to shift registers, since the syscall number goes into $v0 and we
     * get all of our arguments in $a0-$a6 (so $a0 into $v0 and $a1-$a6 into the
     * one below each). */
    move        $v0, $a0
    move        $a0, $a1
    move        $a1, $a2
    move        $a2, $a3
    move        $a3, $a4
    move        $a4, $a5
    move        $a5, $a6
    syscall
    /* The $a3 register is set to 1 on error; in order to not need to compare a
     * register to a register, we use bgtz (branch if greater than zero). */
    move        $a0, $v0
    bgtz        $a3, __syscall_error
      nop
    j           $ra
      nop

