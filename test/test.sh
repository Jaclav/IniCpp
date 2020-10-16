#!/bin/bash
make
./a.out > /tmp/a.out

str="name = John
surname = Smith
email = johnsmith@example.com
age = 32
age = 16"

if [[ "$(cat /tmp/a.out)" == $str ]]; then
	echo "Everything is OK!"
else
	echo "Something is wrong!"
fi
rm /tmp/a.out
rm a.out
