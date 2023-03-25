/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:15:52 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/23 14:17:51 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stk **stk_orig, t_stk **stk_dest, char dest_name)
{
	if (*stk_orig != NULL && *stk_dest != NULL)
	{
		ft_stk_p(stk_orig, stk_dest);
		ft_printf("p%c\n", dest_name);
	}
}

void	swap(t_stk *stk, char name)
{
	if (stk == NULL)
		return ;
	ft_stk_s(stk);
	ft_printf("s%c\n", name);
}

void	rotate(t_stk *stk_a, t_stk *stk_b, char name)
{
	if (stk_a != NULL && stk_b != NULL)
	{
		if (name == 'a' || name == 'b')
			ft_stk_r(stk_a);
		else if (name == 'r')
		{
			ft_stk_r(stk_a);
			ft_stk_r(stk_b);
		}
		ft_printf("r%c\n", name);
	}
}

void	rev_rotate(t_stk *stk_a, t_stk *stk_b, char name)
{
	if (stk_a != NULL && stk_b != NULL)
	{
		if (name == 'a' || name == 'b')
			ft_stk_rr(stk_a);
		else if (name == 'r')
		{
			ft_stk_rr(stk_a);
			ft_stk_rr(stk_b);
		}
		ft_printf("rr%c\n", name);
	}
}
