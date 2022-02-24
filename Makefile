##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	src/json_parser.c						\
		src/get_buffer.c						\
		src/stringify.c							\
		src/get_data.c							\
		src/get_key.c							\
		src/type_checkers/check_type.c			\
		src/type_checkers/check_array.c			\
		src/type_checkers/check_object.c		\
		src/type_checkers/check_double.c		\
		src/type_checkers/check_int.c			\
		src/type_checkers/check_string.c		\
		src/value_getters/get_value.c			\
		src/value_getters/get_array.c			\
		src/value_getters/get_object.c			\
		src/value_getters/get_double.c			\
		src/value_getters/get_int.c				\
		src/value_getters/get_string.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -Wall -Wextra -pedantic

LFLAGS =	-L./lib -lmy -llist -lm

NAME	=	json_parser

#------------------------------

all:	$(NAME)

$(NAME): build_lib build

build_lib:
	$(MAKE) -C ./lib/my/ --silent
	$(MAKE) -C ./lib/linked_list --silent
	cp ./lib/my/libmy.a ./lib/libmy.a
	cp ./lib/my/my.h ./include/my.h

build: $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(LFLAGS) -g3

run: $(NAME)
	@echo -e "\n\nEnd of the compilation:\n"
	./json_parser test/easy.json

clean_lib:
	$(MAKE) -C ./lib/my --silent clean
	$(MAKE) -C ./lib/linked_list --silent clean

fclean_lib:
	$(MAKE) -C ./lib/my --silent fclean
	$(MAKE) -C ./lib/linked_list --silent fclean
	rm -f lib/libmy.a
	rm -f lib/liblist.a

clean: clean_lib
	rm -f $(OBJ)

fclean: fclean_lib clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean fclean_lib clean_lib build build_lib all
