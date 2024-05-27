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

#include <polyglot/syscall_choice.h>
#include <bits/linux/syscall.h>
#include <bits/linux/shim.h>
#include <bits/linux/features.h>
#include <unistd.h>

int faccessat(int fd, const char* path, int mode, int flag);

/* XXX: so this is implemented a little differently than we do most, but that's
 * because we -aren't- using access() to handle the non-faccessat() case--we
 * could, but tbh, it ends up being pretty awful to try to implement with things
 * like AT_EACCESS and keep our sanity... */
/* XXX: faccessat() is also a bit weird under the hood because Linux had a nasty
 * implementation of SYS_faccessat that wasn't to the POSIX spec (missing flags)
 * and only added a compatible one (SYS_faccessat2) in the 5.x series kernel */

syscall_choice(
    // syscall (name, signature, failure)
    faccessat,
    int, ( int,         fd,
           const char*, path,
           int,         mode,
           int,         flag ),
    -1,

    // options (name, function)
#if defined(HAS_NATIVE_faccessat)
# if defined(__NR_faccessat2)
    FACCESSAT2, __sys_faccessat2,
# endif
# if defined(__NR_faccessat)
    FACCESSAT, __sys_faccessat,
# endif
#endif
#if (  defined(HAS_fstatat) \
    && defined(HAS_geteuid) \
    && defined(HAS_getegid))
    FSTATAT, __faccessat_via_fstatat,
#endif
)

