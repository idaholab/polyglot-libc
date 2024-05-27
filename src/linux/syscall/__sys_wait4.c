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
#include <sys/resource.h>

#ifdef __NR_wait4

pid_t __sys_wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage)
{
    pid_t result;
    struct __kernel_rusage k_rusage;

    if ((result = syscall(__NR_wait4, pid, wstatus, options, &k_rusage)) == -1)
        return -1;
    if (rusage)
        __copy_rusage(&k_rusage, rusage);
    return result;
}

#endif
