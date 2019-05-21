##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for single_binary
## (Makefile for a single binary, with Criterion unit tests)
## Dependencies:
## - Makefile for the my_hello_world library (depends on the my_putstr library)
## - Makefile for the my_putstr library
## - Makefile for single_binary's Criterion unit tests
## Syntax notes:
## - Rules and variables are sorted in alphabetical order
## - Path values mustn't end with a slash
## Last revision: 02/05/2019
##

CFLAGS							+=	-Wall -Wextra -Werror -Wpedantic -pedantic-errors

CPPFLAGS						+=	-I $(PATH_HEADERS)/

LDFLAGS							+=	-L $(PATH_LIB_DIR)/ $(addprefix -l, $(LIBS)) -o $(EXEC)

EXEC							=	single_binary

LIBS							=	

OBJ								=	$(addprefix $(PATH_OBJ_DIR)/, $(SRC:.c=.o))

SRC								=	src/globals.c						\
									src/main.c							\
									src/parse_main_args.c				\
									src/single_binary.c

PATH_HEADERS					=	include

PATH_LIB_ARCHIVES				=	$(addprefix $(PATH_LIB_DIR)/lib, $(addsuffix .a, $(LIBS)))

PATH_LIB_DIR					=	libs

PATH_OBJ_DIR					=	obj

PATH_OBJ_FILES					=	$(addprefix $(PATH_OBJ_DIR)/, $(SRC:.c=.o))

PATH_TESTS						=	tests

$(EXEC):						libs $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) $(LDFLAGS)

.PHONY:							all
all:							$(EXEC)

.PHONY:							clean
clean:							clean_tests
	$(RM) $(OBJ)

.PHONY:							clean_tests
clean_tests:
	$(MAKE) -C $(PATH_TESTS)/ clean

.PHONY:							debug
debug:							debug_libs $(addprefix debug_, $(OBJ))
	$(CC) $(CPPFLAGS) $(CFLAGS) -g3 $(OBJ) $(LDFLAGS)

.PHONY:							debug_libs
debug_libs:						$(addprefix debug_, $(PATH_LIB_ARCHIVES))

.PHONY:							fclean
fclean:							fclean_tests
	$(RM) $(OBJ)
	$(RM) $(EXEC)

.PHONY:							fclean_tests
fclean_tests:
	$(MAKE) -C $(PATH_TESTS)/ fclean

.PHONY:							libs
libs:							$(PATH_LIB_ARCHIVES)

.PHONY:							re
re:								fclean all

.PHONY:							tests_run
tests_run:
	$(MAKE) -C $(PATH_TESTS)/ tests_run

$(PATH_OBJ_DIR)/%.o:			%.c
	mkdir -p $(PATH_OBJ_DIR)/$(<D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(PATH_OBJ_DIR)/$(<:.c=.o) $<

debug_$(PATH_OBJ_DIR)/%.o:		%.c
	mkdir -p $(PATH_OBJ_DIR)/$(<D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -g3 -c -o $(PATH_OBJ_DIR)/$(<:.c=.o) $<

$(PATH_LIB_DIR)/lib%.a:			$(PATH_LIB_DIR)/%
	$(MAKE) -C $<

debug_$(PATH_LIB_DIR)/lib%.a:	$(PATH_LIB_DIR)/%
	$(MAKE) -C $< debug
