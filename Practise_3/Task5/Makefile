CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

SOURCES = main.c
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
