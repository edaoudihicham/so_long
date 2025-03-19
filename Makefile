NAME = so_long
FT_PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

CC= cc 
CFLAGS= -Wall -Wextra -Werror

LIBXFLAGS := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #-lmlx -lXext -lX11

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
		so_long_source/so_long.c 	so_long_source/print_error.c so_long_source/parsing.c  \
		so_long_source/map_validation.c  	so_long_source/map_validation_2.c\
		so_long_source/mlx_game.c 		so_long_source/movement.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./ft_printf/ --silent
	make -C ./libft/ --silent
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME) $(LIBXFLAGS)

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
