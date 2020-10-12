CFLAGS=-c -g -I ../
run: test.o Ini.o
	g++ test.o Ini.o
test.o: test.cpp
	g++ $(CFLAGS) test.cpp
Ini.o: ../Ini.cpp
	g++ $(CFLAGS) ../Ini.cpp
clean:
	rm test.o
	rm Ini.o
