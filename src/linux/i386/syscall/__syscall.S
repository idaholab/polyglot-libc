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

.intel_syntax noprefix

/* long __syscall() */

.text
.globl          __syscall
.type           __syscall,@function
__syscall:
    push        ebp                 /* save registers */
    push        edi
    push        esi
    push        ebx

    mov         ebp, [esp+16+28]    /* load arguments off stack */
    mov         edi, [esp+16+24]
    mov         esi, [esp+16+20]
    mov         edx, [esp+16+16]
    mov         ecx, [esp+16+12]
    mov         ebx, [esp+16+8]
    mov         eax, [esp+16+4]     /* load syscall number into %eax */

    int         0x80                /* do the system call */

    pop         ebx                 /* restore registers */
    pop         esi
    pop         edi
    pop         ebp

    cmp         eax, -4095          /* check %eax for error */
    jae         error               /* jump to error handler if error */
    ret

error:
    neg         eax                 /* fix error code */
    mov         [esp+4], eax        /* reuse stack space for argument */
    jmp         __syscall_error     /* tail-call error handler */

