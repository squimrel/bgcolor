CC = g++
CFLAGS = -I .. -std=c++14 -O3 -Wall -Wextra -Wpedantic -Wsign-conversion
LDFLAGS = -lpng
OBJECTS = main.o png.o utilities.o

all: bgcolor

bgcolor: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bgcolor

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) bgcolor
