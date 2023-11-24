#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

void print_environment();
void print_variable(const char *variable_name);
void set_variable(const char *variable_name, const char *value);
void assign_variable(const char *variable_name, const char *value);
void delete_variable(const char *variable_name);
void clear_environment();
void print_help();
#endif
