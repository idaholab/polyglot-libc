/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/i386/setjmp.S).

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

.globl      setjmp
.type       setjmp,@function
setjmp:
    pop     eax
    pop     ecx
    push    1
    push    ecx
    push    eax
    jmp     sigsetjmp


.globl      _setjmp
.type       _setjmp,@function
_setjmp:
    pop     eax
    pop     ecx
    push    0
    push    ecx
    push    eax
    jmp     sigsetjmp


.globl      sigsetjmp
.type       sigsetjmp,@function
sigsetjmp:
    mov     eax, [esp+4]

    mov     dword ptr [eax+JB_EBX], ebx # Save EBX
    mov     dword ptr [eax+JB_ESI], esi # Save ESI
    mov     dword ptr [eax+JB_EDI], edi # Save EDI
    lea     ecx, [esp+4]
    mov     dword ptr [eax+JB_ESP], ecx # Save ESP (after we return)
    mov     dword ptr [eax+JB_EBP], ebp # Save EBP
    mov     ecx, [esp]
    mov     dword ptr [eax+JB_PC], ecx  # Save PC

    jmp     __setjmp_sig_save


