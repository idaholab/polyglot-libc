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

#if !defined(_SYS_RESOURCE_H)
#define _SYS_RESOURCE_H 1

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

#include <sys/types.h>
#include <sys/time.h>

/******************************************************************************/

/* we use a 64-bit rlim_t because 32-bit binaries on 64-bit hosts can have
 * 64-bit rlimit values (i.e. Linux at least, via prlimit64) */
typedef unsigned long long rlim_t;

// universal rlimit structure; differs from kernel versions
struct rlimit
{
    rlim_t rlim_cur;
    rlim_t rlim_max;
};

// universal RLIM_* values; these may differ from kernel values
#define RLIM_INFINITY   (~0ull)
#define RLIM_SAVED_MAX  RLIM_INFINITY
#define RLIM_SAVED_CUR  RLIM_INFINITY

/******************************************************************************/

struct rusage
{
    struct timeval ru_utime;
    struct timeval ru_stime;
    long ru_maxrss;
    long ru_ixrss;
    long ru_idrss;
    long ru_isrss;
    long ru_minflt;
    long ru_majflt;
    long ru_nswap;
    long ru_inblock;
    long ru_oublock;
    long ru_msgsnd;
    long ru_msgrcv;
    long ru_nsignals;
    long ru_nvcsw;
    long ru_nivcsw;
};

/******************************************************************************/

int getpriority(int, id_t);
int getrlimit(int, struct rlimit *);
int getrusage(int, struct rusage *);
int setrlimit(int, const struct rlimit *);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - int setpriority(int, id_t, int);
 */

/******************************************************************************/

/* include target-specific after generic so that forward declarations can
 * include the rlimit/rusage structures if needed */
#include <target/resource.h>

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_RESOURCE_H
