CFLAGS=-c -I include -g
run: test.o Ini.o
	g++ test.o Ini.o
test.o: test.cpp
	g++ $(CFLAGS) test.cpp
Ini.o: src/Ini.cpp
	g++ $(CFLAGS) src/Ini.cpp
clean:
	rm test.o
	rm Ini.o
