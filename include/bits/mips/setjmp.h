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

#if !defined(_MIPS_SETJMP_H)
#define _MIPS_SETJMP_H 1

#if defined(__ASSEMBLER__)

/* We only define these macros if we are in assembly-land; they're used for
 * storing registers into the jmp_buf structure. */

#define JB_PTR  4
#define JB_LONG 4
#define LA      la
#define ST_ADDR sw
#define ST_VAL  sw
#define LD_ADDR lw
#define LD_VAL  lw

#define JB_PC   0
#define JB_SP   (JB_PC + JB_PTR)
#define JB_FP   (JB_SP + JB_PTR)
#define JB_GP   (JB_FP + JB_PTR)
#define JB_S(n) (JB_GP + JB_PTR + (n) * JB_LONG)

#else // __ASSEMBLER__

struct __jmp_buf_regs {
    void *pc;
    void *sp;
    void *fp;
    void *gp;
    unsigned long s0;
    unsigned long s1;
    unsigned long s2;
    unsigned long s3;
    unsigned long s4;
    unsigned long s5;
    unsigned long s6;
    unsigned long s7;
    /* XXX: We could have floating point stuff here, but we should always be
     * building with soft float support, so it shouldn't be necessary. */
} __JMP_BUF_PACKED;

#endif // !__ASSEMBLER__

#endif // _MIPS_SETJMP_H
