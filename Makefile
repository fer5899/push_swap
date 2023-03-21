# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:12:12 by fgomez-d          #+#    #+#              #
#    Updated: 2023/03/21 19:16:25 by fgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS= -Ilibft -Iinc -Istack
NAME=push_swap

LIB_DIR=libft
LIB_OBJ=$(LIB_DIR)/*.o

SRC_DIR=src
SRC=$(SRC_DIR)/merge_sort.c $(SRC_DIR)/check_args.c $(SRC_DIR)/process_args.c \
	$(SRC_DIR)/sort_utils.c $(SRC_DIR)/stack_moves.c $(SRC_DIR)/stack_sort.c

OBJ=$(SRC:.c=.o)

STACK_SRC=$(wildcard stack/*.c)

STACK_OBJ=$(STACK_SRC:.c=.o)

all: $(NAME)

$(NAME): fclean $(OBJ) $(LIB_OBJ)
	clear
	$(CC) $(CPPFLAGS) $(CFLAGS) push_swap.c $(OBJ) $(LIB_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(LIB_OBJ):
	$(MAKE) -C libft

deepclean: clean
	$(MAKE) -C libft fclean
	
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	
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