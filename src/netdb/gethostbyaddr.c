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
#include <string.h>


struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type)
{
    struct hostent *ent;

    // Open and/or rewind the file
    sethostent(__netdb_host_stayopen);

    // Iterate through records, seeing if they match
    while ((ent = gethostent())) {
        // Filter out things with the wrong address type
        if (ent->h_addrtype != type)
            continue;
        if (ent->h_length != len)
            continue;

        // Try to match any of the addresses
        for (char **haddr = ent->h_addr_list; *haddr; ++haddr)
            if (!memcmp(*haddr, addr, len))
                goto finish;
    }

    // We found nothing, so we return NULL
    ent = NULL;

finish:
    if (!__netdb_host_stayopen)
        endhostent();
    return ent;
}


