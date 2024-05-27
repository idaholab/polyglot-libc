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
#include <sys/select.h>

#ifdef HAS_NATIVE_pselect

int __select_via_pselect(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds,
        struct timeval *tv)
{
    struct timespec ts;

    if (tv) {
        ts.tv_sec = tv->tv_sec;
        ts.tv_nsec = tv->tv_usec * 1000;
    }

    return pselect(
        nfds, rfds, wfds, efds,
        tv ? &ts : NULL, NULL
    );
}

#endif
