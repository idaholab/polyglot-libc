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

syscall_choice(
    /* syscall   */ getpeername,
    /* return    */ int,
    /* args      */ (
                        int, socket,
                        struct sockaddr*, address,
                        socklen_t*, address_len
                    ),
    /* failure   */ -1,
#ifdef __NR_getpeername
    /* option    */ GETPEERNAME, __sys_getpeername,
#endif
#ifdef HAS_NATIVE_socketcall
    /* option    */ SOCKETCALL, __getpeername_via_socketcall,
#endif
)

