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



int grantpt(int fd)
{
    /* XXX: on some systems, we could do this via the pt_chown setuid helper
     * binary; for systems that don't have that helper (specifically older OSes
     * potentially, such as pre-UNIX98-style Linuxes, or newer Linuxes that use
     * /dev/pts/X), it is assumed that the ownership of the nodes is correct
     * enough for use. Under older Linux, it seems like the binaries that use
     * PTYs tend to be setuid, which could be specifically to allow for handling
     * these cases (plus their libc's don't have grantpt() anyway...). */
    return 0;
}


