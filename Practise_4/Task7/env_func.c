#include <stdio.h>
#include <stdlib.h>
#include "env_func_head.h"

extern char **environ;

void print_environment() {
    char **env = environ;
    if (env == NULL || *env == NULL) {
        printf("Environment is empty.\n");
    } else {
        while (*env) {
            printf("%s\n", *env);
            env++;
        }
    }
}

void print_variable(const char *variable_name) {
    char *value = getenv(variable_name);
    if (value != NULL) {
        printf("%s=%s\n", variable_name, value);
    } else {
        printf("Variable %s is not present in the environment.\n", variable_name);
    }
}

void set_variable(const char *variable_name, const char *value) {
    setenv(variable_name, value, 1);
    printf("%s=%s\n", variable_name, value);
}

void assign_variable(const char *variable_name, const char *value) {
    if (value != NULL) {
        setenv(variable_name, value, 1);
        printf("%s=%s\n", variable_name, value);
    } else {
        unsetenv(variable_name);
        printf("Variable %s has been removed from the environment.\n", variable_name);
    }
}

void delete_variable(const char *variable_name) {
    unsetenv(variable_name);
    printf("Variable %s has been removed from the environment.\n", variable_name);
}

void clear_environment() {
    clearenv();
    printf("\nEnvironment has been cleaned!\n");
}

void print_help() {
    printf("Help:\n");
    printf("-h, --help\t\tShow this help message\n");
    printf("-i, --info <variable>\tDisplay the value of an environment variable\n");
    printf("-s, --set <variable=value>\tSet the value of an environment variable\n");
    printf("-a -v <variable> [value]\tAssign a new value to an environment variable\n");
    printf("-d, --del <variable>\tDelete an environment variable\n");
    printf("-c, --clear\t\tClear the entire environment\n");
}
