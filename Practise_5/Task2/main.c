#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int num_handlers;

void signal_handler(int signum) {
    static int count = 0;
    count++;
    printf("Handler %d: Delaying for 1 second. Signal %d received.\n", count, signum);
    sleep(1);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <number_of_handlers>\n", program_name);
}

int install_signal_handlers() {
    for (int i = 1; i <= num_handlers; i++) {
        if (signal(SIGINT, signal_handler) == SIG_ERR) {
            perror("Error registering handler for SIGINT");
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    num_handlers = atoi(argv[1]);

    if (num_handlers < 1) {
        printf("Number of handlers should be greater than 0.\n");
        return 1;
    }

    if (install_signal_handlers() != 0) {
        return 1;
    }

    printf("Waiting for process termination handlers. PID = %d\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}
