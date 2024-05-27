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

/* __syscall_pipe(int[2]) */

.text
.globl          __syscall_pipe
.type           __syscall_pipe,@function
__syscall_pipe:
    addiu       $sp, $sp, -36
    sw          $a0, 28($sp)
    sw          $ra, 32($sp)
    li          $v0, __NR_pipe
    syscall
    lw          $ra, 32($sp)
    lw          $a0, 28($sp)
    addiu       $sp, $sp, 36

    /* The $a3 register is set to 1 on error; in order to not need to compare a
     * register to a register, we use bgtz (branch if greater than zero). */
    bgtz        $a3, __syscall_error
     nop

    sw          $v0, 0($a0)
    sw          $v1, 4($a0)
    move        $v0, $zero

    j           $ra
     nop


