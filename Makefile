# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 09:58:29 by saguesse          #+#    #+#              #
#    Updated: 2022/08/25 16:06:11 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g3

CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	ft_lstmoves_costs.c \
	big_list.c \
	ft_lstmin.c \
	check_args.c \
	ft_atoi.c \
	ft_dellist.c \
	ft_lstadd_back.c \
	ft_lstbeforelast.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstprint.c \
	ft_lstsize.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_lstpos.c \
	moves.c \
	push_swap.c \

HEADER = push_swap.h

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

random:
	seq 1 100 | sort -R | tr "\n" " "; echo

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
