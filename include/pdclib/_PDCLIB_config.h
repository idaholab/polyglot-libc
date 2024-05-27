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

/* Internal PDCLib configuration <_PDCLIB_config.h> */

#ifndef _PDCLIB_CONFIG_H
#define _PDCLIB_CONFIG_H _PDCLIB_CONFIG_H

// XXX: we removed _PDCLIB_ERRNO_MAX, which was the only thing in this header;
// once all that is resolved, we'll remove this message and the commented out
// include on the next line
// #include <target/_PDCLIB.h>

/* -------------------------------------------------------------------------- */
/* Misc                                                                       */
/* -------------------------------------------------------------------------- */

/* The character (sequence) your platform uses as newline.                    */
#define _PDCLIB_endl "\n"

/* exit() can signal success to the host environment by the value of zero or  */
/* the constant EXIT_SUCCESS. Failure is signaled by EXIT_FAILURE. Note that  */
/* any other return value is "implementation-defined", i.e. your environment  */
/* is not required to handle it gracefully. Set your definitions here.        */
#define _PDCLIB_SUCCESS 0
#define _PDCLIB_FAILURE 1

/* qsort() in <stdlib.h> requires a function that swaps two memory areas.     */
/* Below is a naive implementation that can be improved significantly for     */
/* specific platforms, e.g. by swapping int instead of char.                  */
#define _PDCLIB_memswp( i, j, size ) \
    char tmp; \
    do { \
        tmp = *i; \
        *i++ = *j; \
        *j++ = tmp; \
    } while ( --size );

/* Define this to some compiler directive that can be written after the       */
/* parameter list of a function declaration to indicate the function does     */
/* never return. If your compiler does not support such a directive, define   */
/* to nothing. (This is to avoid warnings with the exit functions under GCC.) */
#define _PDCLIB_NORETURN __attribute__((noreturn))

/* -------------------------------------------------------------------------- */
/* Symbol Visibility                                                          */
/* -------------------------------------------------------------------------- */

//#ifdef _PDCLIB_STATIC_DEFINE
  #define _PDCLIB_PUBLIC
  #define _PDCLIB_LOCAL
//#else
  //#define _PDCLIB_PUBLIC __attribute__((visibility ("default")))
  //#define _PDCLIB_LOCAL  __attribute__((visibility ("hidden")))
//#endif

/* -------------------------------------------------------------------------- */
/* Integers                                                                   */
/* -------------------------------------------------------------------------- */
/* The defines below make use of predefines offered by GCC and clang. If you  */
/* adapt PDCLib for a different compiler family, you will have to use what    */
/* that compiler provides, or enter actual values.                            */
/* -------------------------------------------------------------------------- */

/* At the point of writing, PDCLib makes no provisions for, nor has it been   */
/* tested, on a platform that uses signed magnitude or one's complement to    */
/* encode its integers. Most importantly, there are no guarantees that the    */
/* negative zero of those encodings is in any form handled gracefully.        */
#define _PDCLIB_TWOS_COMPLEMENT 1

/* Calculation of a minimum value from a given maximum for two's complement.  */
#define _PDCLIB_MIN_CALC( max ) ( ( - max ) - 1 )

/* Now, introducting the various predefines to the _PDCLIB_* namespace, so    */
/* the rest of PDCLib can work with that and adapting to a different compiler */
/* will require changes only in this one file.                                */

#define _PDCLIB_CHAR_BIT __CHAR_BIT__

#define _PDCLIB_SCHAR_MAX __SCHAR_MAX__
#define _PDCLIB_SCHAR_MIN _PDCLIB_MIN_CALC( __SCHAR_MAX__ )
#define _PDCLIB_UCHAR_MAX ( __SCHAR_MAX__ * 2 + 1 )

/* Whether the 'char' type is unsigned                                        */
#ifdef __CHAR_UNSIGNED__
#define _PDCLIB_CHAR_MAX _PDCLIB_UCHAR_MAX
#define _PDCLIB_CHAR_MIN 0
#else
#define _PDCLIB_CHAR_MAX _PDCLIB_SCHAR_MAX
#define _PDCLIB_CHAR_MIN _PDCLIB_SCHAR_MIN
#endif

#define _PDCLIB_SHRT_MAX __SHRT_MAX__
#define _PDCLIB_SHRT_MIN _PDCLIB_MIN_CALC( __SHRT_MAX__ )
#define _PDCLIB_USHRT_MAX ( __SHRT_MAX__ * 2u + 1 )

#define _PDCLIB_INT_MAX __INT_MAX__
#define _PDCLIB_INT_MIN _PDCLIB_MIN_CALC( __INT_MAX__ )
#define _PDCLIB_UINT_MAX ( __INT_MAX__ * 2u + 1 )

#define _PDCLIB_LONG_MAX __LONG_MAX__
#define _PDCLIB_LONG_MIN _PDCLIB_MIN_CALC( __LONG_MAX__ )
#define _PDCLIB_ULONG_MAX ( __LONG_MAX__ * 2ul + 1 )

#define _PDCLIB_LLONG_MAX __LONG_LONG_MAX__
#define _PDCLIB_LLONG_MIN _PDCLIB_MIN_CALC( __LONG_LONG_MAX__ )
#define _PDCLIB_ULLONG_MAX ( __LONG_LONG_MAX__ * 2ull + 1 )

/* -------------------------------------------------------------------------- */
/* <stdint.h> defines a set of integer types that are of a minimum width, and */
/* "usually fastest" on the system. (If, for example, accessing a single char */
/* requires the CPU to access a complete int and then mask out the char, the  */
/* "usually fastest" type of at least 8 bits would be int, not char.)         */
/* If you do not have information on the relative performance of the types,   */
/* the standard allows you to define any type that meets minimum width and    */
/* signedness requirements.                                                   */
/* The first define is the appropriate basic type (e.g. "long int"), second   */
/* its max value, the third its min value, and the fourth the width in bits   */
/* (not bytes!).                                                              */
/* The minimum width types have a fifth define, a macro taking a value and    */
/* expanding to an integer constant of that value, and the corresponding      */
/* minimum width type.                                                        */
/* The *are* predefines provided for the printf()/scanf() length specifiers,  */
/* but tunneling them through here would have added many lines of repetitive  */
/* and mostly redundant defines, so these are determined in <_PDCLIB_int.h>.  */
/* -------------------------------------------------------------------------- */

#define _PDCLIB_int_fast8_t        __INT_FAST8_TYPE__
#define _PDCLIB_INT_FAST8_MAX      __INT_FAST8_MAX__
#define _PDCLIB_INT_FAST8_MIN      _PDCLIB_MIN_CALC( __INT_FAST8_MAX__ )
#define _PDCLIB_uint_fast8_t       __UINT_FAST8_TYPE__
#define _PDCLIB_UINT_FAST8_MAX     __UINT_FAST8_MAX__

#define _PDCLIB_int_least8_t       __INT_LEAST8_TYPE__
#define _PDCLIB_INT_LEAST8_MAX     __INT_LEAST8_MAX__
#define _PDCLIB_INT_LEAST8_MIN     _PDCLIB_MIN_CALC( __INT_LEAST8_MAX__ )
#define _PDCLIB_INT_LEAST8_C       __INT8_C
#define _PDCLIB_uint_least8_t      __UINT_LEAST8_TYPE__
#define _PDCLIB_UINT_LEAST8_MAX    __UINT_LEAST8_MAX__
#define _PDCLIB_UINT_LEAST8_C      __UINT8_C

#define _PDCLIB_int_fast16_t       __INT_FAST16_TYPE__
#define _PDCLIB_INT_FAST16_MAX     __INT_FAST16_MAX__
#define _PDCLIB_INT_FAST16_MIN     _PDCLIB_MIN_CALC( __INT_FAST16_MAX__ )
#define _PDCLIB_uint_fast16_t      __UINT_FAST16_TYPE__
#define _PDCLIB_UINT_FAST16_MAX    __UINT_FAST16_MAX__

#define _PDCLIB_int_least16_t      __INT_LEAST16_TYPE__
#define _PDCLIB_INT_LEAST16_MAX    __INT_LEAST16_MAX__
#define _PDCLIB_INT_LEAST16_MIN    _PDCLIB_MIN_CALC( __INT_LEAST16_MAX__ )
#define _PDCLIB_INT_LEAST16_C      __INT16_C
#define _PDCLIB_uint_least16_t     __UINT_LEAST16_TYPE__
#define _PDCLIB_UINT_LEAST16_MAX   __UINT_LEAST16_MAX__
#define _PDCLIB_UINT_LEAST16_C     __UINT16_C

#define _PDCLIB_int_fast32_t       __INT_FAST32_TYPE__
#define _PDCLIB_INT_FAST32_MAX     __INT_FAST32_MAX__
#define _PDCLIB_INT_FAST32_MIN     _PDCLIB_MIN_CALC( __INT_FAST32_MAX__ )
#define _PDCLIB_uint_fast32_t      __UINT_FAST32_TYPE__
#define _PDCLIB_UINT_FAST32_MAX    __UINT_FAST32_MAX__

#define _PDCLIB_int_least32_t      __INT_LEAST32_TYPE__
#define _PDCLIB_INT_LEAST32_MAX    __INT_LEAST32_MAX__
#define _PDCLIB_INT_LEAST32_MIN    _PDCLIB_MIN_CALC( __INT_LEAST32_MAX__ )
#define _PDCLIB_INT_LEAST32_C      __INT32_C
#define _PDCLIB_uint_least32_t     __UINT_LEAST32_TYPE__
#define _PDCLIB_UINT_LEAST32_MAX   __UINT_LEAST32_MAX__
#define _PDCLIB_UINT_LEAST32_C     __UINT32_C

#define _PDCLIB_int_fast64_t       __INT_FAST64_TYPE__
#define _PDCLIB_INT_FAST64_MAX     __INT_FAST64_MAX__
#define _PDCLIB_INT_FAST64_MIN     _PDCLIB_MIN_CALC( __INT_FAST64_MAX__ )
#define _PDCLIB_uint_fast64_t      __UINT_FAST64_TYPE__
#define _PDCLIB_UINT_FAST64_MAX    __UINT_FAST64_MAX__

#define _PDCLIB_int_least64_t      __INT_LEAST64_TYPE__
#define _PDCLIB_INT_LEAST64_MAX    __INT_LEAST64_MAX__
#define _PDCLIB_INT_LEAST64_MIN    _PDCLIB_MIN_CALC( __INT_LEAST64_MAX__ )
#define _PDCLIB_INT_LEAST64_C      __INT64_C
#define _PDCLIB_uint_least64_t     __UINT_LEAST64_TYPE__
#define _PDCLIB_UINT_LEAST64_MAX   __UINT_LEAST64_MAX__
#define _PDCLIB_UINT_LEAST64_C     __UINT64_C

#if __target_arch_mips && (__target_abi_o32 || __target_abi_n32)
// fix the mips-o32/-n32 uint_least32_t definition (broken PRIx32)
#undef _PDCLIB_uint_least32_t
#define _PDCLIB_uint_least32_t unsigned int
#endif

/* <stdlib.h> defines the div() function family that allows taking quotient   */
/* and remainder of an integer division in one operation. Many platforms      */
/* support this in hardware / opcode, and the standard permits ordering of    */
/* the return structure in any way to fit the hardware. That is why those     */
/* structs can be configured here.                                            */

struct _PDCLIB_div_t
{
    int quot;
    int rem;
};

struct _PDCLIB_ldiv_t
{
    long int quot;
    long int rem;
};

struct _PDCLIB_lldiv_t
{
    long long int quot;
    long long int rem;
};

/* -------------------------------------------------------------------------- */
/* What follows are a couple of "special" typedefs and their limits.          */
/* -------------------------------------------------------------------------- */

/* The result type of substracting two pointers                               */
#define _PDCLIB_ptrdiff_t   __PTRDIFF_TYPE__
#define _PDCLIB_PTRDIFF_MAX __PTRDIFF_MAX__
#define _PDCLIB_PTRDIFF_MIN _PDCLIB_MIN_CALC( __PTRDIFF_MAX__ )
#define _PDCLIB_PTR_CONV l

/* An integer type that can be accessed as atomic entity (think asynchronous  */
/* interrupts). In a freestanding environment, the type itself need not be    */
/* defined, but its limits must. (Don't ask.) GCC is so kind to predefine it, */
/* but clang is only giving us its MAX value, so we use that to identify the  */
/* type in _PDCLIB_int.h if the type definition is unavailable.               */
#ifdef __SIG_ATOMIC_TYPE__
#define _PDCLIB_sig_atomic_t   __SIG_ATOMIC_TYPE__
#endif
#define _PDCLIB_SIG_ATOMIC_MAX __SIG_ATOMIC_MAX__
#define _PDCLIB_SIG_ATOMIC_MIN _PDCLIB_MIN_CALC( __SIG_ATOMIC_MAX__ )

/* Result type of the 'sizeof' operator (must be unsigned).                   */
/* Note: In <stdint.h>, this is taken as the base for RSIZE_MAX, the limit    */
/* for the bounds-checking interfaces of Annex K. The recommendation by the   */
/* standard is to use ( SIZE_MAX >> 1 ) when "targeting machines with large   */
/* addess spaces", whereas small address spaces should use SIZE_MAX directly. */
#define _PDCLIB_size_t   __SIZE_TYPE__
#define _PDCLIB_SIZE_MAX __SIZE_MAX__

/* Large enough an integer to hold all character codes of the widest          */
/* supported locale.                                                          */
#define _PDCLIB_wchar_t   __WCHAR_TYPE__
#define _PDCLIB_WCHAR_MAX __WCHAR_MAX__
#define _PDCLIB_WCHAR_MIN __WCHAR_MIN__

/* Large enough an integer to hold all character codes of the widest          */
/* supported locale plus WEOF (which needs not to be equal to EOF, nor needs  */
/* to be of negative value).                                                  */
#define _PDCLIB_wint_t   __WINT_TYPE__
#define _PDCLIB_WINT_MAX __WINT_MAX__
#define _PDCLIB_WINT_MIN __WINT_MIN__

/* Integer types capable of taking the (cast) value of a void *, and having   */
/* the value cast back to void *, comparing equal to the original.            */
#define _PDCLIB_intptr_t     __INTPTR_TYPE__
#define _PDCLIB_INTPTR_MAX   __INTPTR_MAX__
#define _PDCLIB_INTPTR_MIN   _PDCLIB_MIN_CALC( __INTPTR_MAX__ )
#define _PDCLIB_uintptr_t    __UINTPTR_TYPE__
#define _PDCLIB_UINTPTR_MAX  __UINTPTR_MAX__

/* Largest supported integer type. Implementation note: see _PDCLIB_atomax(). */
#define _PDCLIB_intmax_t     __INTMAX_TYPE__
#define _PDCLIB_INTMAX_MAX   __INTMAX_MAX__
#define _PDCLIB_INTMAX_MIN   _PDCLIB_MIN_CALC( __INTMAX_MAX__ )
#define _PDCLIB_INTMAX_C     __INTMAX_C
#define _PDCLIB_uintmax_t    __UINTMAX_TYPE__
#define _PDCLIB_UINTMAX_MAX  __UINTMAX_MAX__
#define _PDCLIB_UINTMAX_C    __UINTMAX_C

/* <inttypes.h> defines imaxdiv(), which is equivalent to the div() function  */
/* family (see further above) with intmax_t as basis.                         */
struct _PDCLIB_imaxdiv_t
{
    _PDCLIB_intmax_t quot;
    _PDCLIB_intmax_t rem;
};

/* -------------------------------------------------------------------------- */
/* Time types, limits, constants, and paths                                   */
/* -------------------------------------------------------------------------- */

/* _PDCLIB_time is the type for type_t; _PDCLIB_clock for clock_t. Both types */
/* are defined as "real types capable of representing times". The "range and  */
/* precision of times representable" is implementation-defined.               */

/* For clock_t, the standard defines that dividing the result of clock() by   */
/* CLOCKS_PER_SEC gives the seconds elapsed.                                  */
#define _PDCLIB_clock_t long long
#define _PDCLIB_CLOCKS_PER_SEC 1000000

/* For time_t, no such divider exists. Most implementations use a count of    */
/* seconds since a specified epoch. While PDCLib really should support other  */
/* encodings as well, for now "count of seconds" is the only supported one.   */
/* MIN / MAX values for time_t are not required by the standard (and they are */
/* not "exported" from the _PDCLIB namespace), but they are useful in support */
/* of the _tzcode implementation.                                             */
#define _PDCLIB_time_t long long
#define _PDCLIB_TIME_MAX __LONG_LONG_MAX__
#define _PDCLIB_TIME_MIN _PDCLIB_MIN_CALC( __LONG_LONG_MAX__ )

/* "Unix time" uses 1970-01-01T00:00:00 as "epoch". If your system uses a     */
/* different "zero point" for its timestamps, set this to the offset between  */
/* your epoch and Unix epoch. (For example, NTP uses 1900-01-01T00:00:00 as   */
/* epoch, giving an offset of (70 * 365 + 17) * 86400 = 220898800 seconds.)   */
#define _PDCLIB_EPOCH_BIAS INT64_C( 0 )

/* Leave this alone for now.                                                  */
#define _PDCLIB_TIME_UTC 1

/* Path to TZ data.                                                           */
/* IMPORTANT: *Must* end with separator character!                            */
/* It does make it much easier for the time data handling code if this detail */
/* can be relied upon and need not be handled in code.                        */
#define _PDCLIB_TZDIR "/usr/share/zoneinfo/"

/* Path to default (local) timezone                                           */
#define _PDCLIB_TZDEFAULT "/etc/localtime"

/* -------------------------------------------------------------------------- */
/* Floating Point                                                             */
/* -------------------------------------------------------------------------- */

/* Whether the implementation rounds toward zero (0), to nearest (1), toward  */
/* positive infinity (2), or toward negative infinity (3). (-1) signifies     */
/* indeterminable rounding, any other value implementation-specific rounding. */
#define _PDCLIB_FLT_ROUNDS -1

/* Whether the implementation uses exact-width precision (0), promotes float  */
/* to double (1), or promotes float and double to long double (2).            */
/* (-1) signifies indeterminable behaviour, any other value implementation-   */
/* specific behaviour.                                                        */
#define _PDCLIB_FLT_EVAL_METHOD -1

/* "Number of the decimal digits (n), such that any floating-point number in  */
/* the widest supported floating type with p(max) radix (b) digits can be     */
/* rounded to a floating-point number with (n) decimal digits and back again  */
/* without change to the value p(max) log(10)b if (b) is a power of 10,       */
/* [1 + p(max) log(10)b] otherwise."                                          */
/* 64bit IEC 60559 double format (53bit mantissa) is DECIMAL_DIG 17.          */
/* 80bit IEC 60559 double-extended format (64bit mantissa) is DECIMAL_DIG 21. */
#define _PDCLIB_DECIMAL_DIG 17

/* -------------------------------------------------------------------------- */
/* Platform-dependent macros defined by the standard headers.                 */
/* -------------------------------------------------------------------------- */

/* The offsetof macro                                                         */
/* Contract: Expand to an integer constant expression of type size_t, which   */
/* represents the offset in bytes to the structure member from the beginning  */
/* of the structure. If the specified member is a bitfield, behaviour is      */
/* undefined.                                                                 */
/* There is no standard-compliant way to do this.                             */
/* This implementation casts an integer zero to 'pointer to type', and then   */
/* takes the address of member. This is undefined behaviour but should work   */
/* on most compilers.                                                         */
// Generic definition:
// #define _PDCLIB_offsetof(type, member) ((size_t)&(((type*)0)->member))
// GCC definition:
#define _PDCLIB_offsetof(type, member) __builtin_offsetof(type, member)

/* Variable Length Parameter List Handling (<stdarg.h>)                       */
/* The macros defined by <stdarg.h> are highly dependent on the calling       */
/* conventions used, and you probably have to replace them with builtins of   */
/* your compiler.                                                             */

typedef __builtin_va_list _PDCLIB_va_list;
#define _PDCLIB_va_arg( ap, type ) ( __builtin_va_arg( ap, type ) )
#define _PDCLIB_va_copy( dest, src ) ( __builtin_va_copy( dest, src ) )
#define _PDCLIB_va_end( ap ) ( __builtin_va_end( ap ) )
#define _PDCLIB_va_start( ap, parmN ) ( __builtin_va_start( ap, parmN ) )

/* -------------------------------------------------------------------------- */
/* OS "glue", part 1                                                          */
/* These are values and data type definitions that you would have to adapt to */
/* the capabilities and requirements of your OS.                              */
/* The actual *functions* of the OS interface are declared in _PDCLIB_glue.h. */
/* -------------------------------------------------------------------------- */

/* I/O ---------------------------------------------------------------------- */

/* The type of the file descriptor returned by _PDCLIB_open(), i.e. whatever  */
/* the underlying kernel uses for stream identification.                      */
typedef int _PDCLIB_fd_t;

/* The value of type _PDCLIB_fd_t returned by _PDCLIB_open() if the operation */
/* failed.                                                                    */
#define _PDCLIB_NOHANDLE ( (_PDCLIB_fd_t) -1 )

/* The default size for file buffers. Must be at least 256.                   */
#define _PDCLIB_BUFSIZ 1024

/* The minimum number of files the implementation guarantees can opened       */
/* simultaneously.  Must be at least 8. Depends largely on how the platform   */
/* does the bookkeeping in whatever is called by _PDCLIB_open(). PDCLib puts  */
/* no further limits on the number of open files other than available memory. */
#define _PDCLIB_FOPEN_MAX 8

/* Length of the longest filename the implementation guarantees to support.   */
#define _PDCLIB_FILENAME_MAX 128

/* Maximum length of filenames generated by tmpnam(). (See tmpfile.c.)        */
#define _PDCLIB_L_tmpnam 46

/* Number of distinct file names that can be generated by tmpnam().           */
#define _PDCLIB_TMP_MAX 50

/* The values of SEEK_SET, SEEK_CUR and SEEK_END, used by fseek().            */
/* Since at least one platform (POSIX) uses the same symbols for its own      */
/* "seek" function, you should use whatever the host defines (if it does      */
/* define them).                                                              */
#define _PDCLIB_SEEK_SET /*defined in <target/seek.h>*/
#define _PDCLIB_SEEK_CUR /*defined in <target/seek.h>*/
#define _PDCLIB_SEEK_END /*defined in <target/seek.h>*/

/* The number of characters that can be buffered with ungetc(). The standard  */
/* guarantees only one (1); PDCLib supports larger values, but applications   */
/* relying on this would rely on implementation-defined behaviour (not good). */
#define _PDCLIB_UNGETCBUFSIZE 1

/* The number of functions that can be registered with atexit(). Needs to be  */
/* at least 33 (32 guaranteed by the standard, plus _PDCLIB_closeall() which  */
/* is used internally by PDCLib to close all open streams).                   */
/* TODO: Should expand dynamically.                                           */
#define _PDCLIB_ATEXIT_SLOTS 40

/* errno -------------------------------------------------------------------- */

/* These are the values that _PDCLIB_errno can be set to by the library.      */
/*                                                                            */
/* By keeping PDCLib's errno in the _PDCLIB_* namespace, the library is       */
/* capable of "translating" between errno values used by the hosting OS and   */
/* those used and passed out by the library.                                  */
/*                                                                            */
/* Example: In the example platform, the remove() function uses the unlink()  */
/* system call as backend. Linux sets its errno to EISDIR if you try to       */
/* unlink() a directory, but POSIX demands EPERM. Within the remove()         */
/* function, you can catch 'errno == EISDIR', and set '*_PDCLIB_errno_func()  */
/* = _PDCLIB_EPERM'. Anyone using PDCLib's <errno.h> will "see" EPERM instead */
/* of EISDIR.                                                                 */
/*                                                                            */
/* If you do not want that kind of translation, you might want to "match" the */
/* values used by PDCLib with those used by the host OS, to avoid confusion.  */
/* auxiliary/errno/errno_readout.c provides a convenience program to read     */
/* those errno values mandated by the standard from a platform's <errno.h>,   */
/* giving output that can readily be pasted here.                             */
/* Either way, note that the list below, the list in PDCLib's <errno.h>, and  */
/* the list in _PDCLIB_stdinit.h, need to be kept in sync.                    */
/*                                                                            */
/* The values below are read from a Linux system.                             */

#include <target/errno.h>

// FIXME: this should just be removed and we should use the real names in all of
// PDClib where we need them... fix that.

/* Argument list too long */
#define _PDCLIB_E2BIG           E2BIG
/* Permission denied */
#define _PDCLIB_EACCES          EACCES
/* Address in use */
#define _PDCLIB_EADDRINUSE      EADDRINUSE
/* Address not available */
#define _PDCLIB_EADDRNOTAVAIL   EADDRNOTAVAIL
/* Address family not supported */
#define _PDCLIB_EAFNOSUPPORT    EAFNOSUPPORT
/* Resource unavailable, try again */
#define _PDCLIB_EAGAIN          EAGAIN
/* Connection already in progress */
#define _PDCLIB_EALREADY        EALREADY
/* Bad file descriptor */
#define _PDCLIB_EBADF           EBADF
/* Bad message */
#define _PDCLIB_EBADMSG         EBADMSG
/* Device or resource busy */
#define _PDCLIB_EBUSY           EBUSY
/* Operation canceled */
#define _PDCLIB_ECANCELED       ECANCELED
/* No child processes */
#define _PDCLIB_ECHILD          ECHILD
/* Connection aborted */
#define _PDCLIB_ECONNABORTED    ECONNABORTED
/* Connection refused */
#define _PDCLIB_ECONNREFUSED    ECONNREFUSED
/* Connection reset */
#define _PDCLIB_ECONNRESET      ECONNRESET
/* Resource deadlock would occur */
#define _PDCLIB_EDEADLK         EDEADLK
/* Destination address required */
#define _PDCLIB_EDESTADDRREQ    EDESTADDRREQ
/* Mathematics argument out of domain of function */
#define _PDCLIB_EDOM            EDOM
/* File exists */
#define _PDCLIB_EEXIST          EEXIST
/* Bad address */
#define _PDCLIB_EFAULT          EFAULT
/* File too large */
#define _PDCLIB_EFBIG           EFBIG
/* Host is unreachable */
#define _PDCLIB_EHOSTUNREACH    EHOSTUNREACH
/* Identifier removed */
#define _PDCLIB_EIDRM           EIDRM
/* Illegal byte sequence */
#define _PDCLIB_EILSEQ          EILSEQ
/* Operation in progress */
#define _PDCLIB_EINPROGRESS     EINPROGRESS
/* Interrupted function */
#define _PDCLIB_EINTR           EINTR
/* Invalid argument */
#define _PDCLIB_EINVAL          EINVAL
/* I/O error */
#define _PDCLIB_EIO             EIO
/* Socket is connected */
#define _PDCLIB_EISCONN         EISCONN
/* Is a directory */
#define _PDCLIB_EISDIR          EISDIR
/* Too many levels of symbolic links */
#define _PDCLIB_ELOOP           ELOOP
/* File descriptor value too large */
#define _PDCLIB_EMFILE          EMFILE
/* Too many links */
#define _PDCLIB_EMLINK          EMLINK
/* Message too large */
#define _PDCLIB_EMSGSIZE        EMSGSIZE
/* Filename too long */
#define _PDCLIB_ENAMETOOLONG    ENAMETOOLONG
/* Network is down */
#define _PDCLIB_ENETDOWN        ENETDOWN
/* Connection aborted by network */
#define _PDCLIB_ENETRESET       ENETRESET
/* Network unreachable */
#define _PDCLIB_ENETUNREACH     ENETUNREACH
/* Too many files open in system */
#define _PDCLIB_ENFILE          ENFILE
/* No buffer space available */
#define _PDCLIB_ENOBUFS         ENOBUFS
/* No message is available on the STREAM head read queue */
#define _PDCLIB_ENODATA         ENODATA
/* No such device */
#define _PDCLIB_ENODEV          ENODEV
/* No such file or directory */
#define _PDCLIB_ENOENT          ENOENT
/* Executable file format error */
#define _PDCLIB_ENOEXEC         ENOEXEC
/* No locks available */
#define _PDCLIB_ENOLCK          ENOLCK
/* Link has been severed */
#define _PDCLIB_ENOLINK         ENOLINK
/* Not enough space */
#define _PDCLIB_ENOMEM          ENOMEM
/* No message of the desired type */
#define _PDCLIB_ENOMSG          ENOMSG
/* Protocol not available */
#define _PDCLIB_ENOPROTOOPT     ENOPROTOOPT
/* No space left on device */
#define _PDCLIB_ENOSPC          ENOSPC
/* No STREAM resources */
#define _PDCLIB_ENOSR           ENOSR
/* Not a STREAM */
#define _PDCLIB_ENOSTR          ENOSTR
/* Function not supported */
#define _PDCLIB_ENOSYS          ENOSYS
/* The socket is not connected */
#define _PDCLIB_ENOTCONN        ENOTCONN
/* Not a directory */
#define _PDCLIB_ENOTDIR         ENOTDIR
/* Directory not empty */
#define _PDCLIB_ENOTEMPTY       ENOTEMPTY
/* State not recoverable */
#define _PDCLIB_ENOTRECOVERABLE ENOTRECOVERABLE
/* Not a socket */
#define _PDCLIB_ENOTSOCK        ENOTSOCK
/* Not supported */
#define _PDCLIB_ENOTSUP         ENOTSUP
/* Inappropriate I/O control operation */
#define _PDCLIB_ENOTTY          ENOTTY
/* No such device or address */
#define _PDCLIB_ENXIO           ENXIO
/* Operation not supported on socket */
#define _PDCLIB_EOPNOTSUPP      EOPNOTSUPP
/* Value too large to be stored in data type */
#define _PDCLIB_EOVERFLOW       EOVERFLOW
/* Previous owner died */
#define _PDCLIB_EOWNERDEAD      EOWNERDEAD
/* Operation not permitted */
#define _PDCLIB_EPERM           EPERM
/* Broken pipe */
#define _PDCLIB_EPIPE           EPIPE
/* Protocol error */
#define _PDCLIB_EPROTO          EPROTO
/* Protocol not supported */
#define _PDCLIB_EPROTONOSUPPORT EPROTONOSUPPORT
/* Protocol wrong type for socket */
#define _PDCLIB_EPROTOTYPE      EPROTOTYPE
/* Result too large */
#define _PDCLIB_ERANGE          ERANGE
/* Read-only file system */
#define _PDCLIB_EROFS           EROFS
/* Invalid seek */
#define _PDCLIB_ESPIPE          ESPIPE
/* No such process */
#define _PDCLIB_ESRCH           ESRCH
/* Stream ioctl() timeout */
#define _PDCLIB_ETIME           ETIME
/* Connection timed out */
#define _PDCLIB_ETIMEDOUT       ETIMEDOUT
/* Text file busy */
#define _PDCLIB_ETXTBSY         ETXTBSY
/* Operation would block */
#define _PDCLIB_EWOULDBLOCK     EWOULDBLOCK
/* Cross-device link */
#define _PDCLIB_EXDEV           EXDEV

/* The highest defined errno value, plus one. This is used to set the size    */
/* of the array in struct _PDCLIB_lc_text_t holding error messages for the    */
/* strerror() and perror() functions. (If you change this value because you   */
/* are using additional errno values, you *HAVE* to provide appropriate error */
/* messages for *ALL* locales.)                                               */
//#define _PDCLIB_ERRNO_MAX 132

/* The error message used for unknown error codes (generated by errno_readout */
/* for consistency between the 'holes' in the list of defined error messages  */
/* and the text generated by e.g. strerror() for out-of-range error values.)  */
#define _PDCLIB_EUNKNOWN_TEXT (char*)"unknown error"

/* locale data -------------------------------------------------------------- */

/* The default path where PDCLib should look for its locale data.             */
/* Must end with the appropriate separator character.                         */
#define _PDCLIB_LOCALE_PATH "/usr/share/pdclib/i18n"

/* The name of the environment variable that can be used to override that     */
/* path setting.                                                              */
#define _PDCLIB_LOCALE_PATH_ENV PDCLIB_I18N

/* threads ------------------------------------------------------------------ */

#define __STDC_NO_THREADS__ 1

/* This is relying on underlying <pthread.h> implementation to provide thread */
/* support.                                                                   */
/* The problem here is we cannot just #include <pthread.h> and access the     */
/* original definitions. The standard library must not drag identifiers into  */
/* the user's namespace, so we have to set our own definitions. Which are,    */
/* obviously, platform-specific.                                              */
/* If you do NOT want to provide threads support, define __STDC_NO_THREADS__  */
/* to 1 and simply delete the threads.h header and the corresponding files in */
/* functions/threads/. This makes PDCLib not thread-safe (obviously), as all  */
/* all the safeguards against race conditions (e.g. in <stdio.h>) will be     */
/* omitted.                                                                   */

/* header extensions -------------------------------------------------------- */

#define _PDCLIB_EXTEND_LIMITS_H <limits_ext.h>
#define _PDCLIB_EXTEND_STDINT_H <stdint_ext.h>
#define _PDCLIB_EXTEND_STDIO_H <stdio_ext.h>
#define _PDCLIB_EXTEND_STDLIB_H <stdlib_ext.h>
#define _PDCLIB_EXTEND_STRING_H <string_ext.h>
#define _PDCLIB_EXTEND_TIME_H <time_ext.h>

#endif
