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


/* XXX: Because this is a noreturn function, we are explicitly excluding it
 * from the syscall mechanism; if we run into an architecture that needs us to
 * differentiate exit syscalls within an ABI, we will tackle that then. */


/* Actually perform the exit syscall; exits immediately, no handlers. */
__attribute__((noreturn))
void _exit(int status)
{
#if defined(__NR_exit)
    syscall(__NR_exit, status);
#else
#error "No __NR_exit defined for this architecture!"
#endif
    __builtin_unreachable();
}


