/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:12:26 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 21:50:00 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_elem	*new_elem_stk(int value, int index)
{
	t_elem	*data;

	data = (t_elem *) ft_calloc(1, sizeof(t_elem));
	if (data == NULL)
		return (NULL);
	data->value = value;
	data->index = index;
	return (data);
}

int	get_arr_idx(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	update_pos(t_stk *stk)
{
	int		pos;
	t_elem	*elem;

	pos = 0;
	if (stk != stk->first)
		stk = stk->first;
	while (stk->next != stk->first)
	{
		elem = (t_elem *) stk->content;
		elem->pos = pos;
		stk->content = elem;
		stk = stk->next;
		pos++;
	}
	elem = (t_elem *) stk->content;
	elem->pos = pos;
	stk->content = elem;
}

t_stk	*fill_stk(int *orig, int *sorted, int argc)
{
	t_stk		*stk;
	t_stk		*new_stk;
	int			i;

	i = argc - 2;
	stk = ft_stknew(new_elem_stk(
				orig[i], get_arr_idx(sorted, argc - 1, orig[i]) + 1));
	if (stk == NULL)
		return (NULL);
	i--;
	while (i >= 0)
	{
		new_stk = ft_stknew(new_elem_stk(
					orig[i], get_arr_idx(sorted, argc - 1, orig[i]) + 1));
		if (new_stk == NULL)
			return (NULL);
		ft_stkadd_top(stk, new_stk);
		i--;
	}
	update_pos(stk);
	free(orig);
	free(sorted);
	return (stk);
}

t_stk	*create_stk(int argc, char **argv)
{
	int		i;
	int		*orig;
	int		*sorted;

	i = 0;
	orig = (int *) ft_calloc(argc - 1, sizeof(int));
	sorted = (int *) ft_calloc(argc - 1, sizeof(int));
	if (orig == NULL || sorted == NULL)
		return (NULL);
	while (i < argc - 1)
	{
		orig[i] = ft_atoi(argv[i + 1]);
		sorted[i] = orig[i];
		i++;
	}
	if (merge_sort(sorted, argc - 1))
		return (fill_stk(orig, sorted, argc));
	return (NULL);
}
