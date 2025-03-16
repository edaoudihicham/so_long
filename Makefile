NAME = so_long
FT_PRINTF = ft_printf/libftprintf.a
CC= cc 
CFLAGS= -Wall -Wextra -Werror

LIBXFLAGS := -lmlx -lXext -lX11

SRC = get_next_line.c get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C ft_printf/
	$(CC) $(CFLAGS) $(LIBXFLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)

clean:
	make -C ft_printf clean
	rm -f $(OBJ)

fclean: clean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
