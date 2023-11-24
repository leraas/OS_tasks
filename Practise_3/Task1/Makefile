CC = gcc
CFLAGS = -Wall -Wextra
SRC = main.c
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLE)
