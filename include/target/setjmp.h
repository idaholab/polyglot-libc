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

#ifndef _TARGET_SETJMP_H
#define _TARGET_SETJMP_H _TARGET_SETJMP_H

#include <_platform.h>

// define header feature set
#define __NEED_JMP_BUF 1

/* all the __jmp_buf structures should be packed and aligned on pointer
 * boundaries; if they're not, things probably explode... */
#define __JMP_BUF_PACKED __attribute__((packed,aligned(sizeof(unsigned long))))

#if __has_include(__target_arch_header(setjmp.h))
#include __target_arch_header(setjmp.h)
#else
#error "No architecture-specific <target/setjmp.h> header available"
#endif

#if !defined(__ASSEMBLER__)
#ifdef __NEED_JMP_BUF

#include <signal.h>

struct __jmp_buf {
    struct __jmp_buf_regs registers;
    sigset_t mask;
    unsigned mask_saved;
} __JMP_BUF_PACKED;

typedef struct __jmp_buf jmp_buf[1];
typedef struct __jmp_buf jmp_buf_t;

#endif // __NEED_JMP_BUF
#endif // !__ASSEMBLER__

// undefine header feature set
#undef __NEED_JMP_BUF

#endif // _TARGET_SETJMP_H
