#include <stdio.h>
#include <stdarg.h>
#include <signal.h>

char *id_die = "@(#)/mnt/gersemi/src/Local/Die/die.c " \
               "Sunday October 10, 1999 (23:22) " \
               "Mark Orchard-Webb " \
               "Compiled: "__DATE__ " (" __TIME__ ")" ;

/*
 * Sunday October 10, 1999 (23:22)
 * ===============================
 * 
 * Add a carriage-return after error message
 * 
 * Thursday September 23, 1999 (11:54)
 * ===================================
 * 
 * Call fflush (stderr) before aborting ... moosefit redirects stderr
 * to a file this does not get written without the flush.
 * 
 * Saturday September 11, 1999 (18:23)
 * ===================================
 * 
 * Torn unceremoniously from the Vibrating_drum sources.  Add coredump
 * feature.
 * 
 */

int die (char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vfprintf (stderr, fmt, ap);
  va_end(ap);
  fprintf (stderr, "\n");
  fflush (stderr);
  raise(SIGABRT);
  return 0;
}

int warn (char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vfprintf (stderr, fmt, ap);
  fprintf (stderr, "\n");
  fflush (stderr);
  va_end(ap);
  return 0;
}

int errmsg (char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vfprintf (stderr, fmt, ap);
  fflush (stderr);
  va_end(ap);
  return 0;
}

