CC=g++
CFLAGS=-I .. -std=c++14 -O3 -Wall -Wextra -Wpedantic -Wsign-conversion -c

all: bgcolor

bgcolor: main.o
	$(CC) main.o -o bgcolor

main.o: main.cc
	$(CC) $(CFLAGS) main.cc -o main.o

clean:
	rm main.o bgcolor
