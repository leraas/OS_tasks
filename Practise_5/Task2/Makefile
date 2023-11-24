CC = gcc
CFLAGS = -Wall

all: main

main: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f main main.o

.PHONY: all clean
