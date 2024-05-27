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

#if !defined(_TERMIOS_H)
#define _TERMIOS_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <target/ioctl.h>
#include <target/termios.h>

/* MACRO DEFINITIONS **********************************************************/

#define TCSANOW     0
#define TCSADRAIN   1
#define TCSAFLUSH   2

#define TCIFLUSH    0
#define TCIOFLUSH   2
#define TCOFLUSH    1

#define TCIOFF      2
#define TCION       3
#define TCOOFF      0
#define TCOON       1

/* FUNCTION PROTOTYPES ********************************************************/

speed_t cfgetispeed(const struct termios *);
speed_t cfgetospeed(const struct termios *);
void cfmakeraw(struct termios *);
int cfsetispeed(struct termios *, speed_t);
int cfsetospeed(struct termios *, speed_t);
int tcdrain(int);
int tcflow(int, int);
int tcflush(int, int);
int tcgetattr(int, struct termios *);
int tcsendbreak(int, int);
int tcsetattr(int, int, const struct termios *);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - pid_t tcgetsid(int);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _TERMIOS_H
