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

#include <bits/linux/syscall.h>

.section .note.GNU-stack,""

/* long __syscall() */

.text
.globl      __syscall
.type       __syscall,%function
__syscall:
    mov     ip, sp

#if defined(__target_abi_eabi)

/* EABI uses r7 for syscall number, and r0-r6 for arguments. */

    push    {r4, r5, r6, r7}
    mov     r7, r0
    mov     r0, r1
    mov     r1, r2
    mov     r2, r3
    ldmfd   ip, {r3, r4, r5, r6}
    swi     0x0
    pop     {r4, r5, r6, r7}

#elif defined(__target_abi_oabi)

/* So we _do_ define a __syscall() function on ARM-OABI, but we won't ever use
 * it in our code; I tried implementing it this way, and, while it works for
 * some syscalls, others explode in bizarre ways if called using __NR_syscall
 * (i.e. __syscall(__NR_mmap2, ...) -> EOVERFLOW with the same arguments as
 * calling it using __NR_mmap2, and I can't figure out why, while write() works
 * fine). The solution is that we use inline assembly syscalls (defined in
 * <linux/arm/syscall.h>) instead of calling this function. */

    push    {r4, r5, r6}
    ldmfd   ip, {r4, r5, r6}
    swi     __NR_syscall
    pop     {r4, r5, r6}

#else
#error "Unsupported ARM ABI for syscalls"
#endif

    cmn     r0, #4096               /* check if r0 + 4096 overflows, i.e. we */
    it      cc                      /*   got back a number -4096 < r0 < 0 */
#ifdef __ARM_ARCH_4T__
    bxcc    lr
#else
    movcc   pc, lr
#endif

    rsb     r0, r0, #0              /* rsb -> r0 = 0 - r0 -> -r0 */
    b       __syscall_error         /* tail-call error handler */


