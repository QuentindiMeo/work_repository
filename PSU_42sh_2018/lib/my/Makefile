##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c	\
		my_arr_add.c		\
		my_array_startswith.c	\
		my_arrdup.c		\
		my_arrdup_enlarge.c	\
		my_charcat.c		\
		my_cut_str.c		\
		my_cut_word_array.c	\
		my_getnbr.c		\
		my_itoa.c		\
		my_putarr.c		\
		my_putchar.c		\
		my_putchar_err.c	\
		my_put_nbr.c		\
		my_put_nbr_err.c	\
		my_putstr.c		\
		my_puterr.c		\
		my_strcat.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isequal.c	\
		my_strlen.c		\
		my_str_startswith.c	\
		my_str_to_word_array.c	\
		vartype_conv.c		\
		my_arr_add.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Library compiled"

clean:
	@rm -f $(OBJ)
	@echo "Library cleaned"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "Library fcleaned"

re:	fclean all
