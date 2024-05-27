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

#ifndef _POLYGLOT_COUNT_ARGS_H
#define _POLYGLOT_COUNT_ARGS_H 1

#define COUNT_ARGS(...)     COUNT_ARGS_(ign, ##__VA_ARGS__, COUNT_RSEQ())
#define COUNT_ARGS_(...)    COUNT_ARGS__(__VA_ARGS__)
#define COUNT_ARGS__(       ign,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,\
                            _14,_15,_16,_17,_18_,_19,_20,_21,_22,_23,_24,_25,\
                            _26,_27,_28,_29,_30,_31,N,...) N
#define COUNT_RSEQ()        31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,\
                            15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#endif // _POLYGLOT_COUNT_ARGS_H
