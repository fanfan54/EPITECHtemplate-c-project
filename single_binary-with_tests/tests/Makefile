##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for single_binary's unit tests
## (Makefile for Criterion unit tests)
## Dependencies:
## - Makefile for the my_hello_world library (depends on the my_putstr library)
## - Makefile for the my_putstr library
## Syntax notes:
## - Rules and variables are sorted in alphabetical order
## - Path values mustn't end with a slash
## Last revision: 02/05/2019
##

CFLAGS							+=	-Wall -Wextra -Werror -Wpedantic -pedantic-errors --coverage

CPPFLAGS						+=	-I $(PATH_HEADERS)/

LDFLAGS							+=	-l criterion -L $(RELATIVE_PATH_LIB_DIR)/ $(addprefix -l, $(LIBS)) -o $(EXEC)

EXEC							=	unit_tests

LIBS							=	my_hello_world						\
									my_putstr

OBJ								=	$(addprefix $(PATH_OBJ_DIR)/, $(SRC:.c=.o))

SRC								=	src/globals.c						\
									src/parse_main_args.c				\
									src/single_binary.c

PATH_GCOV_FILES					=	$(SRC:.c=.gcda) $(SRC:.c=.gcno) $(SRC:.c=.c.gcov)

PATH_HEADERS					=	include

PATH_LIB_ARCHIVES				=	$(addprefix $(PATH_LIB_DIR)/lib, $(addsuffix .a, $(LIBS)))

PATH_LIB_DIR					=	../$(RELATIVE_PATH_LIB_DIR)

PATH_OBJ_DIR					=	obj

PATH_OBJ_FILES					=	$(addprefix $(PATH_OBJ_DIR)/, $(SRC:.c=.o))

RELATIVE_PATH_LIB_DIR			=	libs

$(EXEC):						libs $(OBJ)
	cd .. && $(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) $(LDFLAGS)

.PHONY:							all
all:							$(EXEC)

.PHONY:							clean
clean:							clean_libs
	cd .. && $(RM) $(OBJ)

.PHONY:							clean_libs
clean_libs:						$(addprefix clean_, $(PATH_LIB_ARCHIVES))

.PHONY:							debug
debug:							debug_libs $(OBJ)
	cd .. && $(CC) $(CPPFLAGS) $(CFLAGS) -g3 $(OBJ) $(LDFLAGS)

.PHONY:							debug_libs
debug_libs:						$(addprefix debug_, $(PATH_LIB_ARCHIVES))

.PHONY:							fclean
fclean:							fclean_libs
	cd .. && $(RM) $(OBJ)
	cd .. && $(RM) $(EXEC)
	cd .. && $(RM) $(GCOV_FILES)

.PHONY:							fclean_libs
fclean_libs:					$(addprefix fclean_, $(PATH_LIB_ARCHIVES))

.PHONY:							libs
libs:							$(PATH_LIB_ARCHIVES)

.PHONY:							re
re:								fclean all

.PHONY:							tests_run
tests_run:						re
	../$(EXEC)

$(PATH_OBJ_DIR)/%.o:			%.c
	mkdir -p $(PATH_OBJ_DIR)/$(<D)
	cd .. && $(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(PATH_OBJ_DIR)/$(<:.c=.o)

$(PATH_LIB_DIR)/lib%.a:			$(PATH_LIB_DIR)/%
	$(MAKE) -C $<

clean_$(PATH_LIB_DIR)/lib%.a:	$(PATH_LIB_DIR)/%
	$(MAKE) -C $< clean

debug_$(PATH_LIB_DIR)/lib%.a:	$(PATH_LIB_DIR)/%
	$(MAKE) -C $< debug

fclean_$(PATH_LIB_DIR)/lib%.a:	$(PATH_LIB_DIR)/%
	$(MAKE) -C $< fclean
