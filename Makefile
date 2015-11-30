CC = g++
CFLAGS = -g -std=c++11 -Wall
INSTALLPATH = ./
EXECUTABLE = idk

all: idk

idk: main.o util.o
	$(CC) $(CFLAGS) main.o util.o -o $(EXECUTABLE)

main.o: main.cpp util.h
	$(CC) $(CFLAGS) -c main.cpp

util.o: util.cpp util.h
	$(CC) $(CFLAGS) -c util.cpp


clean:
	rm -rf *.o $(EXECUTABLE)
