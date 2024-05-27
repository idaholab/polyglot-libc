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

#ifndef _POLYGLOT_SYSCALL_CHOICE_H
#define _POLYGLOT_SYSCALL_CHOICE_H 1

#include <stddef.h>
#include <errno.h>

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/arithmetic/mul.hpp>
#include <boost/preprocessor/arithmetic/div.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/logical/and.hpp>
#include <polyglot/cpp_common.h>

//#define debug_text_section ".polyglot.debug.text"
//#define debug_data_section ".polyglot.debug.data"
//#define debug_preinit_section ".polyglot.debug.preinit_array"
#define debug_text_section ".text"
#define debug_data_section ".data"
#define debug_preinit_section ".preinit_array"


#if 0
/* linked list entry for syscalls with choices */
struct __choice_info
{
    struct __choice_info *next;
    const char *name;
    int *choice;
    const char *options[];
};

/* this is the linked list the preinit functions defined by choice_register
 * below build; it contains one entry per syscall */
extern struct __choice_info *__choice_info_head;
extern struct __choice_info *__choice_info_tail;

/* a function that handles appending the linked list entry */
void __choice_append(struct __choice_info*);
#endif

/* the function we use for initializing our syscall debugging interface; it
 * reads the linked list of syscalls and parses the POLYGLOT_SYSCALL env var to
 * pre-seed choices */
void __syscall_debug_init();

/* define a function for a syscall that find the first option in the set
 * provided that successfully returns in this run; this allows us to provide a
 * number of options that might work for a platform and lt it decide at runtime
 * which is the right one (and remember the choice going forward so that future
 * calls don't need to triage); this is the outer wrapper only converts our
 * varargs into a tuple, then passes everything off to the actual logic */
#define syscall_choice(name, rettype, args, fail, ...) \
    __syscall_choice( \
        name, rettype, args, fail, \
        BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__) \
    )
/* branch to the various sub-cases based on whether there are 0, 1, or many
 * options; this doesn't do any further conversion of arguments */
//#define test_macro(x, y) BOOST_PP_NOT_EQUAL_ ## x(0, BOOST_PP_NOT_EQUAL_ ## y)
#define __syscall_choice(name, rettype, args, fail, tup) \
    BOOST_PP_IF( \
        BOOST_PP_EQUAL(__choice_pair_count(tup), 0), \
        __choice_0, \
        BOOST_PP_IF( \
            BOOST_PP_EQUAL(__choice_pair_count(tup), 1), \
            __choice_1, \
            __choice_n \
        ) \
    )(name, rettype, args, fail, tup)

/* count the number of pairs in a tuple, rounding down */
#define __choice_pair_count(tup) \
    BOOST_PP_DIV(BOOST_PP_TUPLE_SIZE(tup), 2)
/* get the left element of the nth pair in a tuple */
#define __choice_pair_get_left(n, tup) \
    BOOST_PP_TUPLE_ELEM(BOOST_PP_MUL(n, 2), tup)
/* get the right element of the nth pair in a tuple */
#define __choice_pair_get_right(n, tup) \
    BOOST_PP_TUPLE_ELEM(BOOST_PP_ADD(BOOST_PP_MUL(n, 2), 1), tup)
/* output a comma if n is not the final pair index in the tuple */
#define __choice_pair_comma_if(n, tup) \
    BOOST_PP_COMMA_IF(BOOST_PP_NOT_EQUAL( \
        BOOST_PP_SUB(__choice_pair_count(tup), 1), n \
    ))

/* support macros for consistent definitions of variable/structure names */
#define __choice_register(n)        BOOST_PP_CAT(_register_info_, n)
#define __choice_preinit(n)         BOOST_PP_CAT(_preinit_info_, n)
#define __choice_var(n)             BOOST_PP_CAT(_choice_, n)
#define __choice_info(n)            BOOST_PP_CAT(_info_, n)
#define __choice_enum(n)            BOOST_PP_CAT(_enum_, n)
#define __choice_option(s,n)        BOOST_PP_CAT(BOOST_PP_CAT(s, _), n)

/* given a tuple of syscall options, generate enum names */
#define __choice_enum_values(name, tup) \
    BOOST_PP_REPEAT( \
        __choice_pair_count(tup), \
        __choice_enum_value, \
        BOOST_PP_VARIADIC_TO_TUPLE(name, tup) \
    )
#define __choice_enum_value(z, n, tup) \
    __choice_option( \
        BOOST_PP_TUPLE_ELEM(0, tup), \
        __choice_pair_get_left(n, BOOST_PP_TUPLE_ELEM(1, tup)) \
    ) \
    BOOST_PP_COMMA()
/* given a tuple of syscall options, generate string versions of the options */
#define __choice_option_values(name, tup) \
    BOOST_PP_REPEAT( \
        __choice_pair_count(tup), \
        __choice_option_value, \
        tup \
    )
#define __choice_option_value(z, n, tup) \
    BOOST_PP_STRINGIZE( \
        __choice_pair_get_left(n, tup) \
    ) \
    BOOST_PP_COMMA()
/* extract names from a fully comma-delimited list of arguments */
#define __choice_arg_names(tup) \
    BOOST_PP_REPEAT(__choice_pair_count(tup), __choice_arg_name, tup)
#define __choice_arg_name(z, n, tup) \
    __choice_pair_get_right(n, tup) \
    __choice_pair_comma_if(n, tup)
/* convert comma-delimited list of arguments to a real argument set */
#define __choice_fix_args(tup) \
    BOOST_PP_REPEAT(__choice_pair_count(tup), __choice_fix_arg, tup)
#define __choice_fix_arg(z, n, tup) \
    __choice_pair_get_left(n, tup) __choice_pair_get_right(n, tup) \
    __choice_pair_comma_if(n, tup)

/* check if an option tuple has a final NONE option, expands to 0/1; this is
 * sort of a hackish solution, but since we can't rely on BOOST_PP_CHECK_EMPTY,
 * this serves as a solution; because the concatted-NONE-option expands to a
 * comma, the variadic has two elements, otherwise it only has one */
#define __choice_has_final_none(tup) \
    BOOST_PP_EQUAL( \
        2, \
        BOOST_PP_VARIADIC_SIZE( \
            BOOST_PP_CAT( \
                __choice_equals_, \
                __choice_pair_get_left( \
                    BOOST_PP_SUB(__choice_pair_count(tup), 1), \
                    tup \
                ) \
            )() \
        ) \
    )
#define __choice_equals_NONE() \
    BOOST_PP_COMMA()

/* the base case: no options were provided, warn and just short-circuit to
 * raise ENOSYS and return a failure */
#define __choice_0(name, rettype, args, fail, tup) \
    WARNING(syscall #name has zero choices) \
    rettype name(__choice_fix_args(args)) \
    { \
        errno = ENOSYS; \
        return fail; \
    }

/* the one case: we were given one option, so just call that */
#define __choice_1(name, rettype, args, fail, tup) \
    rettype name(__choice_fix_args(args)) \
    { \
        return __choice_pair_get_right(0, tup)(__choice_arg_names(args)); \
    }

/* the N case: we were given 2+ options, so define machinery that handles
 * figuring out which is the "right" one for the current run, and remembering
 * that choice so future calls don't have to guess */
#define __choice_n(name, rettype, args, fail, tup) \
    /* define an enum of the possible choices for this syscall */ \
    enum __choice_enum(name) { \
        __choice_option(name, UNKNOWN), \
        __choice_enum_values(name, tup) \
        BOOST_PP_IF( \
            __choice_has_final_none(tup), \
            BOOST_PP_EMPTY, \
            BOOST_PP_IDENTITY(__choice_option(name, NONE)) \
        )() \
    }; \
    /* create persistent storage for our choice; this can't go into the debug \
     * sections because it gets used from the non-debug code */ \
    static int __choice_var(name) = __choice_option(name, UNKNOWN); \
    /* instantiate the choice info struct for this syscall, and put it in the \
     * debug data section so it can be discarded if necessary */ \
    /*__attribute__((section(debug_data_section), used)) \
    static struct __choice_info __choice_info(name) = { \
        NULL, \
        #name, \
        &__choice_var(name), \
        { \
            BOOST_PP_STRINGIZE(UNKNOWN), \
            __choice_option_values(name, tup) \
            BOOST_PP_IF( \
                __choice_has_final_none(tup), \
                BOOST_PP_EMPTY, \
                BOOST_PP_IDENTITY( \
                    BOOST_PP_STRINGIZE(NONE) \
                ) \
            )() \
        } \
    };*/ \
    \
    /* define a function in the debug text section that handles registering \
     * this syscall info structure into the global linked list */ \
    /*__attribute__((section(debug_text_section))) \
    static void __choice_register(name)(int argc, char** argv, char** envp) \
    { \
        __choice_append(&__choice_info(name)); \
    }*/ \
    /* add the registration function to the debug preinit_array; this lets it
     * be cleanly included/excluded based on the linker script */ \
    /*__attribute__((section(debug_preinit_section), used)) \
    static void (*__choice_preinit(name))() = __choice_register(name); */ \
    \
    rettype name(__choice_fix_args(args)) \
    { \
        rettype _result = fail; \
        /* if we have already made a decision, jump right away, otherwise, \
         * work through the options and find one that works */ \
        switch (__choice_var(name)) \
        { \
        /* if we haven't made a decision yet, start at the top */ \
        case __choice_option(name, UNKNOWN): \
        /* generate cases for each of the options we were given */ \
        BOOST_PP_REPEAT( \
            __choice_pair_count(tup), \
            __choice_n_case, \
            BOOST_PP_VARIADIC_TO_TUPLE(name, rettype, args, fail, tup) \
        ) \
        /* the case where none of the syscalls work; we short-circuit it so \
         * that any further calls immediately go here */ \
        case __choice_option(name, NONE): \
            __choice_var(name) = __choice_option(name, NONE); \
            BOOST_PP_IF( \
                __choice_has_final_none(tup), \
                __choice_n_case_none, \
                __choice_n_case_fail \
            )(tup, args, fail) \
        } \
    }
/* we have a 'none' case, so use that as our default */
#define __choice_n_case_none(tup, args, fail) \
    /* a final none option was provided, use that */ \
    return __choice_pair_get_right( \
        BOOST_PP_SUB(__choice_pair_count(tup), 1), \
        tup \
    )(__choice_arg_names(args));
/* no 'none' case provided, we fail here */
#define __choice_n_case_fail(tup, args, fail) \
    /* no final none, we treat it as a failure */ \
    return fail;
/* expand an option into a case branch to include in the generic function; this
 * is an intermediate macro to expand the data tuple passed from the repeat */
#define __choice_n_case(z, n, tup) \
    /* tup -> (name, rettype, args, fail, tup) */ \
    BOOST_PP_IF( \
        /* if we have a true 'none' option, it's handled in the main body
         * instead of here, so we ignore our final option */ \
        BOOST_PP_NOT(BOOST_PP_AND( \
            BOOST_PP_EQUAL( \
                BOOST_PP_SUB( \
                    __choice_pair_count(BOOST_PP_TUPLE_ELEM(4, tup)), \
                    1 \
                ), \
                n \
            ), \
            __choice_has_final_none(BOOST_PP_TUPLE_ELEM(4, tup)) \
        )), \
        __choice_n_case_normal, \
        __choice_n_case_empty \
    )( \
        BOOST_PP_TUPLE_ELEM(0, tup), \
        BOOST_PP_TUPLE_ELEM(1, tup), \
        BOOST_PP_TUPLE_ELEM(2, tup), \
        BOOST_PP_TUPLE_ELEM(3, tup), \
        __choice_pair_get_left(n, BOOST_PP_TUPLE_ELEM(4, tup)), \
        __choice_pair_get_right(n, BOOST_PP_TUPLE_ELEM(4, tup)) \
    )
/* a normal choice option */
#define __choice_n_case_normal(name, rettype, args, fail, option, call) \
    case __choice_option(name, option): \
        /* try to call the current option */ \
        _result = call(__choice_arg_names(args)); \
        /* if we have previously selected this option, if it returns \
         * successfully, or if it raises a non-ENOSYS error, we consider the \
         * call to be successful */ \
        if ((__choice_var(name) == __choice_option(name, option)) || \
                (_result != fail) || (errno != ENOSYS)) { \
            /* mark this as the right option to use henceforth and return */ \
            __choice_var(name) = __choice_option(name, option); \
            return _result; \
        }
/* dummy macro that evaluates to nothing but consumes arguments */
#define __choice_n_case_empty(name, rettype, args, fail, option, call)

#endif // _POLYGLOT_SYSCALL_CHOICE_H
