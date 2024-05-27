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

#if !defined(_SETJMP_H)
#define _SETJMP_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* PLATFORM-SPECIFIC DEFINITIONS **********************************************/

#include <target/setjmp.h>

/* TYPE DEFINITIONS ***********************************************************/

typedef jmp_buf sigjmp_buf;

/* FUNCTION PROTOTYPES ********************************************************/

int _setjmp(jmp_buf) __attribute__((returns_twice));
int setjmp(jmp_buf) __attribute__((returns_twice));
int sigsetjmp(sigjmp_buf, int) __attribute__((returns_twice));

void _longjmp(jmp_buf, int) __attribute__((noreturn));
void longjmp(jmp_buf, int) __attribute__((noreturn));
void siglongjmp(sigjmp_buf, int) __attribute__((noreturn));

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SETJMP_H
