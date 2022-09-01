# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 09:58:29 by saguesse          #+#    #+#              #
#    Updated: 2022/09/01 17:55:04 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	big_list.c \
	check_args.c \
	ft_atoi.c \
	ft_dellist.c \
	ft_lstadd_back.c \
	ft_lstbeforelast.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstmax.c \
	ft_lstmin.c \
	ft_lstmoves_costs.c \
	ft_lstnew.c \
	ft_lstpos.c \
	ft_lstsize.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	moves.c \
	push_swap.c

HEADER = push_swap.h

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test3 test5 test500 test100
