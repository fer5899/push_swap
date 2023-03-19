/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:07:46 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/19 14:06:03 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_array
{
	int	*arr;
	int	size;
}	t_array;

typedef struct s_elem_stk
{
	int	pos;
	int	value;
	int	index;
	int	target_pos;
	int	cost_a;
	int	cost_b;
}	t_elem_stk;

int			check_args(int argc, char **argv);
int			merge_sort(int arr[], int size);
t_stk		*create_stk(int argc, char **argv);
t_elem_stk	*new_elem_stk(int value, int index);

#endif