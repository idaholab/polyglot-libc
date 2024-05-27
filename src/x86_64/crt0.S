/* Startup code compliant to the ELF i386 ABI.

   This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/x86_64/start.S).

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

/*
This is the canonical entry point, usually the first thing in the text
segment.  The SVR4/i386 ABI (pages 3-31, 3-32) says that when the entry
point runs, most registers' values are unspecified, except for:

%rdx    Contains a function pointer to be registered with `atexit'.
        This is how the dynamic linker arranges to have DT_FINI
        functions called for shared libraries that have been loaded
        before this code runs.

%rsp    The stack contains the arguments and environment:
            0(%rsp)                     argc
            LP_SIZE(%rsp)               argv[0]
            ...
            (LP_SIZE*argc)(%rsp)        NULL
            (LP_SIZE*(argc+1))(%rsp)    envp[0]
            ...
            (?)(%rsp)                   NULL

Arguments for __libc_main are passed via registers and on the stack:

| main | argc | argv | init | fini | rtld_fini | stack_end |
| %rdi | %rsi | %rdx | %rcx | %r8  | %r9       | stack     |

*/

.text
.globl      _start
.type       _start,@function
_start:
    xorl    %ebp, %ebp              /* clear the frame pointer */

    mov     %rdx, %rcx              /* (arg 4) rtld_fini */
    popq    %rsi                    /* (arg 2) argc */
    mov     %rsp, %rdx              /* (arg 3) argv */
    and     $~15, %rsp              /* align the stack to a 16 byte boundary */
    mov     %rsp, %r8               /* (arg 5) stack end */
    mov     $main, %rdi             /* (arg 1) main function */

    call    __libc_main             /* call the user's main function via
                                     * __libc_main, and exit with its value */
    hlt                             /* crash if somehow `exit' does return */


/* define a symbol for the first piece of initialized data */
.data
.globl      __data_start
__data_start:
    .long   0
    .weak   data_start
data_start = __data_start

