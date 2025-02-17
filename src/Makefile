# -*- Makefile -*-

CC = cc

CFLAGS = -Werror -Wall -Wextra -g

NAME = push_swap
LIBFTDIR = ../includes/libft
LIBFT = ../includes/libft/libft.a
SRC = push_swap.c stack_a_utils.c stack_b_utils.c stacks_utils.c small_number_of_input.c radix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -I$(LIBFTDIR) -lft -o $(NAME)

clean:
	rm -f *.o
# Add the -f flag to suppress errors
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re