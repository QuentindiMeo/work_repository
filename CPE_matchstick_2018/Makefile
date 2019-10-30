##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/game_loop.c		\
		src/error.c		\
		src/malloc_free.c	\
		src/detectors2.c	\
		src/detectors.c		\
		src/setup2.c		\
		src/setup.c		\
		src/ai.c		\
		src/main_matchstick.c	\

CC	=	gcc -o

CFLAGS	+=	-Wall -Werror

LIB	=	lib/my/libmy.a

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

.PHONY:	all clean fclean re
