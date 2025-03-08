NAME = so_long

CC= cc 
CFLAGS= -Wall -Wextra -Werror

SRC = printf/ft_printf.c printf/ft_putnbr.c \
	printf/ft_putptr.c printf/ft_printf.c printf/ft_putchar.c\
	printf/ft_putnbr_hex.c printf/ft_putstr.c printf/ft_putunsigned.c \
	getnextline/get_next_line_bonus.c  getnextline/get_next_line.c \
	getnextline/get_next_line_utils_bonus.c getnextline/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
