/* Return the canonical absolute name of a given file.

   This file is part of the Polyglot C Library. It is a modification of a file
   from the GNU C Library (stdlib/canonicalize.c).

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED
   Copyright (C) 1996-2024 Free Software Foundation, Inc.

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

/* CHANGES: This file has been reworked from upstream to remove extraneous bits
        that are either not supported or extraneous due to the limited scope of
        Polyglot vs. glibc. In general, it's also been modified to fit within
        the Polyglot C Library's infrastructure. */

#include <errno.h>
#include <alloca.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <target/limits.h>

/* Return the canonical absolute name of file NAME.  A canonical name
   does not contain any `.', `..' components nor any repeated path
   separators ('/') or symlinks.  All path components must exist.  If
   RESOLVED is null, the result is malloc'd; otherwise, if the
   canonical name is PATH_MAX chars or more, returns null with `errno'
   set to ENAMETOOLONG; if the name fits in fewer than PATH_MAX chars,
   returns the name in RESOLVED.  If the name cannot be resolved and
   RESOLVED is non-NULL, it contains the path of the first component
   that cannot be resolved.  If the path can be resolved, RESOLVED
   holds the same value as the value returned.  */

char *realpath(const char *name, char *resolved)
{
    char *rpath, *dest, *extra_buf = NULL;
    const char *start, *end, *rpath_limit;
    int num_links = 0, n;
    struct stat64 st;

    // Handle initial error conditions.
    if (name == NULL) {
        errno = EINVAL;
        return NULL;
    }
    if (name[0] == 0) {
        errno = ENOENT;
        return NULL;
    }

    // Allocate a buffer for our result if we need to.
    if (resolved == NULL) {
        rpath = malloc(PATH_MAX);
        if (rpath == NULL)
            return NULL;
    } else {
        rpath = resolved;
    }
    rpath_limit = rpath + PATH_MAX;

    // Figure out where we start putting things in the output path.
    if (name[0] != '/') {
        if (!getcwd(rpath, PATH_MAX)) {
            rpath[0] = 0;
            goto error;
        }
        dest = memchr(rpath, 0, PATH_MAX);
    } else {
        rpath[0] = '/';
        dest = rpath + 1;
    }

    for (start = end = name; *start; start = end) {
        /* Skip sequence of multiple path-separators.  */
        while (*start == '/') {
            ++start;
        }

        /* Find end of path component.  */
        for (end = start; *end && *end != '/'; ++end) {
            /* Nothing.  */;
        }

        if (end - start == 0) {
            break;
        } else if (end - start == 1 && start[0] == '.') {
            /* nothing */;
        } else if (end - start == 2 && start[0] == '.' && start[1] == '.') {
            /* Back up to previous component, ignore if at root already.  */
            if (dest > rpath + 1) {
                while ((--dest)[-1] != '/');
            }
        } else {
            size_t new_size;

            if (dest[-1] != '/') {
                *dest++ = '/';
            }

            if (dest + (end - start) >= rpath_limit) {
                ptrdiff_t dest_offset = dest - rpath;
                char *new_rpath;

                if (resolved) {
                    errno = ENAMETOOLONG;
                    if (dest > rpath + 1) {
                        dest--;
                    }
                    *dest = '\0';
                    goto error;
                }
                new_size = rpath_limit - rpath;
                if (end - start + 1 > PATH_MAX) {
                    new_size += end - start + 1;
                } else {
                    new_size += PATH_MAX;
                }
                new_rpath = (char *)realloc(rpath, new_size);
                if (new_rpath == NULL) {
                    goto error;
                }
                rpath = new_rpath;
                rpath_limit = rpath + new_size;

                dest = rpath + dest_offset;
            }

            dest = memcpy(dest, start, end - start) + (end - start);
            *dest = '\0';

            if (lstat64(rpath, &st) < 0) {
                goto error;
            }

            if (S_ISLNK(st.st_mode)) {
                char *buf = alloca(PATH_MAX);
                size_t len;

                if (++num_links > ELOOP_MAX) {
                    errno = ELOOP;
                    goto error;
                }

                n = readlink(rpath, buf, PATH_MAX - 1);
                if (n < 0) {
                    goto error;
                }
                buf[n] = '\0';

                if (!extra_buf) {
                    extra_buf = alloca(PATH_MAX);
                }

                len = strlen(end);
                if (PATH_MAX - n <= len) {
                    errno = ENAMETOOLONG;
                    goto error;
                }

                /* Careful here, end may be a pointer into extra_buf... */
                memmove(&extra_buf[n], end, len + 1);
                name = end = memcpy(extra_buf, buf, n);

                if (buf[0] == '/') {
                    dest = rpath + 1; /* It's an absolute symlink */
                } else {
                    /* Back up to previous component, ignore if at root already */
                    if (dest > rpath + 1) {
                        while ((--dest)[-1] != '/');
                    }
                }
            } else if (!S_ISDIR(st.st_mode) && *end != '\0') {
                errno = ENOTDIR;
                goto error;
            }
        }
    }
    if (dest > rpath + 1 && dest[-1] == '/') {
        --dest;
    }
    *dest = '\0';
    
    return rpath;
    
error:
    if (resolved == NULL)
        free (rpath);
    return NULL;
}

