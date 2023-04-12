/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:31:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 20:39:16 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	update_stacks_pos(t_stk *stk_a, t_stk *stk_b)
{
	update_pos(stk_a);
	update_pos(stk_b);
}

t_sizes	*init_sizes(int size_a, int size_b)
{
	t_sizes	*sizes;

	sizes = (t_sizes *) ft_calloc(1, sizeof(t_sizes));
	if (sizes == NULL)
		return (NULL);
	sizes->a = size_a;
	sizes->b = size_b;
	return (sizes);
}

int	is_sorted(t_stk *stk)
{
	stk = stk->first;
	while (stk->next != stk->first)
	{
		if (((t_elem *)stk->content)->pos + 1
			!= ((t_elem *)stk->content)->index)
			return (0);
		stk = stk->next;
	}
	if (((t_elem *)stk->content)->pos + 1
		!= ((t_elem *)stk->content)->index)
		return (0);
	return (1);
}

t_stk	*initialize_stk_b(t_stk **stk_a, t_sizes *sizes, int argc)
{
	t_stk	*stk_b;

	while (((t_elem *)((*stk_a)->first->content))->index > (argc - 1) / 2)
	{
		if (((t_elem *)(ft_stklast(*stk_a)->content))->index <= (argc - 1) / 2)
			rev_rotate(*stk_a, *stk_a, 'a', 1);
		else
			rotate(*stk_a, *stk_a, 'a', 1);
	}
	ft_stk_r(*stk_a);
	stk_b = ft_stkpop(stk_a, ft_stklast(*stk_a));
	ft_printf("pb\n");
	sizes->b += 1;
	sizes->a -= 1;
	return (stk_b);
}

void	pass_to_b(t_stk **stk_a, t_stk *stk_b, t_sizes *sizes, int argc)
{
	t_stk	*next;

	while (sizes->a > argc / 2)
	{
		*stk_a = (*stk_a)->first;
		if (((t_elem *)((*stk_a)->first->content))->index <= argc / 2)
		{
			next = (*stk_a)->next;
			push(stk_a, &stk_b, sizes, 'b');
			*stk_a = next;
		}
		else if (((t_elem *)(ft_stklast(*stk_a)->content))->index
			<= (argc - 1) / 2)
			rev_rotate(*stk_a, *stk_a, 'a', 1);
		else
			rotate(*stk_a, *stk_a, 'a', 1);
	}
	while (sizes->a > 3)
	{
		*stk_a = (*stk_a)->first;
		next = (*stk_a)->first->next;
		push(stk_a, &stk_b, sizes, 'b');
		*stk_a = next;
	}
}


