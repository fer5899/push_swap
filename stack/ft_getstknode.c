/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstknode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:34:04 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/23 15:51:45 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stk	*ft_getstknode(t_stk *stk, int idx)
{
	if (idx < 0 || stk == NULL || idx >= ft_stksize(stk))
		return (NULL);
	if (stk != stk->first)
		stk = stk->first;
	if (idx == 0)
		return (stk);
	while (stk->next != stk->first)
	{
		if (idx == 0)
			return (stk->next);
		stk = stk->next;
		idx--;
	}
	return (NULL);
}
