# inet_pton.m4 serial 1
dnl Copyright (C) 2006 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_INET_PTON],
[
  AC_REPLACE_FUNCS(inet_pton)
  gl_PREREQ_INET_PTON
])

# Prerequisites of lib/inet_pton.h and lib/inet_pton.c.
AC_DEFUN([gl_PREREQ_INET_PTON], [
  AC_CHECK_HEADERS_ONCE(arpa/inet.h)
  AC_CHECK_DECLS([inet_pton],,,[#include <arpa/inet.h>])
  AC_REQUIRE([gl_SOCKET_FAMILIES])
])
