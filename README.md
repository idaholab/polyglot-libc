# `polyglot-libc`

This is the C library component of Polyglot. It is logically separated because
it is licensed differently than the core Polyglot code. For further information
see the [main Polyglot repository][polyglot].

## License/Attribution

This repository is licensed as [LGPL v2.1][license]. For additional information
regarding funding, etc. see the [notice][notice] file in this repository.

Much of the target-agnostic portion of the C library originates from the [Public
Domain C Library (PDClib)][pdclib]. Their efforts in maintaining the core of C
library that can be used freely in other projects has been absolutely invaluable
to this effort. All files that originate from PDClib are marked, even though
this is not strictly required.

Additionally, there are a handful of files that are based on files in the [GNU C
Library (glibc)][glibc]. These are all licensed as LGPL v2.1 upstream, and
maintain it here. They are marked with their appropriate upstream copyright
notices and have a blurb about what changes have been made. Generally, they are
part of the architecture-specific initialization code, although there are a few
others. It was also incredibly useful as "documentation" of sorts of some more
arcane, platform-specific details.


[polyglot]: https://github.com/idaholab/polyglot-libc
[license]:  LICENSE_LGPL2_1.txt
[notice]:   NOTICE.txt
[pdclib]:   https://github.com/DevSolar/pdclib
[glibc]:    https://www.gnu.org/software/libc/

