/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/x86_64/__longjmp.S).

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

.intel_syntax noprefix

#include <bits/x86_64/setjmp.h>

.text

.globl      __longjmp
.type       __longjmp,@function
__longjmp:
    mov     rax, rsi                    # Load the return value
    cmp     rax, 0                      # If the return value is 0, make it 1
    jne     copy_regs
    mov     rax, 1

copy_regs:
    mov     r8, [rdi+JB_RSP]            # Load RSP->R8
    mov     r9, [rdi+JB_RBP]            # Load RBP->R9
    mov     rdx, [rdi+JB_PC]            # Load PC->RDX

    mov     rbx, [rdi+JB_RBX]           # Restore RBX
    mov     r12, [rdi+JB_R12]           # Restore R12
    mov     r13, [rdi+JB_R13]           # Restore R13
    mov     r14, [rdi+JB_R14]           # Restore R14
    mov     r15, [rdi+JB_R15]           # Restore R15

    mov     rsp, r8                     # Restore RSP
    mov     rbp, r9                     # Restore RBP
    jmp     rdx                         # Jump to our return point

