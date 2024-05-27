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

#if !defined(_SYS_UIO_H)
#define _SYS_UIO_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>

/* TYPE DEFINITIONS ***********************************************************/

struct iovec
{
    void *iov_base;
    size_t iov_len;
};

/* FUNCTION PROTOTYPES ********************************************************/

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - ssize_t readv(int, const struct iovec *, int);
 *   - ssize_t writev(int, const struct iovec *, int);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_UIO_H
