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

#include <stddef.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>


#define PATHLEN 1024

/* XXX: Implementation detail: on sufficiently old versions of OSes, there is no
 * getcwd syscall, and we have to essentially do it ourselves by walking up the
 * tree until we find the root. This has some interesting side effects, namely
 * that we will generate the "real" path (in the case of symlinks, we will find
 * a path that doesn't contain any symlinks). */


char *__getcwd_generic(char *buf, size_t size)
{
    ino_t root_ino;
    char path[PATHLEN], *p = path;
    DIR *d = NULL;
    struct dirent *dent;
    struct stat stbuf;
    int match;
    size_t work, i;

    bzero(path, PATHLEN);
    work = size - 1;
    buf[size - 1] = 0;

    // Get the root inode (root of the tree/walk)
    if (stat("/", &stbuf) < 0) {
        goto error;
    }
    root_ino = stbuf.st_ino;

    // Set our starting path to be '.'
    p = stpncpy(p, ".", 1);

    while (1) {
        // Get the inode of the current level
        if (stat(path, &stbuf) < 0) {
            goto error;
        }

        if (stbuf.st_ino == root_ino) {
            break;
        }

        // Walk up the tree a level (append '/..' to our path)
        // FIXME: I'm not sure if this range-checking works right
        if (p + 3 >= path + PATHLEN - 1) {
            errno = ERANGE;
            goto error;
        }
        p = stpncpy(p, "/..", 3);

        // Open the parent directory
        if ((d = opendir(path)) == NULL) {
            goto error;
        }

        // Iterate through the parent directory
        match = 0;
        while ((dent = readdir(d)) != NULL) {
            if ((dent->d_name[0] == '.') && ((dent->d_name[1] == 0) ||
                    ((dent->d_name[1] == '.') && (dent->d_name[2] == 0))))
                continue;
            if (dent->d_ino == stbuf.st_ino) {
                match = 1;
                i = strlen(dent->d_name);

                if (i + 1 > work) {
                    errno = ERANGE;
                    goto error;
                }

                // Copy the found path segment into the buffer
                memcpy(buf + (work - i), dent->d_name, i);
                work -= i;
                buf[work - 1] = '/';
                work -= 1;

                break;
            }
        }
        if (errno) {
            goto error;
        } else if (!match) {
            errno = ENOENT;
            goto error;
        }

        // Close the parent directory
        if (closedir(d) < 0) {
            d = NULL;
            goto error;
        }
        d = NULL;
    }

    // Move the string if we didn't fill the buffer entirely
    if (work > 0) {
        for (i = 0; i < size - work; ++i) {
            buf[i] = buf[work + i];
        }
    }
    buf[work + i] = 0;

    return buf;

error:
    if (d) {
        closedir(d);
    }
    return NULL;
}


