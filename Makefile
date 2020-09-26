CFLAGS=-c -I include
run: main.o Ini.o
	g++ main.o Ini.o
main.o: main.cpp
	g++ $(CFLAGS) include main.cpp
Ini.o: src/Ini.cpp
	g++ $(CFLAGS) src/Ini.cpp
clean:
	rm main.o
	rm Ini.o
