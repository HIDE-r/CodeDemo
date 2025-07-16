AC_INIT([hello], [1.0])
AC_CONFIG_SRCDIR([hello.c])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CC
AC_CHECK_FUNCS([strdup])

# 手动定义 DEBUG 宏（始终开启）
AC_DEFINE([DEBUG], [1], [Enable debug output])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
