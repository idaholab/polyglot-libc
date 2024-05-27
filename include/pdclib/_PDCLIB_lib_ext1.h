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

/* __STDC_WANT_LIB_EXT1__ redefinition guard */

#ifndef __STDC_WANT_LIB_EXT1__
  #ifdef __STDC_WANT_LIB_EXT1_PREVIOUS__
    #if __STDC_WANT_LIB_EXT1_PREVIOUS__ != -1
      #error __STDC_WANT_LIB_EXT1__ undefined when it was defined earlier.
    #endif
  #else
    #define __STDC_WANT_LIB_EXT1_PREVIOUS__ -1
  #endif
#else
  #if ( __STDC_WANT_LIB_EXT1__ + 0 ) == 0 && ( 0 - __STDC_WANT_LIB_EXT1__ - 1 ) == 1
    #error __STDC_WANT_LIB_EXT1__ defined but empty. Should be an integer value.
  #endif
  #ifdef __STDC_WANT_LIB_EXT1_PREVIOUS__
    #if ( __STDC_WANT_LIB_EXT1__ + 0 ) != __STDC_WANT_LIB_EXT1_PREVIOUS__
      #error __STDC_WANT_LIB_EXT1__ redefined from previous value.
    #endif
  #else
    #if ( __STDC_WANT_LIB_EXT1__ + 0 ) == 0
      #define __STDC_WANT_LIB_EXT1_PREVIOUS__ 0
    #elif ( __STDC_WANT_LIB_EXT1__ + 0 ) == 1
      #define __STDC_WANT_LIB_EXT1_PREVIOUS__ 1
    #else
      #error __STDC_WANT_LIB_EXT1__ set to value other than 0,1 -- undefined behavior
    #endif
  #endif
#endif
