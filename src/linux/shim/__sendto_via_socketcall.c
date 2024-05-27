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

#include <bits/linux/features.h>
#include <sys/socket.h>

#ifdef HAS_NATIVE_socketcall

ssize_t __sendto_via_socketcall(int socket, const void *buffer, size_t length,
            int flags, const struct sockaddr *dest_addr, socklen_t dest_len)
{
    return (ssize_t)__socketcall(
        SOCALL_SENDTO,
        socket, buffer, length, flags, dest_addr, dest_len
    );
}

#endif