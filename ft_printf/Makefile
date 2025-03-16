# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:07:17 by hdaoudi           #+#    #+#              #
#    Updated: 2024/11/20 12:08:29 by hdaoudi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc 
CFLAGS= -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_printf.c ft_putnbr.c ft_putptr.c ft_printf.c ft_putchar.c ft_putnbr_hex.c ft_putstr.c \
	ft_putunsigned.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
