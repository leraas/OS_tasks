#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

int executeCommand(char *command) {
    int result = system(command);
    return result;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter commands (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove the trailing newline character if it exists
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *token = strtok(input, ";");

        while (token != NULL) {
            // Trim leading and trailing white spaces from the command
            while (isspace((unsigned char)*token)) {
                token++;
            }
            char *end = token + strlen(token) - 1;
            while (end > token && isspace((unsigned char)*end)) {
                *end-- = '\0';
            }

            if (strlen(token) > 0) {
                printf("Executing command: %s\n", token);
                int result = executeCommand(token);
                printf("Exit code: %d\n", result);
            }
            token = strtok(NULL, ";");
        }
    }

    return 0;
}
