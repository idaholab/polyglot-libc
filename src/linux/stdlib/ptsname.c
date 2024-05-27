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
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>


static char __ptsname[PTS_PREFIX_LEN+24];


char *ptsname(int fd)
{
    int pty;
    ino_t ino;
    const char *x, *y;
    char master[PTY_PREFIX_LEN+3], slave[PTY_PREFIX_LEN+3];
    struct stat stbuf;

    /* We first try to use TIOCGPTN to get the PTS number (this works for the
     * UNIX98-style PTYs, but not BSD). If the request is invalid, we assume
     * that that means we are doing BSD-style PTYs instead. */
    if (ioctl(fd, TIOCGPTN, &pty) == -1) {
        if (errno != EINVAL)
            return NULL;
    } else {
        snprintf(__ptsname, PTS_PREFIX_LEN + 24, "%s/%d", PTS_PREFIX, pty);
        return __ptsname;
    }

    /* FIXME: Is there a better way of doing this? This is the most "logical"
     * way I could come up with for determining the other half of the pair... */

    /* Get the inode of the master PTY */
    if (fstat(fd, &stbuf) == -1)
        return NULL;
    ino = stbuf.st_ino;

    /* Prime our buffers */
    snprintf(master, PTY_PREFIX_LEN + 3, "%s??", PTYM_PREFIX);
    snprintf(slave, PTY_PREFIX_LEN + 3, "%s??", PTYS_PREFIX);

    /* Walk through the possible device nodes */
    for (x = XRANGE; *x; ++x) {
        master[PTY_PREFIX_LEN] = *x;
        slave[PTY_PREFIX_LEN] = *x;

        for (y = YRANGE; *y; ++y) {
            master[PTY_PREFIX_LEN + 1] = *y;
            slave[PTY_PREFIX_LEN + 1] = *y;

            /* Try to stat the node; we just assume failure is okay here */
            if (stat(master, &stbuf) == -1)
                continue;

            /* If the inode of the device matches our master, we found the pair
             * we were looking for and can return the slave name. */
            if (stbuf.st_ino == ino) {
                snprintf(__ptsname, PTS_PREFIX_LEN + 24, "%s", slave);
                return __ptsname;
            }
        }
    }

    /* We couldn't resolve the slave, so we return a failure */
    errno = EINVAL;
    return NULL;
}


