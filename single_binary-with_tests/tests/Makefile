##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for single_binary's unit tests
## (Makefile for tests)
## Dependencies:
## - Makefile for the my_hello_world library (depends of the my_putstr library)
## - Makefile for the my_putstr library
## Syntax notes:
## - Rules and variables are sorted in alphabetical order
## - Path values mustn't end with a slash
## Last revision: 02/05/2019
##

CFLAGS						+=	-Wall -Wextra -Werror -Wpedantic -pedantic-errors

CPPFLAGS					+=	-I $(PATH_HEADERS)/

LDFLAGS						+=	-l criterion -L $(PATH_LIB_OUTPUT)/ $(addprefix -l, $(LIBS)) -o $(EXEC)

EXEC						=	unit_tests

GCOV_FILES					=	$(SRC:.c=.gcda) $(SRC:.c=.gcno) $(SRC:.c=.c.gcov)

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

$(EXEC):					$(LIB_PUTSTR_FILE) $(LIB_HELLO_WORLD_FILE) $(OBJ)
	cd .. && $(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) $(LDFLAGS)

.PHONY:						all
all:						$(EXEC)

.PHONY:						clean
clean:						clean_lib_hello_world clean_lib_putstr
	cd .. && $(RM) $(OBJ)

.PHONY:						fclean
fclean:						fclean_lib_hello_world fclean_lib_putstr
	cd .. && $(RM) $(OBJ)
	cd .. && $(RM) $(GCOV_FILES)
	cd .. && $(RM) $(EXEC)

.PHONY:						re
re:							fclean all

$(LIB_HELLO_WORLD_FILE):
	$(MAKE) -C $(PATH_LIB_HELLO_WORLD_SRC)/

.PHONY:						clean_lib_hello_world
clean_lib_hello_world:
	$(MAKE) -C $(PATH_LIB_HELLO_WORLD_SRC)/ clean

.PHONY:						fclean_lib_hello_world
fclean_lib_hello_world:
	$(MAKE) -C $(PATH_LIB_HELLO_WORLD_SRC)/ fclean

$(LIB_PUTSTR_FILE):
	$(MAKE) -C $(PATH_LIB_PUTSTR_SRC)/

.PHONY:						clean_lib_putstr
clean_lib_putstr:
	$(MAKE) -C $(PATH_LIB_PUTSTR_SRC)/ clean

.PHONY:						fclean_lib_putstr
fclean_lib_putstr:
	$(MAKE) -C $(PATH_LIB_PUTSTR_SRC)/ fclean

# We add "cd .." because gcov can't read the relative path to coverage files if source files were in a parent directory during compilation, so we have to cd to the root directory
$(PATH_OBJ)/%.o:			%.c
	cd .. && $(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

.PHONY:						tests_run
tests_run:					re
	../$(EXEC)
