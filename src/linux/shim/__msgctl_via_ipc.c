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

#ifdef HAS_NATIVE_ipc

/* XXX: final argument is actually a union, but we generalize it down to a
 * platform-sized value, since that's as big as it will be (pointers, etc.) */

int __msgctl_via_ipc(int msqid, int cmd, long arg)
{
    /* FIXME: there might be a 64-bit version of this? If there is, we should
     * test on 32-bit-on-64-bit Linux, since that's where you'd get a 64-bit
     * value with a 32-bit executable; since the last argument is a pointer to
     * the value, it may just be a pointer to a 64-bit value in that case */
    return __ipc(IPC_MSGCTL, msqid, cmd, 0, &arg);
}

#endif
