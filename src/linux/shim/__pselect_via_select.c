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
#include <signal.h>

#ifdef HAS_NATIVE_select

int __pselect_via_select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds,
        const struct timespec *ts, const sigset_t *sigmask)
{
    struct timeval tv;
    sigset_t orig_mask;
    int result;

    if (ts) {
        tv.tv_sec = ts->tv_sec;
        tv.tv_usec = ts->tv_nsec / 1000;
    }

    if (sigmask && (sigprocmask(SIG_SETMASK, sigmask, &orig_mask) == -1))
        return -1;
    result = select(
        nfds, rfds, wfds, efds,
        ts ? &tv : NULL
    );
    if (sigmask && (sigprocmask(SIG_SETMASK, &orig_mask, NULL) == -1))
        return -1;
    return result;
}

#endif
