# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 09:58:29 by saguesse          #+#    #+#              #
#    Updated: 2022/07/18 17:17:55 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  push_swap.c \
	ft_atoi.c \
	ft_split.c \
	ft_substr.c \
	ft_moves_a.c \
	ft_moves_b.c \



HEADER = push_swap.h

OBJ = $(SRC:.c=.o)

all: $(NAME) 

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
