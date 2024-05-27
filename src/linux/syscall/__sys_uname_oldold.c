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

#include <bits/linux/syscall.h>
#include <bits/linux/utsname.h>
#include <sys/utsname.h>
#include <strings.h>
#include <string.h>

#ifdef __NR_uname_oldold

int __sys_uname_oldold(struct utsname *un)
{
    struct kernel_utsname_oldold k_un;

    if (syscall(__NR_uname_oldold, &k_un) != 0)
        return -1;

    bzero(un, sizeof(struct utsname));
    memcpy(un->sysname,    k_un.sysname,    sizeof(k_un.sysname));
    memcpy(un->nodename,   k_un.nodename,   sizeof(k_un.nodename));
    memcpy(un->release,    k_un.release,    sizeof(k_un.release));
    memcpy(un->version,    k_un.version,    sizeof(k_un.version));
    memcpy(un->machine,    k_un.machine,    sizeof(k_un.machine));
    return 0;
}

#endif
