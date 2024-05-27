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

#if !defined(_I386_SETJMP_H)
#define _I386_SETJMP_H 1

#if defined(__ASSEMBLER__)

/* We only define these macros if we are in assembly-land; they're used for
 * storing registers into the jmp_buf structure. */

#define JB_REG  4
#define JB_EBX  (JB_REG * 0)
#define JB_ESI  (JB_REG * 1)
#define JB_EDI  (JB_REG * 2)
#define JB_ESP  (JB_REG * 3)
#define JB_EBP  (JB_REG * 4)
#define JB_PC   (JB_REG * 5)

#else // __ASSEMBLER__

#include <signal.h>

struct __jmp_buf_regs {
    unsigned ebx;
    unsigned esi;
    unsigned edi;
    unsigned esp;
    unsigned ebp;
    unsigned pc;
} __JMP_BUF_PACKED;

#endif // __ASSEMBLER__

#endif // _I386_SETJMP_H
