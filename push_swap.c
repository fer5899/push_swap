/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:07:25 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/21 17:56:31 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	printstk(void *stk_elem)
{
	t_elem_stk	*elem;

	elem = (t_elem_stk *) stk_elem;
	ft_printf("%d. (%d, %d) -> ", elem->pos, elem->value, elem->index);
}

int	main(int argc, char **argv)
{
	t_stk	*stk;

	if (argc == 1)
		return (0);
	if (check_args(argc, argv))
	{
		stk = create_stk(argc, argv);
		if (stk == NULL)
			return (ft_printf_fd("Error\n", 2), 1);
		if (argc == 3)
			two_elem_sort(stk);
		if (argc == 4)
			three_elem_sort(stk);
	}
	else
		return (ft_printf_fd("Error\n", 2), 1);
	return (0);
}
