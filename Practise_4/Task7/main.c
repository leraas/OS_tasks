#include <stdio.h>
#include <string.h>
#include "env_func_head.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        print_environment();
    } else {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            print_help();
        } else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0) {
            if (argc == 3) {
                print_variable(argv[2]);
            } else {
                fprintf(stderr, "Error: Specify a variable for the -i/--info option\n");
            }
        } else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0) {
            if (argc == 4) {
                set_variable(argv[2], argv[3]);
                print_environment();
            } else {
                fprintf(stderr, "Error: Specify a variable and value for the -s/--set option\n");
            }
        } else if (strcmp(argv[1], "-a") == 0 && strcmp(argv[3], "-v") == 0) {
            if (argc == 4) {
                assign_variable(argv[2], NULL);
                print_environment();
            } else if (argc == 5) {
                assign_variable(argv[2], argv[4]);
                print_environment();
            } else {
                fprintf(stderr, "Error: Specify a variable and, if needed, a value for the -a -v option\n");
            }
        } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0) {
            if (argc == 3) {
                delete_variable(argv[2]);
                print_environment();
            } else {
                fprintf(stderr, "Error: Specify a variable for the -d/--del option\n");
            }
        } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0) {
            clear_environment();
            print_environment();
        } else {
            fprintf(stderr, "Error: Unknown option. Use -h or --help for help.\n");
        }
    }
    return 0;
}
