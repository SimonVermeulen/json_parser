##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -Wall -Wextra -pedantic

LFLAGS =	-L./lib -llist -ljson_parser -lm

NAME	=	

#------------------------------

all:	$(NAME)

$(NAME): build_lib build

build_lib:
	$(MAKE) -C ./lib/linked_list --silent
	$(MAKE) -C ./lib/json_parser --silent

build: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LFLAGS)

clean_lib:
	$(MAKE) -C ./lib/linked_list --silent clean
	$(MAKE) -C ./lib/json_parser --silent clean

fclean_lib:
	$(MAKE) -C ./lib/linked_list --silent fclean
	$(MAKE) -C ./lib/json_parser --silent fclean
	rm -f lib/liblist.a
	rm -f lib/libjson_parser.a

clean: clean_lib
	rm -f $(OBJ)

fclean: fclean_lib clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean fclean_lib clean_lib build build_lib all
