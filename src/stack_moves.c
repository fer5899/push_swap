/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:15:52 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:14:41 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stk **stk_orig, t_stk **stk_dest, t_sizes *sizes, char dst)
{
	if (*stk_orig != NULL && *stk_dest != NULL)
	{
		ft_stk_p(stk_orig, stk_dest);
		ft_printf("p%c\n", dst);
	}
	if (dst == 'a')
	{
		sizes->a += 1;
		sizes->b -= 1;
	}
	else
	{
		sizes->b += 1;
		sizes->a -= 1;
	}
}

void	swap(t_stk *stk, char name)
{
	if (stk == NULL)
		return ;
	ft_stk_s(stk);
	ft_printf("s%c\n", name);
}

void	rotation(t_stk *stk_a, t_stk *stk_b, int a_rot, int b_rot)
{
	int	repeat;

	if (a_rot >= 0 && b_rot >= 0)
	{
		repeat = ft_minmax(a_rot, b_rot, 1);
		rotate(stk_a, stk_b, 'r', repeat);
		a_rot -= repeat;
		b_rot -= repeat;
	}
	else if (a_rot <= 0 && b_rot <= 0)
	{
		repeat = ft_abs(ft_minmax(a_rot, b_rot, 0));
		rev_rotate(stk_a, stk_b, 'r', repeat);
		a_rot += repeat;
		b_rot += repeat;
	}
	if (a_rot > 0)
		rotate(stk_a, stk_a, 'a', a_rot);
	if (b_rot > 0)
		rotate(stk_b, stk_b, 'b', b_rot);
	if (a_rot < 0)
		rev_rotate(stk_a, stk_a, 'a', ft_abs(a_rot));
	if (b_rot < 0)
		rev_rotate(stk_b, stk_b, 'b', ft_abs(b_rot));
}

void	rotate(t_stk *stk_a, t_stk *stk_b, char name, int repeat)
{
	while (repeat > 0)
	{
		if (name == 'a' || name == 'b')
			ft_stk_r(stk_a);
		else if (name == 'r')
		{
			ft_stk_r(stk_a);
			ft_stk_r(stk_b);
		}
		ft_printf("r%c\n", name);
		repeat--;
	}
}

void	rev_rotate(t_stk *stk_a, t_stk *stk_b, char name, int repeat)
{
	while (repeat > 0)
	{
		if (name == 'a' || name == 'b')
			ft_stk_rr(stk_a);
		else if (name == 'r')
		{
			ft_stk_rr(stk_a);
			ft_stk_rr(stk_b);
		}
		ft_printf("rr%c\n", name);
		repeat--;
	}
}
