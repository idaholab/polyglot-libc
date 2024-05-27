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

#if !defined(_STRINGS_H)
#define _STRINGS_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* EXTERNAL TYPE DEFINITIONS **************************************************/

#include <sys/types.h>

/* TYPE DEFINITIONS ***********************************************************/

/* FIXME: locale_t isn't defined here! */

/* NON-POSIX FUNCTION PROTOTYPES **********************************************/

void bzero(void *, size_t);

/* POSIX FUNCTION PROTOTYPES **************************************************/

int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int ffs(int);
 *   - int strcasecmp_l(const char *, const char *, locale_t);
 *   - int strncasecmp_l(const char *, const char *, size_t, locale_t);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _STRINGS_H
