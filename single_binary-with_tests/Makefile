##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for single_binary
## (Makefile for a single binary, with unit tests)
## Dependencies:
## - Makefile for the my_hello_world library (depends of the my_putstr library)
## - Makefile for the my_putstr library
## - Makefile for single_binary's unit tests
## Syntax notes:
## - Rules and variables are sorted in alphabetical order
## - Path values mustn't end with a slash
## Last revision: 02/05/2019
##

CFLAGS						+=	-Wall -Wextra -Werror -Wpedantic -pedantic-errors

CPPFLAGS					+=	-I $(PATH_HEADERS)/

LDFLAGS						+=	-L $(PATH_LIB_OUTPUT)/ $(addprefix -l, $(LIBS)) -o $(EXEC)

EXEC						=	single_binary

LIBS						=	my_hello_world						\
								my_putstr

OBJ							=	$(addprefix $(PATH_OBJ)/, $(SRC:.c=.o))

SRC							=	src/globals.c						\
								src/main.c							\
								src/parse_main_args.c				\
								src/single_binary.c

LIB_HELLO_WORLD_FILE		=	$(PATH_LIB_OUTPUT)/libmy_hello_world.a

PATH_LIB_HELLO_WORLD_SRC	=	$(PATH_LIB_OUTPUT)/my_hello_world

LIB_PUTSTR_FILE				=	$(PATH_LIB_OUTPUT)/libmy_putstr.a

PATH_LIB_PUTSTR_SRC			=	$(PATH_LIB_OUTPUT)/my_putstr

PATH_LIB_OUTPUT				=	libs

PATH_HEADERS				=	include

PATH_OBJ					=	obj

PATH_TESTS					=	tests

$(EXEC):					$(LIB_PUTSTR_FILE) $(LIB_HELLO_WORLD_FILE) $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) $(LDFLAGS)

.PHONY:						all
all:						$(EXEC)

.PHONY:						clean
clean:						clean_tests
	$(RM) $(OBJ)

.PHONY:						debug
debug:						debug_lib_putstr debug_lib_hello_world
	$(CC) $(CPPFLAGS) $(CFLAGS) -g3 $(SRC) $(LDFLAGS)

.PHONY:						fclean
fclean:						fclean_tests
	$(RM) $(OBJ)
	$(RM) $(EXEC)

.PHONY:						re
re:							fclean all

$(LIB_HELLO_WORLD_FILE):
	$(MAKE) -C $(PATH_LIB_HELLO_WORLD_SRC)/

.PHONY:						debug_lib_hello_world
debug_lib_hello_world:
	$(MAKE) -C $(PATH_LIB_HELLO_WORLD_SRC)/ debug

$(LIB_PUTSTR_FILE):
	$(MAKE) -C $(PATH_LIB_PUTSTR_SRC)/

.PHONY:						debug_lib_putstr
debug_lib_putstr:
	$(MAKE) -C $(PATH_LIB_PUTSTR_SRC)/ debug

.PHONY:						tests_run
tests_run:
	$(MAKE) -C $(PATH_TESTS)/ tests_run

.PHONY:						clean_tests
clean_tests:
	$(MAKE) -C $(PATH_TESTS)/ clean

.PHONY:						fclean_tests
fclean_tests:
	$(MAKE) -C $(PATH_TESTS)/ fclean

$(PATH_OBJ)/%.o:				%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
