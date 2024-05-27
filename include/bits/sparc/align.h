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

#ifndef _SPARC_ALIGN_H
#define _SPARC_ALIGN_H _SPARC_ALIGN_H

/* XXX: technically SPARC ints/pointers need to be 4-byte aligned, but 64-bit
 * integers need to be 8-byte aligned, so all dynamically allocated memory needs
 * to be on an 8-byte alignment to make sure there aren't bus errors */
#define POINTER_ALIGNMENT 8

#endif // _SPARC_ALIGN_H
