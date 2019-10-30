##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c	\
		my_getnbr.c		\
		my_putchar.c		\
		my_putchar_err.c	\
		my_put_nbr.c		\
		my_putstr.c		\
		my_puterr.c		\
		my_strlen.c		\
		vartype_conv.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
