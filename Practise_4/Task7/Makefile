CC = gcc
CFLAGS = -Wall
OBJS = env_func.o main.o
EXEC = my_environment_manager
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f $(OBJS) $(EXEC)
