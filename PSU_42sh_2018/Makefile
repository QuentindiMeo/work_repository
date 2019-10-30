##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

SRC	=	src/error.c		\
		src/redirections/redirect_simple_left.c		\
		src/redirections/redirect_double_left.c		\
		src/redirections/redirect_simple_right.c	\
		src/redirections/redirect_double_right.c	\
		src/mysh_functions/unsetenv.c	\
		src/mysh_functions/setenv.c	\
		src/mysh_functions/env.c	\
		src/mysh_functions/cd.c		\
		src/execute_prog.c	\
		src/execute_prog2.c	\
		src/calls.c		\
		src/history_command.c	\
		src/get_nth_command.c	\
		src/detectors2.c	\
		src/detectors.c		\
		src/free_prompt.c	\
		src/main_mysh.c		\
		src/memory.c		\
		src/analyse_ret.c	\
		src/check_file.c	\
		src/history.c		\

OBJ	=	$(SRC:.c=.o)

LIB	=	lib/my/libmy.a

HEADER_PATH	=	include/

CC	=	@gcc

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic -g3

NAME	=	42sh

.PHONY: clean fclean re tests_run

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo Compiling $(NAME)
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo $(NAME) compiled

$(LIB):
	@echo Compiling lib;
	@$(MAKE) -C lib/my

clean:
	@echo Cleaning .o, $(NAME)
	@rm -rf $(OBJ)
	@make clean -C lib/my
	@$(MAKE) -C tests clean

fclean: clean
	@echo Cleaning $(NAME)
	@rm -rf $(NAME)
	@make fclean -C lib/my
	@$(MAKE) -C tests fclean

tests_run: fclean
	@$(MAKE) -C tests
	@./unit_tests
	@gcovr
	@gcovr --branches

re: fclean all
