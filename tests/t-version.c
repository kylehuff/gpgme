/* t-version.c  - regression test
 *      Copyright (C) 2001 g10 Code GmbH
 *
 * This file is part of GPGME.
 *
 * GPGME is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GPGME is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "../gpgme/gpgme.h"

static const char version[] = VERSION;

int 
main (int argc, char **argv )
{
  const char *null_result;
  const char *current_result;
  const char *future_result;

  null_result = gpgme_check_version (NULL);
  current_result = gpgme_check_version (VERSION);
  future_result = gpgme_check_version (VERSION ".1");

  return !(null_result
	   && ! strcmp (null_result, VERSION)
	   && current_result
	   && ! strcmp (current_result, VERSION)
	   && ! future_result);
}