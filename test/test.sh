#!/bin/bash
g++ test.cpp ../Ini.cpp -I ../
./a.out > /tmp/a.out

str="name = John
surname = Smith
email = john.smith@example.com
age = 32"

if [[ "$(cat /tmp/a.out)" == $str ]]; then
	echo "Everything is OK!"
else
	echo "Something is wrong!"
fi
rm /tmp/a.out
rm a.out
rm test.ini
