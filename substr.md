substr(1) - General Commands Manual

# NAME

**substr** - extract substring from a string

# SYNOPSIS

**substr**
*string*
*pos*
\[*length*]

# DESCRIPTION

The
**substr**
utility extracts
*length*
characters from
*string*
starting at position
*pos*.

*length*
should be &gt;0 and not greater than
*pos*,
which should not be greater than the size of
*string*.
The numbering of
*pos*
starts at one, not zero.

If
*length*
is not supplied, the substring starting from
*pos*
to the end of
*string*
will be returned.

# EXIT STATUS

The **substr** utility exits&#160;0 on success, and&#160;&gt;0 if an error occurs.

# COMPATIBILITY

This section provides a list of compatibility issues between
**substr**
and the original GNU extension to
expr(1).

The following behaviours differ from the canonical implementation:

-	The parameters
	*pos*
	and
	*length*
	should always be positive;
-	The third parameter,
	*length*,
	is optional;
-	**substr**
	never returns with a value of 2 or 3.

# SEE ALSO

expr(1)

# HISTORY

The
**substr**
utility first appeared as an extension to the GNU implementation of
expr(1).
This standalone implementation appeared during
OpenBSD 5.5.

# AUTHORS

The
**substr**
utility was written by
Tristan Le Guern &lt;[tleguern@bouledef.eu](mailto:tleguern@bouledef.eu)&gt;.

OpenBSD 7.0 - December 26, 2021
