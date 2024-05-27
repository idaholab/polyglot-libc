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

#ifndef _LINUX_MIPS64_SYSCALL_H
#define _LINUX_MIPS64_SYSCALL_H _LINUX_MIPS64_SYSCALL_H

#include <_platform.h>
#if __has_include(__target_abi_syscall_header)
#include __target_abi_syscall_header
#else
#error "Unknown Linux/MIPS64 syscall ABI!"
#endif

#if !defined(__ASSEMBLER__) && !defined(__target_featuredef)

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/comparison/less.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <polyglot/count_args.h>

long __syscall(long, long, long, long, long, long, long);
long __syscall_pipe(int[2]);

/* this is a simple way of casting all the arguments passed to a syscall to
 * long, without needing to define the function as taking longs */
#define __LONG(z,n,t)   ((long)(BOOST_PP_TUPLE_ELEM(n, t))) \
                            BOOST_PP_COMMA_IF(BOOST_PP_LESS( \
                                n, BOOST_PP_SUB(BOOST_PP_TUPLE_SIZE(t), 1) \
                            ))
#define ___SC_ARGS(t)   BOOST_PP_REPEAT(BOOST_PP_TUPLE_SIZE(t), __LONG, t)
#define __SC_ARGS(...)  ___SC_ARGS( \
                            BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__) \
                        )

#define __syscall1(n,...)   __syscall((n), 0l, 0l, 0l, 0l, 0l, 0l)
#define __syscall2(n,...)   __syscall((n), __SC_ARGS(__VA_ARGS__), 0l, 0l, 0l, 0l, 0l)
#define __syscall3(n,...)   __syscall((n), __SC_ARGS(__VA_ARGS__), 0l, 0l, 0l, 0l)
#define __syscall4(n,...)   __syscall((n), __SC_ARGS(__VA_ARGS__), 0l, 0l, 0l)
#define __syscall5(n,...)   __syscall((n), __SC_ARGS(__VA_ARGS__), 0l, 0l)
#define __syscall6(n,...)   __syscall((n), __SC_ARGS(__VA_ARGS__), 0l)
#define __syscall7(n,...)   __syscall((n), __SC_ARGS(__VA_ARGS__))

#define syscall_(N,...)     BOOST_PP_CAT(__syscall, N)(__VA_ARGS__)
#define syscall(...)        syscall_(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)

#endif // !__ASSEMBLER__ && !__target_featuredef

#endif // _LINUX_MIPS64_SYSCALL_H
