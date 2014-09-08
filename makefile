CC=g++
CFLAGS=-c -Wall

all: guessgam

guessgam: guessgam.o
	$(CC) guessgam.o -o guessgam

guessgam.o: guessgam.cpp
	$(CC) $(CFLAGS) guessgam.cpp

clean:
	rm -rf *o guessgam
