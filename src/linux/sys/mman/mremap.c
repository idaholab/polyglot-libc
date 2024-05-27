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

#include <stdarg.h>
#include <polyglot/syscall_choice.h>
#include <bits/linux/syscall.h>
#include <bits/linux/features.h>
#include <sys/mman.h>

syscall_choice(
    // syscall (name, signature, failure)
    __mremap,
    void*, ( void*,  addr,
             size_t, old_len,
             size_t, new_len,
             int,    flags,
             void*,  new_addr ),
    NULL,
    // options (name, function)
#if defined(HAS_NATIVE_mremap)
    MREMAP, __sys_mremap,
#endif
)

void* mremap(void* addr, size_t old_len, size_t new_len, int flags, ...)
{
    va_list va;
    void* new_addr = 0;
    if (flags & MREMAP_FIXED) {
        va_start(va, flags);
        new_addr = va_arg(va, void*);
        va_end(va);
    }
    return __mremap(addr, old_len, new_len, flags, new_addr);
}

