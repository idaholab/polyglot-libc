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

#ifndef _STDLIB_EXT_H
#define _STDLIB_EXT_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION PROTOTYPES ********************************************************/

int clearenv(void);
int grantpt(int);
int posix_openpt(int);
char *ptsname(int);
int putenv(char *);
char *realpath(const char *restrict, char *restrict);
int setenv(const char *, const char *, int);
char *realpath(const char*, char*);
int unlockpt(int);
int unsetenv(const char *);

/* FIXME: the following functions are currently not implemented:
 *
 *   - long a64l(const char *);
 *   - double drand48(void);
 *   - double erand48(unsigned short [3]);
 *   - int getsubopt(char **, char *const *, char **);
 *   - char *initstate(unsigned, char *, size_t);
 *   - long jrand48(unsigned short [3]);
 *   - char *l64a(long);
 *   - void lcong48(unsigned short [7]);
 *   - long lrand48(void);
 *   - char *mkdtemp(char *);
 *   - long mrand48(void);
 *   - long nrand48(unsigned short [3]);
 *   - int posix_memalign(void **, size_t, size_t);
 *   - int rand_r(unsigned *);
 *   - long random(void);
 *   - unsigned short *seed48(unsigned short [3]);
 *   - void setkey(const char *);
 *   - char *setstate(char *);
 *   - void srand48(long);
 *   - void srandom(unsigned);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _STDLIB_EXT_H
