# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 09:58:29 by saguesse          #+#    #+#              #
#    Updated: 2022/08/21 17:28:29 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	ft_lstmin.c \
	push_swap.c \
	big_list.c
	check_args.c \
	ft_atoi.c \
	ft_dellist.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstbeforelast.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	moves.c \

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
