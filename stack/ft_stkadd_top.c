/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:25:16 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/17 15:46:42 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkadd_top(t_stk *stk, t_stk *new)
{
	if (stk == NULL || new == NULL)
		return ;
	if (stk != stk->first)
		stk = stk->first;
	new->next = stk;
	new->first = new;
	ft_stklast(stk)->next = new;
	ft_stknewfirst(stk, new);
}
