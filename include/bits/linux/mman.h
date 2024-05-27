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

#ifndef _LINUX_MMAN_H
#define _LINUX_MMAN_H _LINUX_MMAN_H

#define __NEED_PROT_FLAGS 1
#define __NEED_MAP_FLAGS 1
#define __NEED_MSYNC_FLAGS 1
#define __NEED_MLOCK_FLAGS 1
#define __NEED_MADV_FLAGS 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(mman.h))
#include __target_os_arch_header(mman.h)
#endif

/* these are defined outside of arch-specific headers */
#define MAP_PRIVATE             0x2
#define MAP_SHARED              0x1

/* these aren't platform-independent (because mremap() isn't), but -do- seem to
 * be architecture-independent within Linux */
void* mremap(void*, size_t, size_t, int, ...);
#define MREMAP_MAYMOVE          1
#define MREMAP_FIXED            2
#define MREMAP_DONTUNMAP        4

#ifdef __NEED_PROT_FLAGS
#define PROT_EXEC               4
#define PROT_NONE               0
#define PROT_READ               1
#define PROT_WRITE              2
#endif

#ifdef __NEED_MAP_FLAGS
#define MAP_ANONYMOUS           0x20
#define MAP_FIXED               0x10
#endif

#ifdef __NEED_MSYNC_FLAGS
#define MS_ASYNC                1
#define MS_INVALIDATE           2
#define MS_SYNC                 4
#endif

#ifdef __NEED_MLOCK_FLAGS
#define MCL_CURRENT             1
#define MCL_FUTURE              2
#endif

#ifdef __NEED_MADV_FLAGS
/* Per glibc note, Linux kernel's behavior for this doesn't completely map to
 * POSIX... whether that matters or not is a different matter. */
#define POSIX_MADV_DONTNEED     4
#define POSIX_MADV_NORMAL       0
#define POSIX_MADV_RANDOM       1
#define POSIX_MADV_SEQUENTIAL   2
#define POSIX_MADV_WILLNEED     3
#endif

#undef __NEED_PROT_FLAGS
#undef __NEED_MAP_FLAGS
#undef __NEED_MSYNC_FLAGS
#undef __NEED_MLOCK_FLAGS
#undef __NEED_MADV_FLAGS

#endif // _LINUX_MMAN_H
