/* Startup code for ARM & ELF

   This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/arm/start.S).

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

/* This is the canonical entry point. At this entry point, most registers have
   unspecified values, except for:

   a1  Contains a function pointer to be registered with `atexit'.
       NOTE: We don't actually need to bother with this because Polyglot doesn't
             support any sort of dynamic linking, and trying to use the pointer
             messes up some older Linuxes regardless.

   sp  The stack contains the arguments and environment:
           0(sp)               argc
           4(sp)               argv[0]
           ...
           (4*argc)(sp)        NULL
           (4*(argc+1))(sp)    envp[0]
           ...
           (?)(sp)             NULL
*/

.section .note.GNU-stack,""

.eabi_attribute 25, 1   /* Tag_ABI_align8_preserved */
.eabi_attribute 24, 1   /* Tag_ABI_align8_needed */

.text
.globl      _start
.type       _start,%function
_start:
.fnstart
    /* clear the frame pointer/link register */
    mov     fp, #0
    mov     lr, #0

    pop     { a2 }      /* (arg 2) Pop argc off the stack */
    mov     a3, sp      /* (arg 3) Save a pointer to argv */
    push    { a3 }      /* (arg 5) Push stack limit */
    mov     a4, a1      /* (arg 4) Move rtld_fini to argument register */
    ldr     a1, =main   /* (arg 1) Load address of main function */

    /* __libc_main (main, argc, argv, init, fini, rtld_fini, stack_end) */
    bl      __libc_main

    /* should never get here....*/
    bl      abort

.cantunwind
.fnend

/* Define a symbol for the first piece of initialized data. */
.data
.globl      __data_start
__data_start:
    .long   0
    .weak   data_start
    data_start = __data_start

