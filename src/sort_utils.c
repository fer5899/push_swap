/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:31:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/25 12:39:55 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stk *stk)
{
	stk = stk->first;
	while (stk->next != stk->first)
	{
		if (((t_elem_stk *)stk->content)->pos
			!= ((t_elem_stk *)stk->content)->index)
			return (0);
		stk = stk->next;
	}
	if (((t_elem_stk *)stk->content)->pos
		!= ((t_elem_stk *)stk->content)->index)
		return (0);
	return (1);
}

t_stk	*initialize_stk_b(t_stk **stk_a, int argc)
{
	t_stk	*stk_b;

	while (((t_elem_stk *)((*stk_a)->first->content))->index > (argc - 1) / 2)
		rotate(*stk_a, *stk_a, 'a');
	ft_stk_r(*stk_a);
	stk_b = ft_stkpop(stk_a, ft_stklast(*stk_a));
	ft_printf("pb\n");
	return (stk_b);
}

void	first_pass_to_b(t_stk *stk_a, t_stk *stk_b, int argc)
{
	while (ft_stksize(stk_a) > argc / 2)
	{
		if (((t_elem_stk *)(stk_a->first->content))->index <= argc / 2)
			push(&stk_a, &stk_b, 'b');
		else
			rotate(stk_a, stk_a, 'a');
	}
	while (ft_stksize(stk_a) > 3)
		push(&stk_a, &stk_b, 'b');
	update_pos(stk_a);
	update_pos(stk_b);
}


