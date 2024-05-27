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
#include <poll.h>

#if defined(HAS_NATIVE_ppoll)

int __poll_via_ppoll(struct pollfd fds[], nfds_t nfds, int timeout)
{
    struct timespec ts;

    if (timeout != -1) {
        ts.tv_sec = (timeout / 1000);
        ts.tv_nsec = (timeout % 1000) * 1000000;
    }

    return ppoll(fds, nfds, (timeout == -1) ? NULL : &ts, NULL);
}

#endif
