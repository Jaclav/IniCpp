#!/bin/bash
make
./a.out > /tmp/a.out

str="Name = John
Surname = Smith
email = johnsmith@example.com
age = 32"

if [[ "$(cat /tmp/a.out)" == $str ]]; then
	echo "Everything is OK!"
else
	echo "Something is wrong!"
fi
rm /tmp/a.out
rm a.out
