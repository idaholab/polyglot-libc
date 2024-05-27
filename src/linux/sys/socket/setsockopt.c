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

#include <polyglot/syscall_choice.h>
#include <sys/socket.h>
#include <sys/time.h>

int setsockopt(int socket, int level, int option_name,
        const void *option_value, socklen_t option_len)
{
    union {
        struct __kernel_timeval timeout;
#define k_timeout   (k_options.timeout)
#define opt_timeout ((const struct timeval*)option_value)
    } k_options;

    switch (level) {
    case SOL_SOCKET:
        switch (option_name) {
        case SO_SNDTIMEO:
        case SO_RCVTIMEO:
            k_timeout.tv_sec = opt_timeout->tv_sec;
            k_timeout.tv_usec = opt_timeout->tv_usec;
            option_value = (const void *)&k_timeout;
            option_len = sizeof(k_timeout);
            break;
        }
        break;
    }

    return __setsockopt(socket, level, option_name, option_value, option_len);

#undef k_timeout
#undef opt_timeout
}

