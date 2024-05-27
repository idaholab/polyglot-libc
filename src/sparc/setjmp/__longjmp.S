/* Special .init and .fini section support for sparc.

   This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/sparc/sparc32/__longjmp.S).

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

.globl          __longjmp
.type           __longjmp,@function
__longjmp:
    /* Store our arguments in global registers so we can still
       use them while unwinding frames and their register windows.  */
    ld          [%o0 + (JB_FP)], %g3    /* save our target fp in %g3 */
    mov         %o0, %g1                /* store env in %g1 */
    orcc        %o1, %g0, %g2           /* store retval in %g2 */
    be,a        loop                    /* branch if retval is zero */
      mov       1, %g2                  /* delay slot only hit if zero */

loop:
    /* Now we will loop, unwinding the register windows up the stack
       until the restored %fp value matches the target value in %g3.  */
    cmp         %fp, %g3                /* have we found our frame? */
    bl,a        loop                    /* loop while fp is below target */
      restore                           /* unwind register window */
    be,a        found                   /* we have to hit it exactly */
      ld        [%g1 + (JB_SP)], %o0    /* extract target SP */

found:
    /* we have unwound register windows so %fp matches the target */
    mov         %o0, %sp                /* restore new SP */
    ld          [%g1 + (JB_PC)], %o0    /* extract target return PC */
    jmp         %o0 + 8                 /* return to that address */
      mov       %g2, %o0                /* set return value */


