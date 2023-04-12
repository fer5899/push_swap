/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:07:25 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 19:45:40 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	*stk;

	if (argc < 2)
		return (0);
	if (check_args(argc, argv))
	{
		stk = create_stk(argc, argv);
		if (stk == NULL)
			return (ft_printf_fd("Error\n", 2), 1);
		if (argc == 3)
			two_elem_sort(stk);
		else if (argc == 4)
			three_elem_sort(stk);
		else
			stack_sort(stk, argc);
	}
	else
		return (ft_printf_fd("Error\n", 2), 1);
	return (0);
}
