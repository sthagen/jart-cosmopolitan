/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2022 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/fmt/itoa.h"
#include "libc/fmt/magnumstrs.internal.h"
#include "libc/intrin/describeflags.internal.h"
#include "libc/str/str.h"
#include "libc/sysv/consts/sol.h"

static inline char *StpCpy(char *d, const char *s) {
  size_t i;
  for (i = 0;; ++i) {
    if (!(d[i] = s[i])) {
      return d + i;
    }
  }
}

/**
 * Describes clock_gettime() clock argument.
 */
const char *(DescribeClockName)(char buf[32], int x) {
  int i;
  char *s, *p;
  if ((s = GetMagnumStr(kClockNames, x))) {
    p = buf;
    *p++ = 'C';
    *p++ = 'L';
    *p++ = 'O';
    *p++ = 'C';
    *p++ = 'K';
    *p++ = '_';
    StpCpy(p, s);
    return buf;
  } else {
    FormatInt32(buf, x);
    return buf;
  }
}