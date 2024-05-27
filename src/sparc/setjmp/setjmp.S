/* Special .init and .fini section support for sparc.

   This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/sparc/sparc32/setjmp.S).

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

#include <bits/sparc/setjmp.h>

#define ST_FLUSH_WINDOWS 3

.globl          _setjmp
.type           _setjmp,@function
_setjmp:
    ba          sigsetjmp
      mov       0, %o1

.globl          setjmp
.type           setjmp,@function
setjmp:
    ba          sigsetjmp
      mov       1, %o1

.globl          sigsetjmp
.type           sigsetjmp,@function
sigsetjmp:
    ta          ST_FLUSH_WINDOWS
    
    /* save PC, SP, FP to the struct */
    st          %o7, [%o0 + (JB_PC)]
    st          %sp, [%o0 + (JB_SP)]
    st          %fp, [%o0 + (JB_FP)]

    /* tail-call __sigjmp_save, takes the same args */
    mov         %o7, %g1
    call        __setjmp_sig_save
      mov       %g1, %o7


