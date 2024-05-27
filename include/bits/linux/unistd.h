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

#ifndef _LINUX_UNISTD_H
#define _LINUX_UNISTD_H _LINUX_UNISTD_H

#include <sys/types.h>

int ___llseek(int, off_t, off_t*, unsigned int);
int __dup3(int, int, int);
off_t __lseek(int, long, unsigned int);
int __pipe2(int*, int);
int __setresgid(gid_t, gid_t, gid_t);
int __setresuid(uid_t, uid_t, uid_t);

#endif // _LINUX_UNISTD_H
