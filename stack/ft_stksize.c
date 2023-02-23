/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:01:56 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/23 15:52:41 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stksize(t_stk *stk)
{
	int	len;

	if (stk == NULL)
		return (0);
	if (stk != stk->first)
		stk = stk->first;
	if (stk->next == stk->first)
		return (1);
	len = 1;
	stk = stk->next;
	while (stk->next != stk->first)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}
