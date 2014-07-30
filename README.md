substr
======

An utility to extract substring from a string, inspired by the GNU
`expr` extension of the same name. This implementation is under
the ISC licence.

Read the man page for more information:

    mandoc substr.1 | less

Example
-------

    $ substr hello 1 2
    he
    $ substr "Omelette du fromage" 13 7
    fromage
    $ substr toto 2
    oto
