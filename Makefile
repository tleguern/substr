PROG= substr
BINDIR?= /usr/local/bin

test: all
	cd regress && make

.PHONY: test

.include <bsd.prog.mk>
