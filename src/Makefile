CC=g++
CFLAGS=-I .. -std=c++14 -O3 -Wall -Wextra -Wpedantic -Wsign-conversion -c

all: bgcolor

bgcolor: main.o png.o
	$(CC) main.o png.o -o bgcolor

main.o: main.cc
	$(CC) $(CFLAGS) main.cc -o main.o

png.o: png.cc
	$(CC) $(CFLAGS) png.cc -o png.o

clean:
	rm main.o png.o bgcolor
