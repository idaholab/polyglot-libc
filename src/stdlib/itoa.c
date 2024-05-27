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

#include <polyglot/itoa.h>
#include <stddef.h>
#include <errno.h>


char *itoa(long long value, char *str, size_t base)
{
    unsigned long long i;
    size_t n = 0;
    char *p1 = str, *p2 = str, c;

    // Make sure our base is within the allowable range.
    if (((base & 0xff) < 2) || ((base & 0xff) > 36)) {
        errno = EINVAL;
        return NULL;
    }

    // Only decimal gets signed conversions.
    if ((base & 0xff) != 10) {
        base |= ITOA_FLAG_UNSIGNED;
    }

    // If it's a signed conversion and negative, flip it for processing.
    if (!ITOA_FLAG(base, UNSIGNED) && (value < 0)) {
        i = -value;
    } else {
        i = value;
    }

    // Default if our number is zero.
    if (i == 0) {
        *(p1++) = '0';
    } else {
        while (i) {
            // Add a separator if needed.
            if (ITOA_FLAG(base, SEPARATOR) && ((base & 0xff) == 10) && (n != 0)
                    && (n % 3 == 0)) {
                *(p1++) = ',';
            }

            // Figure out our current digit and adjust.
            c = i % (base & 0xff);
            i /= (base & 0xff);
            ++n;

            // Add our digit to the number.
            *(p1++) = c + (c < 10 ? '0' : 'a' - 10);
        }
    }

    // We handle signed conversions a little differently.
    if (!ITOA_FLAG(base, UNSIGNED) && !ITOA_FLAG(base, NEVER_SIGN)) {
        // If it's negative, always give it a sign.
        if (value < 0) {
            *(p1++) = '-';
        // If we are supposed to always give it a sign, give it a '+'.
        } else if (ITOA_FLAG(base, ALWAYS_SIGN)) {
            *(p1++) = '+';
        // If we are supposed to leave room, give it a ' '.
        } else if (ITOA_FLAG(base, SIGN_SPACE)) {
            *(p1++) = ' ';
        }
    }

    // Null terminate the string.
    *(p1--) = 0;

    // Invert the resulting string.
    while (p1 > p2) {
        c = *p2;
        *(p2++) = *p1;
        *(p1--) = c;
    }

    return str;
}


