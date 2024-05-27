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

#include <netdb.h>


const char *gai_strerror(int err)
{
    switch (err)
    {
    case EAI_AGAIN:
        return "EAI_AGAIN";
    case EAI_BADFLAGS:
        return "EAI_BADFLAGS";
    case EAI_FAIL:
        return "EAI_FAIL";
    case EAI_FAMILY:
        return "EAI_FAMILY";
    case EAI_MEMORY:
        return "EAI_MEMORY";
    case EAI_NONAME:
        return "EAI_NONAME";
    case EAI_SERVICE:
        return "EAI_SERVICE";
    case EAI_SOCKTYPE:
        return "EAI_SOCKTYPE";
    case EAI_SYSTEM:
        return "EAI_SYSTEM";
    case EAI_OVERFLOW:
        return "EAI_OVERFLOW";
    default:
        return "<unknown>";
    }
}


