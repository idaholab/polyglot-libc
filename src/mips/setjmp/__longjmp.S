/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/mips/__longjmp.c).

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

.set nomips16

#include <bits/mips/setjmp.h>

.text

.globl      __longjmp
.type       __longjmp,@function
__longjmp:
    # If our return value is zero, we make it 1
    bnez    $a1, load_regs
     nop
    li      $a1, 1

load_regs:
    # Restore registers
    LD_ADDR $gp,    JB_GP($a0)
    LD_VAL  $s0,  JB_S(0)($a0)
    LD_VAL  $s0,  JB_S(1)($a0)
    LD_VAL  $s0,  JB_S(2)($a0)
    LD_VAL  $s0,  JB_S(3)($a0)
    LD_VAL  $s0,  JB_S(4)($a0)
    LD_VAL  $s0,  JB_S(5)($a0)
    LD_VAL  $s0,  JB_S(6)($a0)
    LD_VAL  $s0,  JB_S(7)($a0)
    LD_ADDR $t0,    JB_PC($a0)
    LD_ADDR $sp,    JB_SP($a0)
    LD_ADDR $fp,    JB_FP($a0)

    # Load our return value
    move    $v0, $a1
    # Jump to our PC value
    jr      $t0
     nop


