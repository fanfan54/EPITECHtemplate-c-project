/*
** EPITECH PROJECT, 2019
** single_binary
** File description:
** Header for single_binary.
*/

#ifndef SINGLE_BINARY_H_
    #define SINGLE_BINARY_H_



    extern int const RETURN_MAIN_USAGE;
    extern int const RETURN_SUCCESS;



    int parse_main_args(int argc, char * const *argv,
        __attribute__((unused)) char * const *envp);
    int single_binary(void);



#endif /* !SINGLE_BINARY_H_ */
