/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:06:11 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/08 15:21:50 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stk	*ft_stkpop(t_stk *stk, t_stk *to_pop)
{	
	if (stk == NULL || to_pop == NULL)
		return (NULL);
	if (stk != stk->first)
		stk = stk->first;
	while (stk->next != stk->first)
	{
		if (stk->next == to_pop)
		{
			stk->next = stk->next->next;
			to_pop->next = to_pop;
			to_pop->first = to_pop;
			return (to_pop);
		}
		stk = stk->next;
	}
	if (to_pop == stk)
	{
		ft_stklast(stk)->next = stk->next;
		ft_stknewfirst(stk->next, stk->next);
		to_pop->next = to_pop;
		return (to_pop);
	}
	return (NULL);
}
