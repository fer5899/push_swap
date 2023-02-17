/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknewfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:12:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/17 15:36:12 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stknewfirst(t_stk *stk, t_stk *new_first)
{
	t_stk	*start;

	if (ft_getstkidx(stk, new_first) == -1)
		return ;
	start = stk;
	stk->first = new_first;
	while (stk->next != start)
	{
		stk->first = new_first;
		stk = stk->next;
	}
}
