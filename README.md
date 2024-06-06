# `polyglot-libc`

This is the C library component of Polyglot. It is logically separated because
it is licensed differently than the core Polyglot code. For further information
see the [main Polyglot repository][polyglot].

## License/Attribution

This repository is licensed as [LGPL v2.1][lgpl2.1]. For additional information
regarding funding, etc. see the [notice][notice] file in this repository.

Much of the target-agnostic portion of the C library originates from the [Public
Domain C Library (PDCLib)][pdclib]. Their efforts in maintaining the core of a C
library that can be used freely in other projects has been absolutely invaluable
to this effort. All files that originate from PDCLib are marked, even though
this is not strictly required. Files originating from the PDCLib that have not
been significantly modified remain under their original [Creative Commons
CC0][cc0] license.

We inherit two third party software components from PDCLib, which are noted here
along with their specific licenses:

- `calloc()`, `free()`, `malloc()`, and `realloc()` (from
  [`dlmalloc.c`][dlmalloc]) are included courtesy of [Doug Lea][douglea]; this
  code is also licensed as [CC0][cc0].
- Large parts of the functionality behind `<time.h>` is included courtesy of the
  IANA's [Time Zone Database][ianatzdb] (from `tzcode2020a.tar.gz`), which is in
  the public domain.

> PDCLib includes an additional third party component (the `strtod()` code), but
> we have elected to not include it here due to its license.

Additionally, there are a handful of files that are based on files in the [GNU C
Library (glibc)][glibc]. These are all licensed as LGPL v2.1 upstream, and
maintain it here. They are marked with their appropriate upstream copyright
notices and have a blurb about what changes have been made. Generally, they are
part of the architecture-specific initialization code, although there are a few
others. It was also incredibly useful as "documentation" of sorts of some more
arcane, platform-specific details.


[polyglot]: https://github.com/idaholab/polyglot-libc
[lgpl2.1]:  COPYING
[notice]:   NOTICE
[pdclib]:   https://github.com/DevSolar/pdclib
[cc0]:      COPYING.CC0
[douglea]:  https://gee.cs.oswego.edu/dl/
[dlmalloc]: src/_dlmalloc/dlmalloc.c
[ianatzdb]: https://www.iana.org/time-zones/
[glibc]:    https://www.gnu.org/software/libc/

