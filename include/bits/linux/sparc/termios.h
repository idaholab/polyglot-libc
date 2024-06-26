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

#if !defined(_LINUX_SPARC_TERMIOS_H)
#define _LINUX_SPARC_TERMIOS_H 1

/* c_cc indices */
#define VINTR       0
#define VQUIT       1
#define VERASE      2
#define VKILL       3
#define VEOF        4
#define VEOL        5
#define VEOL2       6
#define VSWTC       7
#define VSTART      8
#define VSTOP       9
#define VSUSP       10
#define VDSUSP      11
#define VREPRINT    12
#define VDISCARD    13
#define VWERASE     14
#define VLNEXT      15
#define VMIN        VEOF
#define VTIME       VEOL

/* c_iflag */
#define IGNBRK      0x00000001
#define BRKINT      0x00000002
#define IGNPAR      0x00000004
#define PARMRK      0x00000008
#define INPCK       0x00000010
#define ISTRIP      0x00000020
#define INLCR       0x00000040
#define IGNCR       0x00000080
#define ICRNL       0x00000100
#define IUCLC       0x00000200
#define IXON        0x00000400
#define IXANY       0x00000800
#define IXOFF       0x00001000
#define IMAXBEL     0x00002000
#define IUTF8       0x00004000

/* c_oflag */
#define OPOST       0x00000001
#define OLCUC       0x00000002
#define ONLCR       0x00000004
#define OCRNL       0x00000008
#define ONOCR       0x00000010
#define ONLRET      0x00000020
#define OFILL       0x00000040
#define OFDEL       0x00000080
#define NLDLY       0x00000100
#define NL0         0x00000000
#define NL1         0x00000100
#define CRDLY       0x00000600
#define CR0         0x00000000
#define CR1         0x00000200
#define CR2         0x00000400
#define CR3         0x00000600
#define TABDLY      0x00001800
#define TAB0        0x00000000
#define TAB1        0x00000800
#define TAB2        0x00001000
#define TAB3        0x00001800
#define XTABS       0x00001800
#define BSDLY       0x00002000
#define BS0         0x00000000
#define BS1         0x00002000
#define VTDLY       0x00004000
#define VT0         0x00000000
#define VT1         0x00004000
#define FFDLY       0x00008000
#define FF0         0x00000000
#define FF1         0x00008000
#define PAGEOUT     0x00010000
#define WRAP        0x00020000

/* c_cflag */
#define CBAUD       0x0000100f
#define B0          0x00000000
#define B50         0x00000001
#define B75         0x00000002
#define B110        0x00000003
#define B134        0x00000004
#define B150        0x00000005
#define B200        0x00000006
#define B300        0x00000007
#define B600        0x00000008
#define B1200       0x00000009
#define B1800       0x0000000a
#define B2400       0x0000000b
#define B4800       0x0000000c
#define B9600       0x0000000d
#define B19200      0x0000000e
#define B38400      0x0000000f
#define EXTA        B19200
#define EXTB        B38400
#define CSIZE       0x00000030
#define CS5         0x00000000
#define CS6         0x00000010
#define CS7         0x00000020
#define CS8         0x00000030
#define CSTOPB      0x00000040
#define CREAD       0x00000080
#define PARENB      0x00000100
#define PARODD      0x00000200
#define HUPCL       0x00000400
#define CLOCAL      0x00000800
#define CBAUDEX     0x00001000
#define  B57600     0x00001001
#define  B115200    0x00001002
#define  B230400    0x00001003
#define  B460800    0x00001004
#define  B76800     0x00001005
#define  B153600    0x00001006
#define  B307200    0x00001007
#define  B614400    0x00001008
#define  B921600    0x00001009
#define  B500000    0x0000100a
#define  B576000    0x0000100b
#define B1000000    0x0000100c
#define B1152000    0x0000100d
#define B1500000    0x0000100e
#define B2000000    0x0000100f
#define B2500000    0x00001010
#define B3000000    0x00001011
#define B3500000    0x00001012
#define B4000000    0x00001013
#define CIBAUD      0x100f0000 /* unused */
#define CMSPAR      0x40000000
#define CRTSCTS     0x80000000

/* c_lflag */
#define ISIG        0x00000001
#define ICANON      0x00000002
#define XCASE       0x00000004
#define ECHO        0x00000008
#define ECHOE       0x00000010
#define ECHOK       0x00000020
#define ECHONL      0x00000040
#define NOFLSH      0x00000080
#define TOSTOP      0x00000100
#define ECHOCTL     0x00000200
#define ECHOPRT     0x00000400
#define ECHOKE      0x00000800
#define DEFECHO     0x00001000
#define FLUSHO      0x00002000
#define PENDIN      0x00004000
#define IEXTEN      0x00008000

#define NCC         8
#define NCCS        17

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

struct termio {
    unsigned short c_iflag;
    unsigned short c_oflag;
    unsigned short c_cflag;
    unsigned short c_lflag;
    unsigned char c_line;
    unsigned char c_cc[NCC];
};

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[NCCS];
};

struct winsize {
    unsigned short ws_row;
    unsigned short ws_col;
    unsigned short ws_xpixel;
    unsigned short ws_ypixel;
};

#endif // _LINUX_SPARC_TERMIOS_H
