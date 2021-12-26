PROG= substr
CFLAGS+= -W -Wall -Wmissing-prototypes -Wstrict-prototypes -Wwrite-strings

INSTALL_PROGRAM?= install -m 0555
INSTALL_MAN?= install -m 0444
DESTDIR?=/usr/local/
BINDIR?=bin/
MANDIR?=man/

.SUFFIXES: .c .o .1 .md
.PHONY: clean install

.c.o:
	${CC} ${CFLAGS} -c $<

.1.md:
	mandoc -T markdown $@ > $<

${PROG}: ${PROG}.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ ${PROG}.o ${LDADD}

clean:
	rm -f ${PROG} ${PROG}.o

install: ${PROG}
	mkdir -p ${DESTDIR}${BINDIR}
	mkdir -p ${DESTDIR}${MANDIR}/man1
	${INSTALL_PROGRAM} ${PROG} ${DESTDIR}${BINDIR}
	${INSTALL_MAN} ${PROG}.1 ${DESTDIR}${MANDIR}/man1
