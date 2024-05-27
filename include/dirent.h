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

#if !defined(_DIRENT_H)
#define _DIRENT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>

/* TYPE DEFINITIONS ***********************************************************/

#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 3
#define DT_BLK 4
#define DT_REG 5
#define DT_LNK 6
#define DT_SOCK 7
#define DT_WHT 8

/* This is defined here as being an opaque pointer type that is (under the hood)
 * actually a pointer to an OS-implementation-defined structure containing the
 * directory stream information. */
typedef void DIR;

struct dirent
{
    ino_t d_ino;
    /* This differs from POSIX slightly; these should behave as expected, but to
     * minimize the overhead of this structure (and rely on the underlying OS
     * implementation more), we just point to the current entry's name instead
     * of copying it into a local buffer here. (This also avoids NAME_MAX.) */
    char *d_name;
    int d_type;
};

/* FUNCTION PROTOTYPES ********************************************************/

int closedir(DIR *);
int dirfd(DIR *);
DIR *opendir(const char *);
struct dirent *readdir(DIR *);
void rewinddir(DIR *);
void seekdir(DIR *, long);
long telldir(DIR *);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int alphasort(const struct dirent **, const struct dirent **);
 *   - DIR *fdopendir(int);
 *   - int readdir_r(DIR *restrict, struct dirent *restrict,
 *          struct dirent **restrict);
 *   - int scandir(const char *, struct dirent ***,
 *          int (*)(const struct dirent *), int (*)(const struct dirent **,
 *          const struct dirent **));
 */

#ifdef __cplusplus
} // extern C
#endif

#endif // _DIRENT_H
