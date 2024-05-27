/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/i386/__longjmp.S).

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

#include <bits/i386/setjmp.h>

.text

.globl      __longjmp
.type       __longjmp,@function
__longjmp:
    mov     eax, [esp+8]                # Load the return value
    cmp     eax, 0                      # If the return value is 0, make it 1
    jne     copy_regs
    mov     eax, 1

copy_regs:
    mov     ecx, [esp+4]                # Load the jmp_buf
    mov     edx, [ecx+JB_PC]            # Load the address to return to

    mov     ebx, [ecx+JB_EBX]           # Restore EBX
    mov     esi, [ecx+JB_ESI]           # Restore ESI
    mov     edi, [ecx+JB_EDI]           # Restore EDI
    mov     ebp, [ecx+JB_EBP]           # Restore EBP
    mov     esp, [ecx+JB_ESP]           # Restore ESP

    jmp     edx                         # Jump to our return point


