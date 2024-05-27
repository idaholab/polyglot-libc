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

#if !defined(_SYS_SELECT_H)
#define _SYS_SELECT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <signal.h>
#include <time.h>

/* MACRO DEFINITIONS **********************************************************/

#define __NFDBITS       (8 * (int)sizeof(__fd_mask))
#define __FD_ELT(d)     ((d) / __NFDBITS)
#define __FD_MASK(d)    ((__fd_mask) (1ul << ((d) % __NFDBITS)))

#define FD_CLR(d, s)    ((void)(((s)->fds_bits)[__FD_ELT(d)] &= ~__FD_MASK(d)))
#define FD_ISSET(d, s)  ((((s)->fds_bits)[__FD_ELT(d)] & __FD_MASK(d)) != 0)
#define FD_SET(d, s)    ((void)(((s)->fds_bits)[__FD_ELT(d)] |= __FD_MASK(d)))
#define FD_ZERO(s) \
    do { \
        unsigned int __i; \
        fd_set *__arr = (s); \
        for (__i = 0; __i < sizeof(fd_set) / sizeof(__fd_mask); ++__i) \
            (__arr->fds_bits)[__i] = 0; \
    } while (0)

/* TYPE DEFINITIONS ***********************************************************/

struct timeval
{
    time_t          tv_sec;
    suseconds_t     tv_usec;
};

typedef struct __fd_set fd_set;

/* FUNCTION PROTOTYPES ********************************************************/

int select(int, fd_set*, fd_set*, fd_set*, struct timeval*);
int pselect(int, fd_set*, fd_set*, fd_set*, const struct timespec*, const sigset_t*);

/******************************************************************************/

#include <target/select.h>

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_SELECT_H
