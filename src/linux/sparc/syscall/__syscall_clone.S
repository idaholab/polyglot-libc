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

#ifdef __NR_clone

/* pid_t __syscall_clone(unsigned long flags, void *stack, int stack_size,
            int *parent_tid, int *child_tid, unsigned long tls) */

.text
.globl      __syscall_clone
.type       __syscall_clone,@function
__syscall_clone:
    save    %sp,-96,%sp     /* ... */

    /* if we were given a child stack, allocate a stack frame, per what the
     * kernel is looking for; however, the child stack can be null */
    orcc    %i1,%g0,%o1     /* stack */
    be      0f              /* is the stack non-null? */
     nop
    sub     %o1,96,%o1      /* fix stack */

0:
    mov     %i0,%o0         /* flags */
    mov     %i2,%o2         /* ptid */
    mov     %i4,%o3         /* tls */
    mov     %i3,%o4         /* ctid */

    set     __NR_clone,%g1  /* syscall number */
    ta      0x10            /* do the syscall */
    bcc     1f              /* did we succeed? */
      nop
    ba      __syscall_error /* nope, tail-call error handler */
      nop
1:
    tst     %o1             /* check whether we're parent/child */
    be      2f              /* branch if parent */
     nop
    set     0,%o0           /* child clears return */
2:
    mov     %o0,%i0         /* set return */
    ret                     /* return to caller */
     restore                /* ... */

#endif
