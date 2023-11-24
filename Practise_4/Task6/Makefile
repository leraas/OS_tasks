CC = gcc
CFLAGS = -Wall

EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): main.o
	$(CC) $(CFLAGS) -o $@ main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(EXECUTABLE) main.o
