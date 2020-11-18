AM_CFLAGS = -I. -I$(top_builddir)/gw -I$(top_builddir)/gwlib -I$(top_builddir)

bin_PROGRAMS = seewbmp mtbatch decode_emimsg
sbin_PROGRAMS = run_kannel_box

man1_MANS = seewbmp.1 mtbatch.1
man8_MANS = run_kannel_box.8

seewbmp_LDADD = $(top_builddir)/libgwlib.a $(top_builddir)/libgw.a
seewbmp_SOURCES = \
		seewbmp.c

mtbatch_LDADD = $(top_builddir)/libgwlib.a $(top_builddir)/libgw.a
mtbatch_SOURCES = \
		mtbatch.c

decode_emimsg_LDADD = $(top_builddir)/libgwlib.a $(top_builddir)/libgw.a
decode_emimsg_SOURCES = \
		decode_emimsg.c

run_kannel_box_LDADD = $(top_builddir)/libgwlib.a $(top_builddir)/libgw.a
run_kannel_box_SOURCES = \
		run_kannel_box.c

if BUILD_STARTSTOPDAEMON

sbin_PROGRAMS += start-stop-daemon
start_stop_daemon_LDADD = $(top_builddir)/libgwlib.a $(top_builddir)/libgw.a
start_stop_daemon_SOURCES = \
		start-stop-daemon.c

endif