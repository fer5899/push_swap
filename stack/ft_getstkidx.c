/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstkidx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:20:52 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/17 13:32:15 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getstkidx(t_stk *stk, t_stk *search)
{
	int	idx;

	idx = 0;
	if (stk == search)
		return (idx);
	while (stk->next != stk->first)
	{
		if (stk == search)
			return (idx);
		stk = stk->next;
		idx++;
	}
	return (-1);
}
