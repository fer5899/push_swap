# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:12:12 by fgomez-d          #+#    #+#              #
#    Updated: 2023/04/12 21:58:03 by fgomez-d         ###   ########.fr        #
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
	$(SRC_DIR)/sort_utils.c $(SRC_DIR)/stack_moves.c $(SRC_DIR)/stack_sort.c \
	$(SRC_DIR)/cost_calc.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	clear
	$(CC) $(CPPFLAGS) $(CFLAGS) push_swap.c $(OBJ) $(LIB_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

lib:
	$(MAKE) -C libft

$(LIB_OBJ):
	$(MAKE) -C libft

deepclean: clean
	$(MAKE) -C libft fclean
	
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re