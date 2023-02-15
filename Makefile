# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:12:12 by fgomez-d          #+#    #+#              #
#    Updated: 2023/02/15 12:06:58 by fgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS= -Ilibft -Iinc
NAME=push_swap

LIB_DIR=libft
LIB_OBJ=$(LIB_DIR)/*.o

SRC_DIR=src
SRC=$(SRC_DIR)/push_swap.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	clear
	$(CC) $(CPPFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(LIB_OBJ):
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	$(MAKE) -C libft fclean
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re