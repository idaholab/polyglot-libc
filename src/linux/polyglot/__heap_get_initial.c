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


/* XXX: because of the nature of brk(), we are not calling our brk() function
 * here, but are expecting that every Linux target architecture has a __NR_brk
 * defined; if this is not the case in the future, reconsider this. */


void *__heap_get_initial()
{
#ifdef __NR_brk
    /* Linux returns the current break if you call brk() with NULL; we use this
     * in order to find our heap because ASLR moves it around. From testing,
     * this works even on pre-ASLR Linux kernels. */
    return (void*)syscall(__NR_brk, 0);
#else
#error "No __NR_brk defined for this architecture!"
#endif
}


