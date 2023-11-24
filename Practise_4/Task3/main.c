#include <stdio.h>
#include <stdlib.h>

void printUsage(const char *programName) {
    printf("Usage: %s <new_variable> <new_value>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return 1;
    }

    const char *new_variable = argv[1];
    const char *new_value = argv[2];

    if (setenv(new_variable, new_value, 1) != 0) {
        perror("Error setting environment variable");
        return 1;
    }

    char *environment_value = getenv(new_variable);
    if (environment_value == NULL) {
        printf("Failed to retrieve environment variable %s.\n", new_variable);
        return 1;
    } else {
        printf("Environment variable: %s\nValue: %s\n", new_variable, environment_value);
    }

    return 0;
}
