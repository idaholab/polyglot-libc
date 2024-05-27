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

/*
_PDCLIB_localsub( struct state const *, time_t const *, int_fast32_t, struct tm * const )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

/* The easy way to behave "as if no library function calls" localtime
   is to not call it, so we drop its guts into "localsub", which can be
   freely called. (And no, the PANS doesn't require the above behavior,
   but it *is* desirable.)

   If successful and SETNAME is nonzero,
   set the applicable parts of tzname, timezone and altzone;
   however, it's OK to omit this step if the timezone is POSIX-compatible,
   since in that case tzset should have already done this step correctly.
   SETNAME's type is intfast32_t for compatibility with gmtsub,
   but it is actually a boolean and its value should be 0 or 1.
*/

/*ARGSUSED*/
struct tm * _PDCLIB_localsub( struct state const * sp, time_t const * timep, int_fast32_t setname, struct tm * const tmp )
{
    const struct ttinfo * ttisp;
    int                   i;
    struct tm *           result;
    const time_t          t = *timep;

    if ( sp == NULL )
    {
        /* Don't bother to set tzname etc.; tzset has already done it.  */
        return _PDCLIB_gmtsub( _PDCLIB_gmtptr, timep, 0, tmp );
    }

    if ( ( sp->goback && t < sp->ats[ 0 ] ) || ( sp->goahead && t > sp->ats[ sp->timecnt - 1 ] ) )
    {
        time_t newt = t;
        time_t seconds;
        time_t years;

        if ( t < sp->ats[ 0 ] )
        {
            seconds = sp->ats[ 0 ] - t;
        }
        else
        {
            seconds = t - sp->ats[ sp->timecnt - 1 ];
        }

        --seconds;
        years = ( seconds / SECSPERREPEAT + 1 ) * YEARSPERREPEAT;
        seconds = years * AVGSECSPERYEAR;

        if ( t < sp->ats[ 0 ] )
        {
            newt += seconds;
        }
        else
        {
            newt -= seconds;
        }

        if ( newt < sp->ats[ 0 ] || newt > sp->ats[ sp->timecnt - 1 ] )
        {
            return NULL;    /* "cannot happen" */
        }

        result = _PDCLIB_localsub( sp, &newt, setname, tmp );

        if ( result )
        {
            int_fast64_t newy;

            newy = result->tm_year;

            if ( t < sp->ats[ 0 ] )
            {
                newy -= years;
            }
            else
            {
                newy += years;
            }

            if ( ! ( _PDCLIB_INT_MIN <= newy && newy <= _PDCLIB_INT_MAX ) )
            {
                return NULL;
            }

            result->tm_year = newy;
        }

        return result;
    }

    if ( sp->timecnt == 0 || t < sp->ats[ 0 ] )
    {
        i = sp->defaulttype;
    }
    else
    {
        int lo = 1;
        int hi = sp->timecnt;

        while ( lo < hi )
        {
            int mid = ( lo + hi ) >> 1;

            if ( t < sp->ats[ mid ] )
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        i = (int) sp->types[ lo - 1 ];
    }

    ttisp = &sp->ttis[ i ];

    /* To get (wrong) behavior that's compatible with System V Release 2.0
       you'd replace the statement below with
       t += ttisp->tt_utoff;
       timesub( &t, 0L, sp, tmp );
    */
    result = _PDCLIB_timesub( &t, ttisp->tt_utoff, sp, tmp );

    if ( result )
    {
        result->tm_isdst = ttisp->tt_isdst;
#ifdef TM_ZONE
        result->TM_ZONE = (char *) &sp->chars[ ttisp->tt_desigidx ];
#endif /* defined TM_ZONE */

        if ( setname )
        {
            _PDCLIB_update_tzname_etc( sp, ttisp );
        }
    }

    return result;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
#endif

    return TEST_RESULTS;
}

#endif
