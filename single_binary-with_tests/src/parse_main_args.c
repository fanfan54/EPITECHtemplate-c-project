/*
** EPITECH PROJECT, 2019
** parse_main_args
** File description:
** Parse the arguments given to the executable.
*/

#include <stdio.h>
#include <string.h>
#include "single_binary.h"

static int print_main_usage(char const *exec_name)
{
    printf("Usage:\t%s [OPTION]\n", exec_name);
    printf("Prints \"Hello World!\" to stdout, using libraries.\n\n");
    printf("Options:\n");
    printf(" -h\t\tDisplay this help message.\n");
    return (RETURN_MAIN_USAGE);
}

int parse_main_args(int argc, char * const *argv,
    __attribute__((unused)) char * const *envp)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return (print_main_usage(argv[0]));
    return (single_binary());
}
