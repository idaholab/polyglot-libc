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
#include <fcntl.h>

#ifdef __NR_faccessat2

int __sys_faccessat2(int fd, const char* path, int mode, int flags)
{
    return syscall(__NR_faccessat2, fd, path, mode, flags);
}

#else // __NR_faccessat2

#if 0
// tilegx sucks
long __sys_faccessat2(long, long, long, long)
     __attribute__((alias("__enosys4")));
#endif

#endif // __NR_faccessat2
