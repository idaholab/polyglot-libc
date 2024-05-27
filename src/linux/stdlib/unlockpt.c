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
#include <errno.h>


int unlockpt(int fd)
{
    /* XXX: It is assumed that systems that don't have TIOCSPTLCK have unlocked
     * PTYs out of the box and we don't have to do anything; YMMV. */

    int lock = 0;
    if (ioctl(fd, TIOCSPTLCK, &lock) == -1) {
        if (errno != EINVAL)
            return -1;
    }

    /* Either we failed with EINVAL (which is what is returned when the request
     * is invalid) or we succeeded, so we *should* be good either way. */
    return 0;
}


