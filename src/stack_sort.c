/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:40:14 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 19:57:30 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	two_elem_sort(t_stk *stk)
{
	t_elem	*elem;

	elem = (t_elem *) stk->first->content;
	if (elem->index == 2)
		swap(stk, 'a');
}

void	three_elem_sort(t_stk *stk)
{
	int	idx_0;
	int	idx_1;
	int	idx_2;

	idx_0 = ((t_elem *) stk->first->content)->index;
	idx_1 = ((t_elem *) stk->first->next->content)->index;
	idx_2 = ((t_elem *) stk->first->next->next->content)->index;
	if (idx_0 > idx_1 && idx_0 > idx_2)
		rotate(stk, stk, 'a', 1);
	else if (idx_1 > idx_0 && idx_1 > idx_2)
		rev_rotate(stk, stk, 'a', 1);
	if (((t_elem *) stk->first->content)->index
		> ((t_elem *) stk->first->next->content)->index)
		swap(stk, 'a');
}

void	sort_element(t_stk **a, t_stk **b, t_sizes *sz, int elem_idx)
{
	t_elem	*elem;

	elem = (t_elem *) ft_getstknode(*b, elem_idx)->content;
	rotation(*a, *b, elem->cost_a, elem->cost_b);
	push(b, a, sz, 'a');
}

void	end_rotations(t_stk *stk_a, t_sizes *sz)
{
	t_elem	*elem;

	elem = (t_elem *) stk_a->first->content;
	if (elem->index - 1 <= sz->a / 2)
		rev_rotate(stk_a, stk_a, 'a', elem->index - 1);
	else
		rotate(stk_a, stk_a, 'a', sz->a - elem->index + 1);
}

void	stack_sort(t_stk *stk_a, int argc)
{
	t_stk	*stk_b;
	t_sizes	*sizes;
	int		cheapest;

	if (is_sorted(stk_a))
		return ;
	sizes = init_sizes(argc - 1, 0);
	stk_b = initialize_stk_b(&stk_a, sizes, argc);
	pass_to_b(&stk_a, stk_b, sizes, argc);
	three_elem_sort(stk_a);
	while (sizes->b > 0)
	{
		stk_b = stk_b->first;
		update_stacks_pos(stk_a, stk_b);
		update_target_pos(stk_a, stk_b, sizes);
		cheapest = find_cheapest(stk_b, sizes, sizes->a + sizes->b);
		sort_element(&stk_a, &stk_b, sizes, cheapest);
	}
	update_pos(stk_a);
	if (!is_sorted(stk_a))
		end_rotations(stk_a, sizes);
}
