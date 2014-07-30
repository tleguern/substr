PROG=substr

test: all
	cd regress && make

.PHONY: test

.include <bsd.prog.mk>
