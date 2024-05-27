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
#include <stddef.h>
#include <unistd.h>
#include <errno.h>


#if defined(__NR_readdir)

/* XXX: Okay, so readdir() is a complicated syscall and really differs from the
 * newer versions. On old enough systems, it doesn't matter what you pass in for
 * the size field: you always get one record back.  On these systems, the return
 * is the size of the name field. On newer systems that support readdir(), the
 * size field should either be 1 (return a single entry) or the size of the
 * buffer (fill the buffer with entries); the return value in this case is the
 * number of bytes used in the output buffer. Importantly, there is no d_off
 * field in the old directory entry structure, so if you return a block of
 * records, you can't actually know what the offset in the directory is at any
 * point; otherwise you can use lseek(<fd>, 0, SEEK_CUR) to get the current
 * offset. Also the structure seems to have inconsistencies in the kernel
 * headers, depending on platform, so we can only use some of the fields... */

#define k_odent ((struct __kernel_old_dirent *)(dir->k_ptr))

int __sys_readdir(struct __polyglot_dir *dir)
{
    /* if we don't have any data, we need to get some */
    if (dir->size <= 0) {
read_data:
        /* try to do the syscall to read some data */
        errno = 0;
        dir->size = syscall(
            __NR_readdir,
            dir->fd, dir->buf, 1
        );

        /* check if we succeeded, but got no data */
        if (dir->size == 0)
            return 0;
        /* check if we outright failed */
        else if (dir->size == -1)
            return -1;

        /* reset our pointer to the right spot */
        dir->k_ptr = dir->buf;

    /* we have some data, but... */
    } else {
        /* ...we only have one record, so read more */
        goto read_data;
    }

    /* copy fields from the kernel struct to the userspace one */
    dir->dent.d_ino = k_odent->d_ino;
    dir->dent.d_name = k_odent->d_name;
    dir->dent.d_type = DT_UNKNOWN;

    /* we have to use lseek() to get the offset (see above) */
    dir->off = lseek(dir->fd, 0, SEEK_CUR);

    /* return success */
    return 1;
}

#endif // __NR_readdir
