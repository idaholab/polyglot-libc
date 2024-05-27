/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/tile/setjmp.S).

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED
   Copyright (C) 1995-2018 Free Software Foundation, Inc.
   Contributed to glibc by Chris Metcalf <cmetcalf@tilera.com>, 2011.

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
#define SPR_INTERRUPT_CRITICAL_SECTION 0x2708

.text

.globl  setjmp
.type   setjmp,@function
.align  8
setjmp:
    movei r1, 1
    j sigsetjmp

.globl  _setjmp
.type   _setjmp,@function
.align  8
_setjmp:
    movei r1, 0
    j sigsetjmp


.globl  sigsetjmp
.type   sigsetjmp,@function
.align  8
sigsetjmp:
    move r2, r0
.no_require_canonical_reg_names
    { st r2, r30; addi r2, r2, REGSIZE }
    { st r2, r31; addi r2, r2, REGSIZE }
    { st r2, r32; addi r2, r2, REGSIZE }
    { st r2, r33; addi r2, r2, REGSIZE }
    { st r2, r34; addi r2, r2, REGSIZE }
    { st r2, r35; addi r2, r2, REGSIZE }
    { st r2, r36; addi r2, r2, REGSIZE }
    { st r2, r37; addi r2, r2, REGSIZE }
    { st r2, r38; addi r2, r2, REGSIZE }
    { st r2, r39; addi r2, r2, REGSIZE }
    { st r2, r40; addi r2, r2, REGSIZE }
    { st r2, r41; addi r2, r2, REGSIZE }
    { st r2, r42; addi r2, r2, REGSIZE }
    { st r2, r43; addi r2, r2, REGSIZE }
    { st r2, r44; addi r2, r2, REGSIZE }
    { st r2, r45; addi r2, r2, REGSIZE }
    { st r2, r46; addi r2, r2, REGSIZE }
    { st r2, r47; addi r2, r2, REGSIZE }
    { st r2, r48; addi r2, r2, REGSIZE }
    { st r2, r49; addi r2, r2, REGSIZE }
    { st r2, r50; addi r2, r2, REGSIZE }
    { st r2, r51; addi r2, r2, REGSIZE }
    { st r2, r52; addi r2, r2, REGSIZE }
    { st r2, r53; addi r2, r2, REGSIZE }
    { st r2, r54; addi r2, r2, REGSIZE }
    { st r2, r55; addi r2, r2, REGSIZE }
    mfspr r3, SPR_INTERRUPT_CRITICAL_SECTION
    st r2, r3
    j __setjmp_sig_save


