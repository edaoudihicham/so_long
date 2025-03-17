NAME = so_long
FT_PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

CC= cc 
CFLAGS= -Wall -Wextra -Werror

LIBXFLAGS := -lmlx -lXext -lX11

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
		so_long/so_long.c 	so_long/print_error.c.c so_long/parsing.c  map_validation.c  	so_long/map_validation_2.c\
		so_long/mlx_game.c 		so_long/movement.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./ft_printf/ --silent
	make -C ./libft/ --silent
	$(CC) $(CFLAGS) $(LIBXFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

clean:
	make -C ./ft_printf/ clean --silent
	make -C ./libft/ clean --silent
	rm -f $(OBJ)

fclean: clean
	make -C ./ft_printf/ fclean --silent
	make -C ./libft/ fclean --silent
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
