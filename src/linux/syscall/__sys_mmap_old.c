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
#include <sys/types.h>
#include <sys/mman.h>
#include <stddef.h>

#if defined(__NR_mmap_old)

/* This is only present on a few platforms, and if you look in the "official"
 * syscall lists, it will be called "mmap" as well, but it's distinct in that,
 * under-the-hood, it's tying mmap() -> sys_old_mmap(), which takes its
 * arguments as a struct. We have renamed this syscall to oldmmap() in order to
 * cleanly differentiate it here and unify the code base cross-arch. */
void *__sys_mmap_old(void *addr, size_t length, int prot, int flags, int fd,
            off_t offset)
{
    unsigned long args[] = {
        (unsigned long)addr, length, prot, flags, fd, offset
    };
    void *result = (void*)syscall(__NR_mmap_old, &args);
    // note that we return MAP_FAILED on failure, but the syscall returns NULL
    return (result == NULL ? MAP_FAILED : result);
}

#endif
