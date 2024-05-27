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

#include <bits/linux/pty.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>


int posix_openpt(int oflag)
{
    const char *x, *y;
    char master[PTY_PREFIX_LEN+3], slave[PTY_PREFIX_LEN+3];
    int fd;
    struct stat stbuf;

    if (oflag & ~(O_RDWR|O_NOCTTY)) {
        errno = EINVAL;
        return -1;
    }

    /* We first try to open the PTY muxer device */
    fd = open(PTMX_DEV, oflag);
    if (fd != -1)
        return fd;

    /* Okay... we didn't find a PTY muxer. So that means we are probably using
     * old-school BSD-style PTYs and have to figure it out for ourselves. */

    /* Prime our buffers */
    snprintf(master, PTY_PREFIX_LEN + 3, "%s??", PTYM_PREFIX);
    snprintf(slave, PTY_PREFIX_LEN + 3, "%s??", PTYS_PREFIX);

    /* We iterate through the possible combinations of valid device names */
    for (x = XRANGE; *x; ++x) {
        master[PTY_PREFIX_LEN] = *x;
        slave[PTY_PREFIX_LEN] = *x;

        for (y = YRANGE; *y; ++y) {
            master[PTY_PREFIX_LEN + 1] = *y;
            slave[PTY_PREFIX_LEN + 1] = *y;

            /* Try to open the master; if we get an error, we assume that that
             * means the device is busy (usually returns EAGAIN). */
            if ((fd = open(master, oflag)) == -1)
                continue;

            /* Try to stat the slave to make sure we have a matched pair */
            if (stat(slave, &stbuf) == -1) {
                close(fd);
                continue;
            }

            return fd;
        }
    }

no_ptys:
    /* We failed to find an available PTY, so fail out */
    errno = EAGAIN;
    return -1;
}


