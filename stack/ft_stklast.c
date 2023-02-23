/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stklast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:08:02 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/23 15:52:51 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stk	*ft_stklast(t_stk *stk)
{
	if (stk == NULL)
		return (NULL);
	if (stk == stk->first)
	{
		if (stk->next == stk->first)
			return (stk);
		else
			stk = stk->next;
	}
	while (stk->next != stk->first)
		stk = stk->next;
	return (stk);
}
