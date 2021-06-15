#!/bin/bash
g++ test.cpp ../Ini.cpp -I ../
./a.out > /tmp/a.out

str="name = John
surname = Smith
email = john.smith@example.com
age = 32
name = Mark
surname = Adams
email = mark.adams@example.com
age = 44
Sections number = 2"

if [[ "$(cat /tmp/a.out)" == $str ]]; then
	echo "Everything is OK!"
else
	echo "Something is wrong!"
fi
rm /tmp/a.out
rm a.out
rm test.ini
