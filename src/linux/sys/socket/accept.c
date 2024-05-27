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
    /* syscall   */ accept,
    /* return    */ int,
    /* args      */ (
                        int, socket,
                        struct sockaddr*, address,
                        socklen_t*, address_len
                    ),
    /* failure   */ -1,
#ifdef HAS_NATIVE_accept4
    /* XXX: this could theoretically need to be HAS_accept4, if there were a
     * system that had socketcall(), but didn't support SOCALL_ACCEPT, and
     * intead only supported SOCALL_ACCEPT4; based on our understanding, this
     * seems unlikely, since the shift has been away from socketcall(), and
     * accept4() is a much more recent syscall than accept(). We are noting
     * this here though, in case we run into that corner case... it saves us
     * some binary space to not do HAS_accept4 though. */
    /* option    */ ACCEPT4, __accept_via_accept4,
#endif
#ifdef __NR_accept
    /* option    */ ACCEPT, __sys_accept,
#endif
#ifdef HAS_NATIVE_socketcall
    /* option    */ SOCKETCALL, __accept_via_socketcall,
#endif
)

