/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/arm/__longjmp.S).

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

#include <bits/arm/setjmp.h>

.text

.globl      __longjmp
.type       __longjmp,%function
__longjmp:
    mov     ip, r0

    /* Restore sp and lr */
    ldr     sp, [ip], #4
    ldr     lr, [ip], #4
    /* Restore common registers */
    ldmia   ip!, { r4-r11 }

    /* Fix our return value */
    mov     r0, r1
    cmp     r0, #0
    it      ne
    bne     return
    mov     r0, #1

return:
#ifdef __ARM_ARCH_4T__
    bx      lr
#else
    mov     pc, lr
#endif


