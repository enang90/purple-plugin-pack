dnl ###########################################################################
dnl # m4 Build Helper for the purple plugin pack
dnl # Copyright (C) 2005-2007 Gary Kramlich <grim@reaperworld.com>
dnl #
dnl # awk foo and other sanity graciously provided by Caleb Gilmour
dnl #
dnl ###########################################################################
dnl # AM_BUILD_PLUGIN_LIST
dnl #
dnl # Searches a dir, for subdir's which have a .plugin file defining them
dnl # as plugins for the plugin pack.
dnl #
dnl ###########################################################################

AC_DEFUN([AM_BUILD_PLUGIN_LIST],
[dnl
	PP_PURPLE=""
	PP_PURPLE_ABUSIVE=""
	PP_PURPLE_INCOMPLETE=""
	PP_PURPLE_BUILD=""

	PP_PIDGIN=""
	PP_PIDGIN_ABUSIVE=""
	PP_PIDGIN_INCOMPLETE=""
	PP_PIDGIN_BUILD=""

	PP_FINCH=""
	PP_FINCH_ABUSIVE=""
	PP_FINCH_INCOMPLETE=""
	PP_FINCH_BUILD=""

	dnl #######################################################################
	dnl # Build a list of all the available plugins
	dnl #######################################################################
	for d in $srcdir/*; do
		if ! test -d "$d"; then
			continue
		fi

		if test -f "$d/Makefile.am" -a ! "$d" = "$srcdir/common" -a ! "$d" = "$srcdir/doc" -a ! "$d" = "$srcdir/m4" -a ! -f "$d/.abusive" -a ! -f "$d/.build" -a ! -f "$d/.incomplete" -a ! -f "$d/.sanity" ; then
			AC_ERROR([Directory $d missing sanity])
		fi

		base=`basename $d`

		if test -f "$d/.purple-plugin" ; then
			if test -f $d/.abusive ; then
				PP_PURPLE_ABUSIVE="$PP_PURPLE_ABUSIVE $base"
			elif test -f "$d/.build" ; then
				PP_PURPLE_BUILD="$PP_PURPLE_BUILD $base"
			fi

			if test -f "$d/.incomplete" ; then
				PP_PURPLE_INCOMPLETE="$PP_PURPLE_INCOMPLETE $base"
			fi

			PP_PURPLE="$PP_PURPLE $base"
		elif test -f "$d/.pidgin-plugin" ; then
			if test -f "$d/.abusive" ; then
				PP_PIDGIN_ABUSIVE="$PP_PIDGIN_ABUSIVE $base"
			elif test -f "$d/.build" ; then
				PP_PIDGIN_BUILD="$PP_PIDGIN_BUILD $base"
			fi

			if test -f "$d/.incomplete" ; then
				PP_PIDGIN_INCOMPLETE="$PP_PIDGIN_INCOMPLETE $base"
			fi

			PP_PIDGIN="$PP_PIDGIN $base"
		elif test -f "$d/.finch-plugin" ; then
			if test -f "$d/.abusive" ; then
				PP_FINCH_ABUSIVE="$PP_FINCH_ABUSIVE $base"
			elif test -f "$d/.build" ; then
				PP_FINCH_BUILD="$PP_FINCH_BUILD $base"
			fi

			if test -f "$d/.incomplete" ; then
				PP_FINCH_INCOMPLETE="$PP_FINCH_INCOMPLETE $base"
			fi

			PP_FINCH="$PP_FINCH $base"
		fi
	done;

	dnl #######################################################################
	dnl # Add our argument
	dnl #######################################################################
	AC_ARG_WITH(plugins,
				AC_HELP_STRING([--with-plugins], [what plugins to build]),
				,with_plugins=all)

	dnl #######################################################################
	dnl # Now determine which ones have been selected
	dnl #######################################################################
	if test "x$with_plugins" = "xdefault" ; then
		tmp_SUB="$PP_AVAILABLE"
	else
		exp_plugins=`echo "$with_plugins" | sed 's/,/ /g'`
		for p in "$PP_AVAILABLE $PP_ABUSIVE"; do
			for r in $exp_plugins; do
				if test x"$r" = x"$p" ; then
					tmp_SUB="$tmp_SUB $p"
				fi
			done
		done
	fi

	dnl # remove duplicates
	PP_BUILD=`echo $tmp_SUB | awk '{for (i = 1; i <= NF; i++) { print $i } }' | sort | uniq | xargs echo `

	dnl # add the abusive plugins to the dist
	PP_DIST="$PP_AVAILABLE $PP_ABUSIVE"

	dnl #######################################################################
	dnl # substitue our sub dirs
	dnl #######################################################################
	AC_SUBST(PP_PURPLE)
	AC_SUBST(PP_PURPLE_ABUSIVE)
	AC_SUBST(PP_PURPLE_INCOMPLETE)
	AC_SUBST(PP_PURPLE_BUILD)

	AC_SUBST(PP_PIDGIN)
	AC_SUBST(PP_PIDGIN_ABUSIVE)
	AC_SUBST(PP_PIDGIN_INCOMPLETE)
	AC_SUBST(PP_PIDGIN_BUILD)

	AC_SUBST(PP_FINCH)
	AC_SUBST(PP_FINCH_ABUSIVE)
	AC_SUBST(PP_FINCH_INCOMPLETE)
	AC_SUBST(PP_FINCH_BUILD)

	dnl #######################################################################
	dnl # build some statistics info
	dnl #######################################################################
	PP_PURPLE_ABUSIVE_COUNT=`echo $PP_PURPLE_ABUSIVE | wc -w`
	PP_PURPLE_INCOMPLETE_COUNT=`echo $PP_PURPLE_INCOMPLETE | wc -w`
	PP_PURPLE_BUILD_COUNT=`echo $PP_PURPLE_BUILD | wc -w`
	PP_PURPLE_TOTAL_COUNT=`echo $PP_PURPLE | wc -w`

	AC_SUBST(PP_PURPLE_ABUSIVE_COUNT)
	AC_SUBST(PP_PURPLE_INCOMPLETE_COUNT)
	AC_SUBST(PP_PURPLE_BUILD_COUNT)
	AC_SUBST(PP_PURPLE_TOTAL_COUNT)

	PP_PIDGIN_ABUSIVE_COUNT=`echo $PP_PIDGIN_ABUSIVE | wc -w`
	PP_PIDGIN_INCOMPLETE_COUNT=`echo $PP_PIDGIN_INCOMPLETE | wc -w`
	PP_PIDGIN_BUILD_COUNT=`echo $PP_PIDGIN_BUILD | wc -w`
	PP_PIDGIN_TOTAL_COUNT=`echo $PP_PIDGIN | wc -w`

	AC_SUBST(PP_PIDGIN_ABUSIVE_COUNT)
	AC_SUBST(PP_PIDGIN_INCOMPLETE_COUNT)
	AC_SUBST(PP_PIDGIN_BUILD_COUNT)
	AC_SUBST(PP_PIDGIN_TOTAL_COUNT)

	PP_FINCH_ABUSIVE_COUNT=`echo $PP_FINCH_ABUSIVE | wc -w`
	PP_FINCH_INCOMPLETE_COUNT=`echo $PP_FINCH_INCOMPLETE | wc -w`
	PP_FINCH_BUILD_COUNT=`echo $PP_FINCH_BUILD | wc -w`
	PP_FINCH_TOTAL_COUNT=`echo $PP_FINCH | wc -w`

	AC_SUBST(PP_FINCH_ABUSIVE_COUNT)
	AC_SUBST(PP_FINCH_INCOMPLETE_COUNT)
	AC_SUBST(PP_FINCH_BUILD_COUNT)
	AC_SUBST(PP_FINCH_TOTAL_COUNT)
])
