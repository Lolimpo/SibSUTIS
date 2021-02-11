CC = g++
CFLAGS = -Wall

bin/main: build/main.o build/SimpleComputer.o build/myTerm.o build/myBigChars.o build/myReadKey.o build/CPU.o build/timer.o bin
	$(CC) $(CFLAGS) build/main.o build/SimpleComputer.o build/myTerm.o build/myBigChars.o build/myReadKey.o build/CPU.o build/timer.o -o bin/main

build/main.o: main.cpp SCLib.h build
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

build/SimpleComputer.o: SimpleComputer.cpp SCLib.h build
	$(CC) $(CFLAGS) -c SimpleComputer.cpp -o build/SimpleComputer.o

build/myTerm.o: myTerm.cpp SCLib.h build
	$(CC) $(CFLAGS) -c myTerm.cpp -o build/myTerm.o

build/myBigChars.o: myBigChars.cpp SCLib.h build
	$(CC) $(CFLAGS) -c myBigChars.cpp -o build/myBigChars.o

build/myReadKey.o: myReadKey.cpp SCLib.h build
	$(CC) $(CFLAGS) -c myReadKey.cpp -o build/myReadKey.o

build/CPU.o: CPU.cpp SCLib.h build
	$(CC) $(CFLAGS) -c CPU.cpp -o build/CPU.o

build/timer.o: timer.cpp SCLib.h build
	$(CC) $(CFLAGS) -c timer.cpp -o build/timer.o

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin
