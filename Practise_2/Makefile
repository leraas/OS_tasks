CC = gcc
CFLAGS = -Wall
LDFLAGS =

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = slot_machine

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
