##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	src/json_parser.c	\
		src/get_buffer.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -Wall -Wextra -pedantic

LFLAGS =	-L./lib -lmy

NAME	=	json_parser

#------------------------------

all:	$(NAME)

$(NAME): build_lib build

build_lib:
	$(MAKE) -C ./lib/my/ --silent
	cp ./lib/my/libmy.a ./lib/libmy.a
	cp ./lib/my/my.h ./include/my.h

build: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LFLAGS)

clean_lib:
	$(MAKE) -C ./lib/my --silent clean

fclean_lib:
	$(MAKE) -C ./lib/my --silent fclean
	rm -f lib/libmy.a

clean: clean_lib
	rm -f $(OBJ)

fclean: fclean_lib clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean fclean_lib clean_lib build build_lib all
