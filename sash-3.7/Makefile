#
# Makefile for sash
#
# The HAVE_GZIP definition adds the -gzip and -gunzip commands.
# The HAVE_LINUX_ATTR definition adds the -chattr and -lsattr commands.
# The HAVE_LINUX_MOUNT definition makes -mount and -umount work on Linux.
# The HAVE_BSD_MOUNT definition makes -mount and -umount work on BSD.
# The MOUNT_TYPE definition sets the default file system type for -mount.
#
HAVE_GZIP		= 0
HAVE_LINUX_ATTR		= 0
HAVE_LINUX_MOUNT	= 0
HAVE_BSD_MOUNT		= 0
MOUNT_TYPE		= '"ext3"'


CFLAGS = -g -Wall -Wextra -Wmissing-prototypes \
	-DHAVE_GZIP=$(HAVE_GZIP) \
	-DHAVE_LINUX_ATTR=$(HAVE_LINUX_ATTR) \
	-DHAVE_LINUX_MOUNT=$(HAVE_LINUX_MOUNT) \
	-DHAVE_BSD_MOUNT=$(HAVE_BSD_MOUNT) \
	-DMOUNT_TYPE=$(MOUNT_TYPE)

# LDFLAGS = -static -s
#LIBS = -lz


BINDIR = /bin
MANDIR = /usr/man/man1

All: sash

OBJS = sash.o cmds.o cmd_dd.o cmd_ed.o cmd_grep.o cmd_ls.o cmd_tar.o \
	cmd_gzip.o cmd_find.o cmd_file.o cmd_chattr.o cmd_ar.o utils.o


eval-upmc.o : eval-upmc.h eval-upmc.cpp
	g++ -c eval-upmc.cpp -o eval-upmc.o

eval-upmc-wrapper.o : eval-upmc.h eval-upmc-wrapper.h eval-upmc-wrapper.cpp
	g++ -c eval-upmc-wrapper.cpp -o eval-upmc-wrapper.o


sash:	$(OBJS) eval-upmc.o eval-upmc-wrapper.o
	g++ $(LDFLAGS) -o sash $(OBJS) eval-upmc.o eval-upmc-wrapper.o  $(LIBS)
	g++ eval-upmc-main.cpp eval-upmc.cpp -o eval-upmc

clean:
	rm -f $(OBJS) sash eval-upmc.o eval-upmc eval-upmc-wrapper.o *~

install: sash
	cp sash $(BINDIR)/sash
	cp sash.1 $(MANDIR)/sash.1

$(OBJS):	sash.h
