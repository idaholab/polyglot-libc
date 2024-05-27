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
#include <bits/linux/times.h>
#include <sys/times.h>

#ifdef __NR_times

clock_t __sys_times(struct tms *tp)
{
    int result;
    struct __kernel_tms k_tp;

    if ((result = syscall(__NR_times, &k_tp)) == -1)
        return -1;

    tp->tms_utime = k_tp.tms_utime;
    tp->tms_stime = k_tp.tms_stime;
    tp->tms_cutime = k_tp.tms_cutime;
    tp->tms_cstime = k_tp.tms_cstime;
    return result;
}

#endif
