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

#include <bits/linux/shim.h>
#include <bits/linux/features.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#if defined(HAS_fstatat)

int __faccessat_via_fstatat(int fd, const char* path, int mode, int flag)
{
    struct stat st;
    uid_t uid;
    gid_t gid;
    mode_t fm;
    int uid_ok, gid_ok;

    // ensure mode is valid
    if (mode & ~S_IRWXO) {
        errno = EINVAL;
        return -1;
    }

    // stat the file; this gets us what we need to check for access
    if (fstatat(fd, path, &st, flag & ~AT_EACCESS) == -1)
        return -1;

    // if we're only checking if it exists, bail now
    if (mode == F_OK)
        return 0;

    // okay, we need to check for permissions, who should we be? if we should be
    // using effective-ids, get them, otherwise get real-ids
    if (flag & AT_EACCESS) {
        uid = geteuid();
        gid = getegid();
    } else {
        uid = getuid();
        gid = getgid();
    }
    // check whether our ids match the file at all
    uid_ok = (st.st_uid == uid);
    gid_ok = (st.st_gid == gid);
    // pull this out... probably gets optimized dthis way anyway? but shorter
    fm = st.st_mode;

    // this is awful, but we kinda have to do it in one shot, or it turns into a
    // horrific mess of nested if blocks... essentially, for each of the modes,
    // the logic is something like:
    //      check_mode? -> (oth? || (uid_ok && usr?) || (gid_ok && grp?)
    if ((!(mode & X_OK)
            || (          (fm & S_IXOTH))
            || (uid_ok && (fm & S_IXUSR))
            || (gid_ok && (fm & S_IXGRP))) &&
        (!(mode & W_OK)
            || (          (fm & S_IWOTH))
            || (uid_ok && (fm & S_IWUSR))
            || (gid_ok && (fm & S_IWGRP))) &&
        (!(mode & R_OK)
            || (          (fm & S_IROTH))
            || (uid_ok && (fm & S_IRUSR))
            || (gid_ok && (fm & S_IRGRP))))
        return 0;
    // nope, we don't have access
    errno = EACCES;
    return -1;
}

#endif
