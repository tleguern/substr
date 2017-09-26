#!/bin/sh
# Tristan Le Guern <tleguern@bouledef.eu>
# Public domain

FAILED=0

substr=${substr:-../substr}

t() {
	# $1 -> exit code
	# $2 -> expected result
	# $3 -> $test expression
	echo "Run $substr \"$3\", expect exit code $1 and string \"$2\""

	ret=$($substr $3)
	if [ $? -ne $1 ]; then
		failed
		return
	fi
	if [ "$ret" != "$2" ]; then
		failed
		return
	fi
	echo OK
}

failed() {
	echo "Failed"
	FAILED=`expr $FAILED + 1`
}

t 0 'he' 'hello 1 2'
t 0 'oto' 'toto 2'
t 1 '' 'hello'
t 1 '' 'hello -1 1'
t 1 '' 'hello 1 -1'
t 1 '' 'hello 0 0'
t 1 '' 'hello 1 0'
t 1 '' 'hello 0 1'
t 1 '' 'hello 6'

echo ""
echo "Failed: $FAILED"
[ $FAILED -gt 0 ] && exit 1
exit 0

