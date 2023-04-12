/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:12:13 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:25:50 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_target_pos(t_stk *stk_a, int elem_idx, int *clst_idx, int *max_idx)
{
	int	target_pos;

	target_pos = -1;
	if (((t_elem *) stk_a->content)->index == elem_idx + 1)
	{
		target_pos = ((t_elem *) stk_a->content)->pos;
		*max_idx = -1;
	}
	else if (((t_elem *) stk_a->content)->index > elem_idx + 1
		&& ((t_elem *) stk_a->content)->index < *clst_idx)
	{
		target_pos = ((t_elem *) stk_a->content)->pos;
		*clst_idx = ((t_elem *) stk_a->content)->index;
	}
	else if (elem_idx > ((t_elem *) stk_a->content)->index
		&& ((t_elem *) stk_a->content)->index > *max_idx)
	{
		*max_idx = ((t_elem *) stk_a->content)->index;
		target_pos = ((t_elem *) stk_a->content)->pos + 1;
	}
	return (target_pos);
}

void	find_target_pos(t_stk *stk_a, t_stk *b, t_sizes *sz, int clst_idx)
{
	int	target_pos;
	int	aux;
	int	max_idx;
	int	elem_idx;
	int	i;

	elem_idx = ((t_elem *) b->content)->index;
	target_pos = -1;
	stk_a = stk_a->first;
	max_idx = 0;
	i = 0;
	while (i < sz->a)
	{
		aux = check_target_pos(stk_a, elem_idx, &clst_idx, &max_idx);
		if (aux != -1)
			target_pos = aux;
		if (max_idx == -1)
			break ;
		stk_a = stk_a->next;
		i++;
	}
	((t_elem *) b->content)->target_pos = target_pos;
}

void	update_target_pos(t_stk *a, t_stk *b, t_sizes *sz)
{
	int	i;

	i = 0;
	while (i < sz->b)
	{
		find_target_pos(a, b, sz, sz->a + sz->b + 1);
		b = b->next;
		i++;
	}
}

int	find_cheapest(t_stk *b, t_sizes *sz, int min_cost)
{
	int		i;
	int		cheapest_idx;
	t_elem	*b_elem;

	i = 0;
	while (i < sz->b)
	{
		b_elem = ((t_elem *)b->content);
		if (b_elem->target_pos <= (sz->a / 2))
			b_elem->cost_a = b_elem->target_pos;
		else
			b_elem->cost_a = b_elem->target_pos - sz->a;
		if (b_elem->pos <= (sz->b / 2))
			b_elem->cost_b = b_elem->pos;
		else
			b_elem->cost_b = b_elem->pos - sz->b;
		if (ft_abs(b_elem->cost_a - b_elem->cost_b) < min_cost)
		{
			min_cost = ft_abs(b_elem->cost_a - b_elem->cost_b);
			cheapest_idx = b_elem->pos;
		}
		b = b->next;
		i++;
	}
	return (cheapest_idx);
}
