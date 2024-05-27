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
#include <stdarg.h>

#ifdef __NR_fcntl64

int __sys_fcntl64_v(int fildes, int request, va_list ap)
{
    void *argp;
    int e;

    /* FIXME: this should probably branch to try to get an argument only if its
     * a request that has an argument; essentially this is pulling garbage from
     * the stack otherwise and relying on the kernel to ignore the third
     * parameter if it doesn't need it... probably a vulnerability, tbh. */
    argp = va_arg(ap, void *);

    return syscall(__NR_fcntl64, fildes, request, argp);
}

#endif
