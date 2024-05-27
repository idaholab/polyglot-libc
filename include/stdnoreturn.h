/* This file is part of the Polyglot C Library. It originates from the Public
   Domain C Library (PDCLib).

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

/* _Noreturn <stdnoreturn.h> */

#ifndef _PDCLIB_STDNORETURN_H
#define _PDCLIB_STDNORETURN_H _PDCLIB_STDNORETURN_H

#include "pdclib/_PDCLIB_int.h"

/* This basically breaks the letter of the standard (which states that
   noreturn be defined to _Noreturn). This defines noreturn -> _Noreturn
   on C11 compliant compilers only (as older compilers do not know about
   _Noreturn).
*/
#define noreturn _PDCLIB_Noreturn

/* Extension hook for downstream projects that want to have non-standard
   extensions to standard headers.
*/
#ifdef _PDCLIB_EXTEND_STDNORETURN_H
#include _PDCLIB_EXTEND_STDNORETURN_H
#endif

#endif
