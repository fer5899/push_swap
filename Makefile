# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:12:12 by fgomez-d          #+#    #+#              #
#    Updated: 2023/03/16 13:23:36 by fgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS= -Ilibft -Iinc -Istack
NAME=push_swap

LIB_DIR=libft
LIB_OBJ=$(LIB_DIR)/*.o

SRC_DIR=src
SRC=$(SRC_DIR)/push_swap.c $(SRC_DIR)/merge_sort.c

OBJ=$(SRC:.c=.o)

STACK_SRC=$(wildcard stack/*.c)

STACK_OBJ=$(STACK_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	clear
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(LIB_OBJ):
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f $(STACK_OBJ)
	$(MAKE) -C libft fclean
	
fclean: clean
	rm -f $(NAME)

test: fclean $(OBJ) $(LIB_OBJ)
	clear
	@$(CC) $(CPPFLAGS) test.c $(OBJ) $(LIB_OBJ) -o test
	@./test
	@rm test

stack: fclean $(STACK_OBJ) test.o
	clear
	@$(CC) $(CPPFLAGS) test.o $(STACK_OBJ) -o test
	@./test
	@rm test

re: fclean all

.PHONY: all clean fclean re