/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/x86_64/setjmp.S).

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

.globl      setjmp
.type       setjmp,@function
setjmp:
    mov     rsi, 1
    jmp     sigsetjmp


.globl      _setjmp
.type       _setjmp,@function
_setjmp:
    mov     rsi, 0
    jmp     sigsetjmp


.globl      sigsetjmp
.type       sigsetjmp,@function
sigsetjmp:
    mov     qword ptr [rdi+JB_RBX], rbx # Save RBX
    mov     qword ptr [rdi+JB_R12], r12 # Save R12
    mov     qword ptr [rdi+JB_R13], r13 # Save R13
    mov     qword ptr [rdi+JB_R14], r14 # Save R14
    mov     qword ptr [rdi+JB_R15], r15 # Save R15
    lea     rdx, [rsp+8]
    mov     qword ptr [rdi+JB_RSP], rdx # Save RSP (after we return)
    mov     qword ptr [rdi+JB_RBP], rbp # Save RBP
    mov     rdx, [rsp]
    mov     qword ptr [rdi+JB_PC], rdx  # Save PC

    jmp     __setjmp_sig_save

