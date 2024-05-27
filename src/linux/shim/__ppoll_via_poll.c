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
#include <signal.h>
#include <poll.h>

#if defined(HAS_NATIVE_poll)

int __ppoll_via_poll(struct pollfd fds[], nfds_t nfds,
        const struct timespec *ts, const sigset_t *sigmask)
{
    sigset_t orig_mask;
    int result;

    if (sigmask && (sigprocmask(SIG_SETMASK, sigmask, &orig_mask) == -1))
        return -1;

    result = poll(
        fds, nfds,
        ts ? (ts->tv_sec * 1000) + (ts->tv_nsec / 1000000) : -1
    );

    if (sigmask && (sigprocmask(SIG_SETMASK, &orig_mask, NULL) == -1))
        return -1;

    return result;
}

#endif
