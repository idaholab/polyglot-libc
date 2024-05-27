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

#if !defined(_ARM_SETJMP_H)
#define _ARM_SETJMP_H 1

#if !defined(__ASSEMBLER__)

#include <signal.h>

struct __jmp_buf_regs {
    unsigned long sp;
    unsigned long lr;
    unsigned long r4;
    unsigned long r5;
    unsigned long r6;
    unsigned long r7;
    unsigned long r8;
    unsigned long r9;
    unsigned long r10;
    unsigned long r11;
    /* XXX: We could include floating point stuff here for VFP/iWMMXt, but
     * we should be building all our code with softmmu support, so we
     * shouldn't need to preserve floating point stuff. */
} __JMP_BUF_PACKED;

#endif // !__ASSEMBLER__

#endif // _ARM_SETJMP_H
