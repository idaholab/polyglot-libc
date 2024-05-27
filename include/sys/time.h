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

#if !defined(_SYS_TIME_H)
#define _SYS_TIME_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/select.h>

/* MACRO DEFINITIONS **********************************************************/

/* NOTE: Linux and Solaris have these values the same; they *could* differ on
 * other platforms potentially, so we should check this again. */
#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

/* TYPE DEFINITIONS ***********************************************************/

struct itimerval
{
    struct timeval  it_interval;
    struct timeval  it_value;
};

/* FUNCTION PROTOTYPES ********************************************************/

int gettimeofday(struct timeval *restrict, void *restrict);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int getitimer(int, struct itimerval *);
 *   - int setitimer(int, const struct itimerval *restrict,
 *               struct itimerval *restrict);
 *   - int utimes(const char *, const struct timeval [2]);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_TIME_H
