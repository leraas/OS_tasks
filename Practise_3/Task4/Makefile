CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
SOURCES = main.c
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)
