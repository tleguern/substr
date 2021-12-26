# substr

An utility to extract substring from a string, inspired by the GNU
`expr` extension of the same name. This implementation is under
the ISC licence.

## Contents

1. [Install](#install)
2. [Instructions](#instruction)
3. [Examples](#examples)
4. [License](#license)

## Install

### Requires

* C compiler ;
* libbsd on Linux.

### Build

On OpenBSD:

    $ make
    $ DESTDIR=~/ make install # or doas make install

On Linux:

    $ LDADD=-lbsd CFLAGS="-D NEED_LIBBSD" make
    $ DESTDIR=~/ make install # or sudo make install

## Instructions

To see a description of the options see the [man](./substr.md) page.

## Example

    $ substr hello 1 2
    he
    $ substr "Omelette du fromage" 13 7
    fromage
    $ substr toto 2
    oto

## License

All the code is licensed under the ISC License.
