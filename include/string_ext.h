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

#ifndef _STRING_EXT_H
#define _STRING_EXT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* FIXME: these are defined here too in order to make them available because we
 * can't include the headers that actually define them? */
typedef int errno_t;
typedef size_t rsize_t;

/* NON-POSIX FUNCTION PROTOTYPES **********************************************/

// FIXME: PDClib has memchr, copy and adjust to memrchr
// void *memrchr(const void *, int, size_t);

/* POSIX FUNCTION PROTOTYPES **************************************************/

errno_t memset_s(void *, rsize_t, int, rsize_t);
char *strchrnul(const char *, int);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
char *strdup(const char *);
char *strndup(const char *, size_t);
size_t strnlen(const char *, size_t);
char *strsep(char **, const char *);

/* FIXME: the following functions are currently not implemented:
 *
 *   - void *memccpy(void *restrict, const void *restrict, int, size_t);
 *   - int strcoll_l(const char *, const char *, locale_t);
 *   - char *strerror_l(int, locale_t);
 *   - int strerror_r(int, char *, size_t);
 *   - char *strsignal(int);
 *   - char *strtok_r(char *restrict, const char *restrict, char **restrict);
 *   - size_t strxfrm_l(char *restrict, const char *restrict, size_t, locale_t);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _STRING_EXT_H
