/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/tile/__longjmp.S).

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
#define SPR_EX_CONTEXT_0_1__ICS_SHIFT 2
#define SPR_EX_CONTEXT_0_0 0x2580
#define SPR_EX_CONTEXT_0_1 0x2581
#define RETURN_PL 0

.text

.globl  __longjmp
.type   __longjmp,@function
.align  8
__longjmp:
.no_require_canonical_reg_names
    { ld r30, r0; addi r0, r0, REGSIZE }
    { ld r31, r0; addi r0, r0, REGSIZE }
    { ld r32, r0; addi r0, r0, REGSIZE }
    { ld r33, r0; addi r0, r0, REGSIZE }
    { ld r34, r0; addi r0, r0, REGSIZE }
    { ld r35, r0; addi r0, r0, REGSIZE }
    { ld r36, r0; addi r0, r0, REGSIZE }
    { ld r37, r0; addi r0, r0, REGSIZE }
    { ld r38, r0; addi r0, r0, REGSIZE }
    { ld r39, r0; addi r0, r0, REGSIZE }
    { ld r40, r0; addi r0, r0, REGSIZE }
    { ld r41, r0; addi r0, r0, REGSIZE }
    { ld r42, r0; addi r0, r0, REGSIZE }
    { ld r43, r0; addi r0, r0, REGSIZE }
    { ld r44, r0; addi r0, r0, REGSIZE }
    { ld r45, r0; addi r0, r0, REGSIZE }
    { ld r46, r0; addi r0, r0, REGSIZE }
    { ld r47, r0; addi r0, r0, REGSIZE }
    { ld r48, r0; addi r0, r0, REGSIZE }
    { ld r49, r0; addi r0, r0, REGSIZE }
    { ld r50, r0; addi r0, r0, REGSIZE }
    { ld r51, r0; addi r0, r0, REGSIZE }
    { ld r52, r0; addi r0, r0, REGSIZE }
    { ld r53, r0; addi r0, r0, REGSIZE }
    { ld r54, r0; addi r0, r0, REGSIZE }
    { ld r55, r0; addi r0, r0, REGSIZE }
    {
        ld r2, r0
        movei r3, 1
        cmpeqi r0, r1, 0
    }
    {
        mtspr SPR_INTERRUPT_CRITICAL_SECTION, r3
        shli r2, r2, SPR_EX_CONTEXT_0_1__ICS_SHIFT
    }
    {
        mtspr SPR_EX_CONTEXT_0_0, lr
        ori r2, r2, RETURN_PL
    }
    {
        or r0, r1, r0
        mtspr SPR_EX_CONTEXT_0_1, r2
    }
    iret


