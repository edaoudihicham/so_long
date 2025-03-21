NAME = so_long
LIBFT = ./libft/libft.a

CC= cc 
CFLAGS= -Wall -Wextra -Werror -Ilibft 

LIBXFLAGS := -lmlx -lXext -lX11

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
		so_long.c 	print_error_close_game.c parsing.c  \
		map_validation.c  	map_validation_2.c\
		mlx_game.c 		movement.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft/ --silent
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBXFLAGS)

clean:
	make -C ./libft/ clean --silent
	rm -f $(OBJ)

fclean: clean
	make -C ./libft/ fclean --silent
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
