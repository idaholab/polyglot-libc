/* This file is part of the Polyglot C Library. It is a modification of a file
   in the GNU C Library (sysdeps/mips/start.S).

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

/* This is the canonical entry point; the SVR4/MIPS ABI (pages 3-31, 3-32) says
   that the following registers are initialized as such:

       $v0     Contains a function pointer to be registered with atexit(); this
               is how the dynamic linker has DT_FINI functions called.
       $sp     Stack contains the arguments and environment:
                   0($sp)              argc
                   4($sp)              argv[0]
                   ...
                   (4*argv)($sp)       NULL
                   (4*(argv+1))($sp)   envp[0]
                   ...
                   ...                 NULL
       $ra     Return address register is set to zero.

   Any other registers' starting states are undefined.
*/

.text
.globl          _start
.type           _start,@function
_start:
    lui         $gp, %highest(_gp)  /* load _gp; this is ugly because 64-bit */
    lui         $t0, %hi(_gp)
    daddiu      $gp, $gp, %higher(_gp)
    daddiu      $t0, $t0, %lo(_gp)
    dsll32      $gp, $gp, 0
    daddu       $gp, $gp, $t0

    move        $ra, $0             /* zero out return address */
    dla         $a0, main           /* (arg 1) main function */
    ld          $a1, 0($sp)         /* (arg 2) argc */
    daddiu      $a2, $sp, 8         /* (arg 3) argv */
    and         $sp, -16            /* make sure stack pointer is 16-aligned */
    move        $a3, $v0            /* (arg 4) rtld_fini */
    move        $a4, $sp            /* (arg 5) stack end */

    dla         $t0, __libc_main
    jalr        $t0
    /* Loop infinitely if we somehow do return. */
0:
    b           0b

/* We need to have a __start symbol instead of _start on some MIPS ABIs. */
.weak           __start
    __start     = _start

/* Define a symbol for the first piece of initialized data. */
.data
.globl          __data_start
__data_start:
    .long       0

.weak           data_start
    data_start  = __data_start

