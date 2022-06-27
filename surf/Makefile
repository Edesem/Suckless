# surf - simple browser
# See LICENSE file for copyright and license details.
.POSIX:

include config.mk

SRC = surf.c
WSRC = webext-surf.c
OBJ = $(SRC:.c=.o)
WOBJ = $(WSRC:.c=.o)
WLIB = $(WSRC:.c=.so)

all: options surf $(WLIB)

options:
	@echo surf build options:
	@echo "CC            = $(CC)"
	@echo "CFLAGS        = $(SURFCFLAGS) $(CFLAGS)"
	@echo "WEBEXTCFLAGS  = $(WEBEXTCFLAGS) $(CFLAGS)"
	@echo "LDFLAGS       = $(LDFLAGS)"

surf: $(OBJ)
	$(CC) $(SURFLDFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)

$(OBJ) $(WOBJ): config.h common.h config.mk

config.h:
	cp config.def.h $@

$(OBJ): $(SRC)
	$(CC) $(SURFCFLAGS) $(CFLAGS) -c $(SRC)

$(WLIB): $(WOBJ)
	$(CC) -shared -Wl,-soname,$@ $(LDFLAGS) -o $@ $? $(WEBEXTLIBS)

$(WOBJ): $(WSRC)
	$(CC) $(WEBEXTCFLAGS) $(CFLAGS) -c $(WSRC)

clean:
	rm -f surf $(OBJ)
	rm -f $(WLIB) $(WOBJ)

distclean: clean
	rm -f config.h surf-$(VERSION).tar.gz

dist: distclean
	mkdir -p surf-$(VERSION)
	cp -R LICENSE Makefile config.mk config.def.h README \
	    surf-open.sh arg.h TODO.md surf.png \
	    surf.1 common.h $(SRC) $(WSRC) surf-$(VERSION)
	tar -cf surf-$(VERSION).tar surf-$(VERSION)
	gzip surf-$(VERSION).tar
	rm -rf surf-$(VERSION)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f surf $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/surf
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp -f $(WLIB) $(DESTDIR)$(LIBDIR)
	for wlib in $(WLIB); do \
	    chmod 644 $(DESTDIR)$(LIBDIR)/$$wlib; \
	done
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < surf.1 > $(DESTDIR)$(MANPREFIX)/man1/surf.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/surf.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/surf
	rm -f $(DESTDIR)$(MANPREFIX)/man1/surf.1
	for wlib in $(WLIB); do \
	    rm -f $(DESTDIR)$(LIBDIR)/$$wlib; \
	done
	- rmdir $(DESTDIR)$(LIBDIR)

.PHONY: all options distclean clean dist install uninstall
