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

#if !defined(_X86_64_MACHMODES_H)
#define _X86_64_MACHMODES_H 1

#define  _QI_TYPE               int __attribute__((mode(QI)))
#define  _HI_TYPE               int __attribute__((mode(HI)))
#define  _SI_TYPE               int __attribute__((mode(SI)))
#define  _DI_TYPE               int __attribute__((mode(DI)))
#define  _TI_TYPE               int __attribute__((mode(TI)))

#define  _QU_TYPE          unsigned __attribute__((mode(QI)))
#define  _HU_TYPE          unsigned __attribute__((mode(HI)))
#define  _SU_TYPE          unsigned __attribute__((mode(SI)))
#define  _DU_TYPE          unsigned __attribute__((mode(DI)))
#define  _TU_TYPE          unsigned __attribute__((mode(TI)))

#define  _SF_TYPE             float __attribute__((mode(SF)))
#define  _DF_TYPE             float __attribute__((mode(DF)))
#define  _XF_TYPE             float __attribute__((mode(XF)))
#define  _TF_TYPE             float __attribute__((mode(TF)))

#define  _SC_TYPE    _Complex float __attribute__((mode(SC)))
#define  _DC_TYPE    _Complex float __attribute__((mode(DC)))
#define  _XC_TYPE    _Complex float __attribute__((mode(XC)))
#define  _TC_TYPE    _Complex float __attribute__((mode(TC)))

#endif // _X86_64_MACHMODES_H