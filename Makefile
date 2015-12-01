CC = g++
CFLAGS = -g -std=c++11 -Wall
INSTALLPATH = ./
EXECUTABLE = idk

all: idk

idk: main.o util.o cycle.o fight.o
	$(CC) $(CFLAGS) main.o util.o cycle.o fight.o -o $(EXECUTABLE)

main.o: main.cpp util.h cycle.h
	$(CC) $(CFLAGS) -c main.cpp

util.o: util.cpp util.h
	$(CC) $(CFLAGS) -c util.cpp

cycle.o: cycle.cpp cycle.h util.h
	$(CC) $(CFLAGS) -c cycle.cpp

fight.o: fight.cpp fight.h util.h
	$(CC) $(CFLAGS) -c fight.cpp


clean:
	rm -rf *.o $(EXECUTABLE)
