/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/mips/setjmp{.S,_aux.c}).

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

#include <bits/mips64/setjmp.h>

.text

.globl      setjmp
.type       setjmp,@function
setjmp:
    li      $a1, 1
    LA      $t0, sigsetjmp
    j       $t0
     nop

.globl      _setjmp
.type       _setjmp,@function
_setjmp:
    li      $a1, 0
    LA      $t0, sigsetjmp
    j       $t0
     nop

.globl      sigsetjmp
.type       sigsetjmp,@function
sigsetjmp:
    # Save our registers into the jmp_buf structure
    ST_ADDR $ra,  JB_PC  ($a0)
    ST_ADDR $sp,  JB_SP  ($a0)
    ST_ADDR $fp,  JB_FP  ($a0)
    ST_ADDR $gp,  JB_GP  ($a0)
    ST_VAL  $s0,  JB_S(0)($a0)
    ST_VAL  $s1,  JB_S(1)($a0)
    ST_VAL  $s2,  JB_S(2)($a0)
    ST_VAL  $s3,  JB_S(3)($a0)
    ST_VAL  $s4,  JB_S(4)($a0)
    ST_VAL  $s5,  JB_S(5)($a0)
    ST_VAL  $s6,  JB_S(6)($a0)
    ST_VAL  $s7,  JB_S(7)($a0)

    # Tail-call sigprocmask
    LA      $t0, __setjmp_sig_save
    j       $t0
     nop


