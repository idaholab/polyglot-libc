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
#include <bits/linux/syscall.h>
#include <bits/linux/shim.h>
#include <errno.h>

/* XXX: Okay, so this is -not- implemented correctly, but what we run into here
 *      is EXACTLY WHY faccessat2() EXISTS! So if we want to use this, we're
 *      just going to shim it if the flags are set, since we can't with this
 *      syscall directly anyway. */

#ifdef __NR_faccessat

int __sys_faccessat(int fd, const char* path, int mode, int flags)
{
    if (flags == 0) {
        return syscall(__NR_faccessat, fd, path, mode);
    } else {
#if defined(HAS_fstatat)
        return __faccessat_via_fstatat(fd, path, mode, flags);
#else
        // if flags are set and we can't do fstatat (for whatever reason... that
        // shouldn't ever be a thing?), then we just bail here rather than try
        // to do something horrible...
        errno = EINVAL;
        return -1;
#endif
    }
}

#else // __NR_faccessat

#if 0
// tilegx sucks
long __sys_faccessat(long, long, long, long)
     __attribute__((alias("__enosys4")));
#endif

#endif // __NR_faccessat
