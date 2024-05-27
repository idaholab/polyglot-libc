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
#include <polyglot/heap.h>

#ifdef __NR_brk

/* Linux is weird in that the brk() syscall returns the address of the new
 * break rather than a strictly 0/-1 result. We need to check it differently
 * than other platforms because of that. */
int __sys_brk(void *new_end)
{
    void *ptr = (void*)syscall(__NR_brk, new_end);
    if (ptr < new_end) {
        return -1;
    } else {
        __heap_end = ptr;
        return 0;
    }
}

#endif
