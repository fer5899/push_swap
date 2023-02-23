/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:46:16 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/23 15:52:40 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkdelone(t_stk *stk, void (*del)(void*))
{
	if (stk == NULL)
		return ;
	del(stk->content);
	free(stk);
}
