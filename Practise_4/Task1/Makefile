
CC = gcc
CFLAGS = -Wall -std=c99

TARGET = myprogram

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.DEFAULT_GOAL := run
