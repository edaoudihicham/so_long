# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 16:42:51 by hdaoudi           #+#    #+#              #
#    Updated: 2025/03/17 23:36:22 by hdaoudi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc 
CFLAGS= -Wall -Wextra -Werror
NAME = libft.a

SRC = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c    ft_isalpha.c ft_memchr.c  ft_memset.c  ft_strlcpy.c ft_strcpy.c ft_strrchr.c \
	ft_bzero.c   ft_isascii.c ft_memcmp.c  ft_strchr.c  ft_strlen.c  ft_tolower.c \
	ft_calloc.c  ft_isdigit.c ft_memcpy.c  ft_strdup.c  ft_strncmp.c ft_toupper.c \
	ft_substr.c  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
	
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)
	
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
