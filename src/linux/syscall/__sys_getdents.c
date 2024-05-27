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
#include <bits/linux/dirent.h>
#include <polyglot/dirent.h>
#include <stddef.h>
#include <errno.h>


#if defined(__NR_getdents)

#define k_dent ((struct __kernel_dirent *)(dir->k_ptr))

int __sys_getdents(struct __polyglot_dir *dir)
{
    /* if we don't have any data, we need to get some */
    if (dir->size <= 0) {
read_data:
        /* try to do the syscall to read some data */
        errno = 0;
        dir->size = syscall(
            __NR_getdents,
            dir->fd, dir->buf, sizeof(dir->buf)
        );

        /* check if we succeeded, but got no data */
        if (dir->size == 0)
            return 0;
        /* check if we outright failed */
        else if (dir->size == -1)
            return -1;

        /* reset our pointer to the right spot */
        dir->k_ptr = dir->buf;

    /* we have some data, try to use what we have */
    } else {
        /* progress the pointer to the next member */
        dir->k_ptr += k_dent->d_reclen;

        /* if we exceeded our buffer, we go and read more data */
        if (dir->k_ptr >= dir->buf + dir->size)
            goto read_data;
    }

    /* copy fields from the kernel struct to the userspace one */
    dir->dent.d_ino = k_dent->d_ino;
    dir->dent.d_name = k_dent->d_name;
    dir->dent.d_type = DT_UNKNOWN;
    dir->off = k_dent->d_off;

    /* return success */
    return 1;
}

#endif // __NR_getdents
