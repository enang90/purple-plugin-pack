/*
 * Gaim Plugin Pack
 * Copyright (C) 2003-2005
 * See AUTHORS for a list of all authors
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#ifndef GPP_INTL_H
#define GPP_INTL_H

#ifdef HAVE_CONFIG_H
# include "../gpp_config.h"
#endif

#ifdef _WIN32
# include <win32dep.h>
#endif

#ifdef ENABLE_NLS
#  include <locale.h>
#  include <libintl.h>
#  define _(x) dgettext(GPP_PACKAGE, x)
#  ifdef dgettext_noop
#    define N_(String) dgettext_noop (GPP_PACKAGE, String)
#  else
#    define N_(String) (String)
#  endif
#else
#  include <locale.h>
#  define N_(String) (String)
#  define _(x) (x)
#  define ngettext(Singular, Plural, Number) ((Number == 1) ? (Singular) : (Plural))
#endif

#endif