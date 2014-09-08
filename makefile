CC=g++
CFLAGS=-c -Wall

all: guessgam

guessgam: guessgam.o guessgamLogic.o
	$(CC) guessgam.o guessgamLogic.o -o guessgam

guessgam.o: guessgam.cpp
	$(CC) $(CFLAGS) guessgam.cpp

guessgamLogic.o: guessgamLogic.cpp
	$(CC) $(CFLAGS) guessgamLogic.cpp

clean:
	rm -rf *o guessgam
