EXTRA_DIST = \
	Makefile.mingw \
	plugins.cfg

eight_balldir = $(PURPLE_LIBDIR)

eight_ball_la_LDFLAGS = -module -avoid-version

if HAVE_PURPLE

eight_ball_LTLIBRARIES = eight_ball.la

eight_ball_la_SOURCES = eight_ball.c

eight_ball_la_LIBADD = \
	$(GLIB_LIBS) \
	$(PURPLE_LIBS)

endif

AM_CPPFLAGS = \
	-DLIBDIR=\"$(PURPLE_LIBDIR)\" \
	-DDATADIR=\"$(PURPLE_DATADIR)\" \
	-DPIXMAPSDIR=\"$(PURPLE_PIXMAPSDIR)\" \
	$(DEBUG_CFLAGS) \
	$(PURPLE_CFLAGS) \
	$(GLIB_CFLAGS)

