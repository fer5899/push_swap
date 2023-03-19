/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:31:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/19 14:05:51 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_elem_stk	*new_elem_stk(int value, int index)
{
	t_elem_stk	*data;

	data = (t_elem_stk *) ft_calloc(1, sizeof(t_elem_stk));
	if (data == NULL)
		return (NULL);
	data->value = value;
	data->index = index;
	return (data);
}
