/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:52:43 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/23 15:52:41 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkclear(t_stk **stk, void (*del)(void*))
{
	t_stk	*next_node;

	if (*stk == NULL || *stk != (*stk)->first)
		return ;
	while ((*stk)->next != (*stk)->first)
	{
		next_node = (*stk)->next;
		ft_stkdelone(*stk, del);
		*stk = next_node;
	}
	ft_stkdelone(*stk, del);
	*stk = NULL;
}
