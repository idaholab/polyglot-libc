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
#include <bits/linux/stat.h>
#include <sys/stat.h>

#ifdef __NR_fstatat64

int __sys_fstatat64(int fd, const char *pathname, struct stat *stbuf, int flag)
{
    struct __kernel_stat64 k_stbuf;

    if (syscall(__NR_fstatat64, fd, pathname, &k_stbuf, flag) == -1)
        return -1;

    __copy_stat64(&k_stbuf, stbuf);
    return 0;
}

#endif
