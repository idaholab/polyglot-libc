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

#ifndef _LINUX_MIPS_WAIT_H
#define _LINUX_MIPS_WAIT_H _LINUX_MIPS_WAIT_H

#define WCONTINUED      0x00000008
#define WNOHANG         0x00000001
#define WUNTRACED       0x00000002

#define __WCONTINUED    0xffff
#define __WCOREFLAG     0x80

#define WEXITSTATUS(s)  ((int)(((s) >> 8) & 0xff))
#define WIFCONTINUED(s) (((int)((s) & 0xffff)) == __WCONTINUED)
#define WIFEXITED(s)    ((int)((s) & 0xff) == 0)
#define WIFSIGNALED(s)  (((signed char)(((s) & 0x7f) + 1) >> 1) > 0)
#define WIFSTOPPED(s)   ((int)((s) & 0xff) == 0x7f)
#define WSTOPSIG(s)     WEXITSTATUS(status)
#define WTERMSIG(s)     ((int)((s) & 0x7f))
#define WCOREDUMP(s)    ((s) & __WCOREFLAG)

#define WEXITED         0x00000004
#define WNOWAIT         0x01000000
#define WSTOPPED        WUNTRACED

typedef enum __idtype {
    P_ALL   = 0,
    P_PID   = 1,
    P_PGID  = 2,
} idtype_t;

#endif // _LINUX_MIPS_WAIT_H
