SRCS = $(shell find . -type f ! -name "ft_lst*.c" -name "ft_*.c")

BSRCS = $(shell find . -type f -name "ft_lst*.c")

NAME = libft.a

OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

bonus: $(OBJ) $(BOBJ)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean: 
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
