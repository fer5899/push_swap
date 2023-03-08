/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:40:00 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/08 13:55:56 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stk_p(t_stk *orig, t_stk *dest)
{
	ft_stk_r(orig);
	ft_stkadd_top(dest, ft_stkpop(orig, ft_stklast(orig)));
}
