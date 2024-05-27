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

#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>


/* XXX: duration is in microseconds */


int tcsendbreak(int fd, int duration)
{
    long long v;
    struct timespec ts;

    if (duration <= 0) {
        v = 250000000;
    } else {
        v = (long long)duration * 1000;
    }

    ts.tv_sec = v / 1000000000;
    ts.tv_nsec = (long)(v % 1000000000);

    if (ioctl(fd, TIOCSBRK, 0) < 0) {
        return -1;
    }

    nanosleep(&ts, NULL);

    if (ioctl(fd, TIOCCBRK, 0) < 0) {
        return -1;
    }

    return 0;
}


