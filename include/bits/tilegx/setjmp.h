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

#if !defined(_TILEGX_SETJMP_H)
#define _TILEGX_SETJMP_H 1

#if defined(__ASSEMBLER__)

/* We only define these macros if we are in assembly-land; they're used for
 * storing registers into the jmp_buf structure. */

#define JB_REG  8
#define JB_R30  (JB_REG * 0)
#define JB_R31  (JB_REG * 1)
#define JB_R32  (JB_REG * 2)
#define JB_R33  (JB_REG * 3)
#define JB_R34  (JB_REG * 4)
#define JB_R35  (JB_REG * 5)
#define JB_R36  (JB_REG * 6)
#define JB_R37  (JB_REG * 7)
#define JB_R38  (JB_REG * 8)
#define JB_R39  (JB_REG * 9)
#define JB_R40  (JB_REG * 10)
#define JB_R41  (JB_REG * 11)
#define JB_R42  (JB_REG * 12)
#define JB_R43  (JB_REG * 13)
#define JB_R44  (JB_REG * 14)
#define JB_R45  (JB_REG * 15)
#define JB_R46  (JB_REG * 16)
#define JB_R47  (JB_REG * 17)
#define JB_R48  (JB_REG * 18)
#define JB_R49  (JB_REG * 19)
#define JB_R50  (JB_REG * 20)
#define JB_R51  (JB_REG * 21)
#define JB_FP   (JB_REG * 22)
#define JB_TP   (JB_REG * 23)
#define JB_SP   (JB_REG * 24)
#define JB_PC   (JB_REG * 25)
#define JB_ICS  (JB_REG * 26)

#else // __ASSEMBLER__

#include <signal.h>

struct __jmp_buf_regs {
    unsigned long r30;
    unsigned long r31;
    unsigned long r32;
    unsigned long r33;
    unsigned long r34;
    unsigned long r35;
    unsigned long r36;
    unsigned long r37;
    unsigned long r38;
    unsigned long r39;
    unsigned long r40;
    unsigned long r41;
    unsigned long r42;
    unsigned long r43;
    unsigned long r44;
    unsigned long r45;
    unsigned long r46;
    unsigned long r47;
    unsigned long r48;
    unsigned long r49;
    unsigned long r50;
    unsigned long r51;
    unsigned long fp;
    unsigned long tp;
    unsigned long sp;
    unsigned long pc;
    unsigned long ics;
} __JMP_BUF_PACKED;

#endif // __ASSEMBLER__

#endif // _TILEGX_SETJMP_H
