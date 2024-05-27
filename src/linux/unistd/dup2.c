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

#include <polyglot/syscall_choice.h>
#include <bits/linux/syscall.h>
#include <bits/linux/features.h>
#include <bits/linux/shim.h>
#include <unistd.h>

syscall_choice(
    /* syscall   */ dup2,
    /* return    */ int,
    /* args      */ (
                        int, oldfd,
                        int, newfd
                    ),
    /* failure   */ -1,
#ifdef HAS_NATIVE_dup3
    /* option    */ DUP3, __dup2_via_dup3,
#endif
#ifdef __NR_dup2
    /* option    */ DUP2, __sys_dup2,
#endif
)

