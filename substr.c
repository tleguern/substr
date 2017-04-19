/*
 * Copyright (c) 2014 Tristan Le Guern <tleguern@bouledef.eu>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef NEED_LIBBSD
# include <bsd/stdlib.h>
#endif

void usage(void);

int
main(int argc, char *argv[]) {
	unsigned int	 pos;
	unsigned int	 length;
	size_t		 slen;
	char		 ch;
	char		*string;
	const char	*errstr;

	while ((ch = getopt(argc, argv, "")) != -1)
		switch (ch) {
		default:
			usage();
			/* NOTREACHED */
		}
	argc -= optind;
	argv += optind;

	if (argc < 2 || argc > 3 || argv[0] == NULL) {
		usage();
		/* NOTREACHED */
	}

	string = argv[0];
	slen = strlen(string);

	pos = strtonum(argv[1], 1, slen, &errstr);
	if (errstr)
		errx(1, "pos is %s", errstr);

	if (argc == 2) {
		length = slen - pos + 1;
	} else {
		length = strtonum(argv[2], 1, slen - pos + 1, &errstr);
		if (errstr)
			errx(1, "length is %s", errstr);
	}

	string = string + pos - 1;
	string[length] = '\0';

	(void)printf("%s\n", string);
	return 0;
}

void
usage(void) {
	(void)fprintf(stderr, "usage: %s string pos length\n", getprogname());
	exit(1);
}

