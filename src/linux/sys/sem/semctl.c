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

#include <sys/sem.h>
#include <stdarg.h>

int semctl(int semid, int semnum, int cmd, ...)
{
    long arg = 0;
    va_list ap;

    switch (cmd)
    {
    case IPC_STAT:
    case IPC_SET:
    case GETALL:
    case SETALL:
    case SETVAL:
        va_start(ap, cmd);
        arg = va_arg(ap, long);
        va_end(ap);

    case IPC_RMID:
    case GETNCNT:
    case GETPID:
    case GETVAL:
    case GETZCNT:
    default:
        break;
    }

    return __semctl(semid, semnum, cmd, arg);
}

