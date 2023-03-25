/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:40:14 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/25 13:07:22 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	two_elem_sort(t_stk *stk)
{
	t_elem_stk	*elem;

	elem = (t_elem_stk *) stk->first->content;
	if (elem->index == 2)
		swap(stk, 'a');
}

void	three_elem_sort(t_stk *stk)
{
	if (((t_elem_stk *) stk->first->content)->index == 3)
		rotate(stk, stk, 'a');
	else if (((t_elem_stk *) stk->first->next->content)->index == 3)
		rev_rotate(stk, stk, 'a');
	if (((t_elem_stk *) stk->first->content)->index
		> ((t_elem_stk *) stk->first->next->content)->index)
		swap(stk, 'a');
}

void	stack_sort(t_stk *stk_a, int argc)
{
	t_stk	*stk_b;
	t_sizes	*sizes;

	if (is_sorted(stk_a))
		return ;
	sizes = init_sizes(argc - 1, 0);
	stk_b = initialize_stk_b(&stk_a, sizes, argc);
	first_pass_to_b(stk_a, stk_b, sizes, argc);
	three_elem_sort(stk_a);
}
