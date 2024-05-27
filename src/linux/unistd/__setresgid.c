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
#include <unistd.h>

syscall_choice(
    /* syscall   */ __setresgid,
    /* return    */ int,
    /* args      */ (
                        gid_t, rgid,
                        gid_t, egid,
                        gid_t, sgid
                    ),
    /* failure   */ -1,
#ifdef __NR_setresgid32
    /* option    */ SETRESGID32, __sys_setresgid32,
#endif
#ifdef __NR_setresgid
    /* option    */ SETRESGID, __sys_setresgid,
#endif
)

