/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:31:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/23 12:54:26 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stk *stk)
{
	stk = stk->first;
	while (stk->next != stk->first)
	{
		if (((t_elem_stk *)stk->content)->pos
			!= ((t_elem_stk *)stk->content)->index)
			return (0);
		stk = stk->next;
	}
	if (((t_elem_stk *)stk->content)->pos
		!= ((t_elem_stk *)stk->content)->index)
		return (0);
	return (1);
}
