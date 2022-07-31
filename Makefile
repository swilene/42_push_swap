# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 09:58:29 by saguesse          #+#    #+#              #
#    Updated: 2022/07/31 11:08:25 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  push_swap.c \
	ft_atoi.c \
	ft_moves_a.c \
	ft_moves_b.c \
	ft_lstnew.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_dellist.c \
	check_args.c \
	#ft_lstdelone.c \
	ft_lstclear.c \#

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
