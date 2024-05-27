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
#include <sys/ipc.h>
#include <errno.h>

#ifdef HAS_NATIVE_ipc

int __shmctl_via_ipc(int shmid, int cmd, void *buf)
{
    /* FIXME: this needs some more looking at for this case based on how
     * complicated the glibc definitions are... I think there's a 64-bit
     * version of the commands possibly? */
    /* XXX: based on our testing on modern Linux, either cmd | IPC_64 or cmd
     * both work just fine, but I'm not sure if we need to do more testing; I
     * am leaving these blurbs for future reference though... */

    int result;
    if (((result = __ipc(IPC_SHMCTL, shmid, cmd | IPC_64, 0, buf)) != -1)
            || (errno != EINVAL))
        return result;
    return __ipc(IPC_SHMCTL, shmid, cmd, 0, buf);
}

#endif
