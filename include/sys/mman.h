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

#if !defined(_SYS_MMAN_H)
#define _SYS_MMAN_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <target/mman.h>

/* MACRO DEFINITIONS **********************************************************/

#define MAP_FAILED ((void*)-1)

#define MADV_DONTNEED   POSIX_MADV_DONTNEED
#define MADV_NORMAL     POSIX_MADV_NORMAL
#define MADV_RANDOM     POSIX_MADV_RANDOM
#define MADV_SEQUENTIAL POSIX_MADV_SEQUENTIAL
#define MADV_WILLNEED   POSIX_MADV_WILLNEED

/* FUNCTION PROTOTYPES ********************************************************/

int madvise(void *, size_t, int);
void *mmap(void *, size_t, int, int, int, off_t);
int munmap(void *, size_t);
int posix_madvise(void *, size_t, int);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - int mprotect(void *, size_t, int);
 *   - int msync(void *, size_t, int);
 *   - int mlock(const void *, size_t);
 *   - int munlock(const void *, size_t);
 *   - int mlockall(int);
 *   - int munlockall(void);
 *   - int posix_mem_offset(const void *restrict, size_t, off_t *restrict,
 *                 size_t *restrict, int *restrict);
 *   - int posix_typed_mem_get_info(int, struct posix_typed_mem_info *);
 *   - int posix_typed_mem_open(const char *, int, int);
 *   - int shm_open(const char *, int, mode_t);
 *   - int shm_unlink(const char *);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_MMAN_H
