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

#ifndef _LINUX_RESOURCE_H
#define _LINUX_RESOURCE_H _LINUX_RESOURCE_H

#define __NEED_PRIO_CONSTS
#define __NEED_RUSAGE_CONSTS
#define __NEED_RLIMIT_CONSTS
#define __NEED_RLIM_INFINITY
#define __NEED_RLIM64_INFINITY
#define __NEED_RUSAGE
#define __NEED_RLIMIT
#define __NEED_RLIMIT64

#include <_platform.h>
#if __has_include(__target_os_arch_header(resource.h))
#include __target_os_arch_header(resource.h)
#endif

// these shouldn't vary
#ifdef __NEED_PRIO_CONSTS
#define PRIO_PROCESS    0
#define PRIO_PGRP       1
#define PRIO_USER       2
#endif

// these shouldn't vary
#ifdef __NEED_RUSAGE_CONSTS
#define RUSAGE_SELF     0
#define RUSAGE_CHILDREN (-1)
#endif

// these can vary by architecture
#ifdef __NEED_RLIMIT_CONSTS
#define RLIMIT_AS       9
#define RLIMIT_CORE     4
#define RLIMIT_CPU      0
#define RLIMIT_DATA     2
#define RLIMIT_FSIZE    1
#define RLIMIT_NOFILE   7
#define RLIMIT_STACK    3
#endif

#include <bits/linux/types.h>
#include <bits/linux/time.h>
#include <sys/types.h>
#include <sys/resource.h>

#ifdef __NEED_RLIM_INFINITY
#define __KERNEL_RLIM_INFINITY (~0ul)
#endif
#ifdef __NEED_RLIM64_INFINITY
#define __KERNEL_RLIM64_INFINITY (~0ull)
#endif

// this shouldn't vary
#ifdef __NEED_RUSAGE
struct __kernel_rusage {
    struct __kernel_old_timeval ru_utime;
    struct __kernel_old_timeval ru_stime;
    __kernel_long_t ru_maxrss;
    __kernel_long_t ru_ixrss;
    __kernel_long_t ru_idrss;
    __kernel_long_t ru_isrss;
    __kernel_long_t ru_minflt;
    __kernel_long_t ru_majflt;
    __kernel_long_t ru_nswap;
    __kernel_long_t ru_inblock;
    __kernel_long_t ru_oublock;
    __kernel_long_t ru_msgsnd;
    __kernel_long_t ru_msgrcv;
    __kernel_long_t ru_nsignals;
    __kernel_long_t ru_nvcsw;
    __kernel_long_t ru_nivcsw;
};
#endif

// platform-sized ulimit structure; used by get-/setrlimit; this shouldn't vary
#ifdef __NEED_RLIMIT
struct __kernel_rlimit {
    __kernel_ulong_t rlim_cur;
    __kernel_ulong_t rlim_max;
};
#endif

// always 64-bit rlimit structure; used by prlimit64; this shouldn't vary
#ifdef __NEED_RLIMIT64
struct __kernel_rlimit64 {
    unsigned long long rlim_cur;
    unsigned long long rlim_max;
};
#endif

// prlimit64 is linux-specific, so it doesn't go in sys/resource.h
int __prlimit64(pid_t, int, const struct rlimit*, struct rlimit*);
void __copy_rusage(struct __kernel_rusage*, struct rusage*);

#endif // _LINUX_RESOURCE_H
