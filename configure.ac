dnl Copyright (C) 2015, 2018  T+A elektroakustik GmbH & Co. KG
dnl
dnl This file is part of OffEvent.
dnl
dnl OffEvent is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License, version 3 as
dnl published by the Free Software Foundation.
dnl
dnl OffEvent is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with OffEvent.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.69])
AC_INIT([OffEvent], [1.0], [r.tiemann@ta-hifi.com])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([1.11 -Wall -Werror foreign])
AM_SILENT_RULES([yes])
AC_CONFIG_SRCDIR([offevent.c])
AC_CONFIG_HEADERS([config.h])

AC_USE_SYSTEM_EXTENSIONS()

AC_ARG_VAR([CWARNINGS], [strict set of C compiler warnings])
AC_ARG_VAR([CRELAXEDWARNINGS], [options for relaxing some compiler warnings for various files])

# Checks for programs.
AC_PROG_CC
AC_CHECK_PROGS([MARKDOWN], [markdown])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.

AM_CONDITIONAL([WITH_MARKDOWN], [test "x$ac_cv_prog_MARKDOWN" != "x"])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
