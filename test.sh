#!/bin/bash
make
./a.out > /tmp/a.out

str="12345
Something
1"

if [[ "$(cat /tmp/a.out)" == $str ]]; then
	echo "Everything is OK!"
else
	echo "Something is wrong!"
fi
rm /tmp/a.out
rm a.out
