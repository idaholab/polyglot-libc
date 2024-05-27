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
    mov         rax, rdi            /* syscall number -> rax */
    mov         rdi, rsi            /* shift arg1 - arg5 */
    mov         rsi, rdx
    mov         rdx, rcx
    mov         r10, r8
    mov         r8, r9
    mov         r9, [rsp+8]         /* arg6 is on the stack */
    syscall                         /* do the system call */
    cmp         rax, -4095          /* check rax for error */
    jae         error               /* jump to error handler if error */
    ret                             /* return to caller */

error:
    neg         rax                 /* fix error code */
    mov         rdi, rax            /* set arg */
    jmp         __syscall_error     /* tail-call error handler */

