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

#if !defined(_LINUX_I386_TERMIOS_H)
#define _LINUX_I386_TERMIOS_H 1

#define CBAUD       0010017
#define CBAUDEX     0010000

#define B0          0000000
#define B50         0000001
#define B75         0000002
#define B110        0000003
#define B134        0000004
#define B150        0000005
#define B200        0000006
#define B300        0000007
#define B600        0000010
#define B1200       0000011
#define B1800       0000012
#define B2400       0000013
#define B4800       0000014
#define B9600       0000015
#define B19200      0000016
#define B38400      0000017
#define B57600      0010001
#define B115200     0010002
#define B230400     0010003
#define B460800     0010004
#define B500000     0010005
#define B576000     0010006
#define B921600     0010007
#define B1000000    0010010
#define B1152000    0010011
#define B1500000    0010012
#define B2000000    0010013
#define B2500000    0010014
#define B3000000    0010015
#define B3500000    0010016
#define B4000000    0010017

#define VEOF        4
#define VEOL        11
#define VERASE      2
#define VINTR       0
#define VKILL       3
#define VMIN        6
#define VQUIT       1
#define VSTART      8
#define VSTOP       9
#define VSUSP       10
#define VTIME       5

#define CSIZE       0000060
#define CS5         0000000
#define CS6         0000020
#define CS7         0000040
#define CS8         0000060
#define CSTOPB      0000100
#define CREAD       0000200
#define PARENB      0000400
#define PARODD      0001000
#define HUPCL       0002000
#define CLOCAL      0004000

#define BRKINT      000002
#define ICRNL       000400
#define IGNBRK      000001
#define IGNCR       000200
#define IGNPAR      000004
#define INLCR       000100
#define INPCK       000020
#define ISTRIP      000040
#define IXANY       004000
#define IXOFF       010000
#define IXON        002000
#define PARMRK      000010

#define ECHO        0000010
#define ECHOE       0000020
#define ECHOK       0000040
#define ECHONL      0000100
#define ICANON      0000002
#define IEXTEN      0100000
#define ISIG        0000001
#define NOFLSH      0000200
#define TOSTOP      0000400

#define OPOST       0000001
#define ONLCR       0000004
#define OCRNL       0000010
#define ONOCR       0000020
#define ONLRET      0000040
#define OFDEL       0000200
#define OFILL       0000100
#define NLDLY       0000400
#define NL0         0000000
#define NL1         0000400
#define CRDLY       0003000
#define CR0         0000000
#define CR1         0001000
#define CR2         0002000
#define CR3         0003000
#define TABDLY      0014000
#define TAB0        0000000
#define TAB1        0004000
#define TAB2        0010000
#define TAB3        0014000
#define BSDLY       0020000
#define BS0         0000000
#define BS1         0020000
#define VTDLY       0040000
#define VT0         0000000
#define VT1         0040000
#define FFDLY       0100000
#define FF0         0000000
#define FF1         0100000

#define NCCS        19

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

struct termios
{
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[NCCS];
};

struct winsize
{
    unsigned short ws_row;
    unsigned short ws_col;
    unsigned short ws_xpixel;
    unsigned short ws_ypixel;
};

#endif // _LINUX_I386_TERMIOS_H
