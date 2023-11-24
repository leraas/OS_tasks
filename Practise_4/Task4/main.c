#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        if (clearenv() == 0) {
            printf("All environment variables have been cleared.\n");
        } else {
            perror("Error clearing the environment");
            return -1;
        }
    } else if (argc == 2) {
        if (unsetenv(argv[1]) == 0) {
            printf("Variable %s has been removed.\n", argv[1]);
        } else {
            perror("Error removing environment variable");
            return -1;
        }
    } else {
        printf("Incorrect usage of the program. Usage: %s [VARIABLE_NAME]\n", argv[0]);
        return -1;
    }

    extern char **environ;
    if (environ == NULL) {
        printf("The environment is empty.\n");
    } else {
        char **env_var = environ;
        while (*env_var) {
            printf("%s\n", *env_var);
            env_var++;
        }
    }

    return 0;
}
