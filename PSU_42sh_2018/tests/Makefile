##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

SRC	=	../src/error.c			\
		../src/redirections/redirect_simple_left.c		\
		../src/redirections/redirect_double_left.c		\
		../src/redirections/redirect_simple_right.c		\
		../src/redirections/redirect_double_right.c		\
		../src/mysh_functions/unsetenv.c	\
		../src/mysh_functions/setenv.c		\
		../src/mysh_functions/env.c		\
		../src/mysh_functions/cd.c		\
		../src/execute_prog.c	\
		../src/execute_prog2.c	\
		../src/calls.c		\
		../src/get_nth_command.c\
		../src/detectors2.c	\
		../src/detectors.c	\
		../src/free_prompt.c	\
		../src/main_mysh.c	\
		../src/memory.c		\
		../src/analyse_ret.c	\
		../src/check_file.c	\
		../src/history_command.c\
		../src/history.c	\

SRCC	=	f_command.c		\
		f_cd.c			\
		f_miscellaneous.c	\
		f_redirect1.c		\
		criterion_util.c

OBJ	=	$(SRC:.c=.o)

LIB	=	../lib/my/libmy.a

HEADER_PATH	=	../include/

CC	=	@gcc

CFLAGS	=	-I $(HEADER_PATH) -g3 -Wall --pedantic -Werror --coverage

NAME	=	../42sh

NAMEC	=	../unit_tests

.PHONY: clean fclean

all: $(NAMEC)

$(NAMEC): $(OBJ) $(LIB)
	@echo Compiling $(NAME)
	$(CC) -o $(NAME) $(OBJ) $(LIB) --coverage
	@echo $(NAME) compiled
	@echo Compiling $(NAMEC)
	$(CC) -o $(NAMEC) $(SRCC) -I $(HEADER_PATH) -lcriterion
	@echo $(NAMEC) compiled
	@echo clean .o
	@rm -rf $(OBJ)

$(LIB):
	@echo Compiling lib;
	@$(MAKE) -C ../lib/my

clean:
	@echo Cleaning gcda gcno
	@rm -rf ../src/*.gcda
	@rm -rf ../src/*.gcno

fclean:
	@echo Cleaning $(NAMEC)
	@rm -rf $(NAMEC)
