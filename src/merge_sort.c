/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:50:21 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/17 13:30:02 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_array	init_sub_array(int arr[], int start, int end)
{
	t_array	new_array;
	int		i;

	new_array.size = (end - start);
	new_array.arr = (int *) malloc((end - start) * sizeof(int));
	i = 0;
	while (start < end)
		new_array.arr[i++] = arr[start++];
	return (new_array);
}

int	merge(int arr[], t_array left, t_array right)
{
	int	l_idx;
	int	r_idx;
	int	result_idx;

	l_idx = 0;
	r_idx = 0;
	result_idx = 0;
	while (l_idx < left.size && r_idx < right.size)
	{
		if (left.arr[l_idx] < right.arr[r_idx])
			arr[result_idx++] = left.arr[l_idx++];
		else if (left.arr[l_idx] == right.arr[r_idx])
			return (0);
		else
			arr[result_idx++] = right.arr[r_idx++];
	}
	while (l_idx < left.size)
		arr[result_idx++] = left.arr[l_idx++];
	while (r_idx < right.size)
		arr[result_idx++] = right.arr[r_idx++];
	return (1);
}

int	merge_sort(int arr[], int size)
{
	int		mid;
	t_array	left;
	t_array	right;
	int		no_dups;

	if (size < 2)
		return (1);
	mid = size / 2;
	left = init_sub_array(arr, 0, mid);
	right = init_sub_array(arr, mid, size);
	if (left.arr == NULL || right.arr == NULL)
		return (0);
	no_dups = merge_sort(left.arr, left.size);
	if (no_dups)
		no_dups = merge_sort(right.arr, right.size);
	if (no_dups)
		no_dups = merge(arr, left, right);
	free(left.arr);
	free(right.arr);
	return (no_dups);
}
