##
## EPITECH PROJECT, 2021
## C Pool Day 10
## File description:
## makefile
##

SRC	=	my_getnbr.c										\
		my_itos.c										\
		my_putchar.c									\
		my_put_nbr.c									\
		my_putstr.c										\
		my_revstr.c										\
		my_strcat.c										\
		my_strcmp.c										\
		my_strcpy.c										\
		my_strdup.c										\
		my_str_to_word_array.c							\
		my_strlen.c										\
		my_strncat.c									\
		my_strncmp.c									\
		my_strncpy.c									\
		my_strstr.c										\
		my_compute_power_rec.c							\
		my_convert_decimal_to_base.c					\
		my_printf.c										\
		my_atoi.c										\
		my_get_index.c									\
		./printf_utilities/handler_convert.c			\
		./printf_utilities/handler_put_nbr.c			\
		./printf_utilities/handler_put_str_and_char.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -pedantic

NAME	=	libmy.a

#--------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ./../
	cp my.h ./../../include/

clean:
	rm -f *.o

fclean:
	rm -f $(OBJ) $(NAME) ./../../include/my.h

re: fclean all

.PHONY: re fclean clean all
