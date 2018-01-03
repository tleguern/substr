substr
======

An utility to extract substring from a string, inspired by the GNU
`expr` extension of the same name. This implementation is under
the ISC licence.

Read the man page for more information with either `mandoc(1)` or `groff(1)`:

    $ mandoc substr.1 | less
    $ groff -m mdoc -Tascii substr.1 | less

In order to run on Linux systems the libbsd package should be installed first.

Installation
------------

On OpenBSD:

    $ make && doas make install

On Linux:

    $ LDADD=-lbsd CFLAGS="-D NEED_LIBBSD" make && sudo make install

Example
-------

    $ substr hello 1 2
    he
    $ substr "Omelette du fromage" 13 7
    fromage
    $ substr toto 2
    oto
