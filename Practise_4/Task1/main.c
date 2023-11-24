#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main() {
    char** env_var = environ;
    int i = 0;
    while (env_var[i] != NULL) {
        printf("%s\n", env_var[i]);
        i++;
    }

    return 0;
}
