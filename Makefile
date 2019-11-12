NAME	= abstractvm
CFLAGS = -Wextra -Wall -Werror

SRC		= \
		syntax_error.c \
		is_correct_type.c \
		my_function.c \
		my_getnbr.c \
		my_getcomma.c \
		read_file.c \
		my_realloc.c \
		my_abstract_vm.c \
		my_stack_operations.c \
		my_cast_function.c \
		my_assert.c \
		my_arithmetic.c \
		my_str_to_wordtab.c \
		my_putstr.c \
		parse_instruction.c \
		display_comma.c \
		list.c \
		main.c \

OBJ 	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all
