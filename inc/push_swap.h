/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:07:46 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/21 19:37:45 by fgomez-d         ###   ########.fr       */
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
void		push(t_stk *stk_orig, t_stk *stk_dest, char name);
void		swap(t_stk *stk, char name);
void		rotate(t_stk *stk_a, t_stk *stk_b, char name);
void		rev_rotate(t_stk *stk_a, t_stk *stk_b, char name);
void		two_elem_sort(t_stk *stk);
void		three_elem_sort(t_stk *stk);
int			is_ordered(t_stk *stk);

#endif