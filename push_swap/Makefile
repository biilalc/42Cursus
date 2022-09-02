NAME		= pushswap
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.

SRC	= $(shell find src -name *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -rf $(OBJ)

re:	fclean all

bonus: all

.PHONY:	all clean fclean re bonus run
