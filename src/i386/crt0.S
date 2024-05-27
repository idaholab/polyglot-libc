/* Startup code compliant to the ELF i386 ABI.

   This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/i386/start.S).

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
This is the canonical entry point, usually the first thing in the text segment.
The SVR4/i386 ABI (pages 3-31, 3-32) says that when the entry point runs, most
registers' values are unspecified, except for:

%edx    Contains a function pointer to be registered with `atexit'.
        This is how the dynamic linker arranges to have DT_FINI functions called
        for shared libraries that have been loaded before this code runs.

%esp    The stack contains the arguments and environment:
            0(%esp)             argc
            4(%esp)             argv[0]
            ...
            (4*argc)(%esp)      NULL
            (4*(argc+1))(%esp)  envp[0]
            ...
            (?)(%rsp)           NULL
*/

.text
.globl      _start
.type       _start,@function
_start:
    xorl    %ebp, %ebp          /* Clear the frame pointer. */

    popl    %esi                /* Pop the argument count.  */
    movl    %esp, %ecx          /* argv starts just at the current stack top. */

# FIXME: why is this necessary on Linux a.out files? what are the two values
# that are between argc and argv?
#if defined(__target_os_linux) && defined(__target_aout)
    addl    $8, %ecx
#endif

    andl    $0xfffffff0, %esp   /* Before pushing the arguments align the stack
                                 * to a 16-byte (SSE needs 16-byte alignment)
                                 * boundary to avoid penalties from misaligned
                                 * accesses.  Thanks to Edward Seidl
                                 * <seidl@janed.com> for pointing this out. */
    pushl   %eax                /* Push garbage because we allocate 28 bytes. */

    pushl   %esp                /* Provide the highest stack address to the user
                                 * code (for stacks which grow downwards). */
    pushl   %edx                /* Address of the shared lib terminator. */
    pushl   %ecx                /* Push second argument: argv. */
    pushl   %esi                /* Push first argument: argc. */
    pushl   $main               /* Push user-provided main function. */

    call    __libc_main         /* Call the user's main function via
                                 * __libc_main, and exit with its value. */
    hlt                         /* Crash if somehow `exit' does return. */


/* To fulfill the System V/i386 ABI we need this symbol. Yuck, it's so
 * meaningless since we don't support machines < 80386. */
.section    .rodata
.globl      _fp_hw
.type       _fp_hw,@object
_fp_hw:
    .long   3
    .size   _fp_hw, 4

/* Define a symbol for the first piece of initialized data. */
.data
.globl      __data_start
__data_start:
    .long   0
    .weak   data_start
data_start = __data_start

