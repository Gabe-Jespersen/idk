CC = g++
CFLAGS = -g -std=c++11 -Wall
INSTALLPATH = ./
EXECUTABLE = idk

all: idk

idk: main.o util.o cycle.o
	$(CC) $(CFLAGS) main.o util.o cycle.o -o $(EXECUTABLE)

main.o: main.cpp util.h cycle.h
	$(CC) $(CFLAGS) -c main.cpp

util.o: util.cpp util.h
	$(CC) $(CFLAGS) -c util.cpp

cycle.o: cycle.cpp cycle.h
	$(CC) $(CFLAGS) -c cycle.cpp


clean:
	rm -rf *.o $(EXECUTABLE)
