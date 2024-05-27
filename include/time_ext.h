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

#if !defined(_TIME_EXT_H)
#define _TIME_EXT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* PLATFORM-SPECIFIC DEFINITIONS **********************************************/

#include <target/time.h>

/* FUNCTION PROTOTYPES ********************************************************/

int clock_gettime(clockid_t, struct timespec *);
int nanosleep(const struct timespec *, struct timespec *);
void tzset(void);

/* FIXME: the following functions are currently not implemented:
 *
 *   - char *asctime_r(const struct tm *restrict, char *restrict);
 *   - int clock_getcpuclockid(pid_t, clockid_t *);
 *   - int clock_getres(clockid_t, struct timespec *);
 *   - int clock_nanosleep(clockid_t, int, const struct timespec *,
 *                  struct timespec *);
 *   - int clock_settime(clockid_t, const struct timespec *);
 *   - char *ctime_r(const time_t *, char *);
 *   - struct tm *getdate(const char *);
 *   - struct tm *gmtime_r(const time_t *restrict, struct tm *restrict);
 *   - struct tm *localtime_r(const time_t *restrict, struct tm *restrict);
 *   - size_t strftime_l(char *restrict, size_t, const char *restrict,
 *                  const struct tm *restrict, locale_t);
 *   - char *strptime(const char *restrict, const char *restrict,
 *                  struct tm *restrict);
 *   - int timer_create(clockid_t, struct sigevent *restrict,
 *                  timer_t *restrict);
 *   - int timer_delete(timer_t);
 *   - int timer_getoverrun(timer_t);
 *   - int timer_gettime(timer_t, struct itimerspec *);
 *   - int timer_settime(timer_t, int, const struct itimerspec *restrict,
 *                  struct itimerspec *restrict);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _TIME_EXT_H
