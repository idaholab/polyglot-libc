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

#include <sys/resource.h>

void __copy_rusage(struct __kernel_rusage *src, struct rusage *dest)
{
    dest->ru_utime.tv_sec = src->ru_utime.tv_sec;
    dest->ru_utime.tv_usec = src->ru_utime.tv_usec;
    dest->ru_maxrss = src->ru_maxrss;
    dest->ru_ixrss = src->ru_ixrss;
    dest->ru_idrss = src->ru_idrss;
    dest->ru_isrss = src->ru_isrss;
    dest->ru_minflt = src->ru_minflt;
    dest->ru_majflt = src->ru_majflt;
    dest->ru_nswap = src->ru_nswap;
    dest->ru_inblock = src->ru_inblock;
    dest->ru_oublock = src->ru_oublock;
    dest->ru_msgsnd = src->ru_msgsnd;
    dest->ru_msgrcv = src->ru_msgrcv;
    dest->ru_nsignals = src->ru_nsignals;
    dest->ru_nvcsw = src->ru_nvcsw;
    dest->ru_nivcsw = src->ru_nivcsw;
}

