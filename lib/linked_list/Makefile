##
## EPITECH PROJECT, 2021
## linked list
## File description:
## makefile
##

SRC	=	add_delete_element.c	\
		create_empty_list.c		\
		add_delete_node.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -pedantic

NAME	=	liblist.a

#--------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ./../
	cp linked_list.h ./../../include/

clean:
	rm -f *.o

fclean:
	rm -f $(OBJ) $(NAME) ./../../include/linked_list.h

re: fclean all

.PHONY: re fclean clean all
