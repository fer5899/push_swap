/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:21:29 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/17 11:21:46 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	quick_sort(int arr[], int start, int end)
{
	int	i;
	int	j;

	if (end - start < 1)
		return ;
	if (end - start == 1)
	{
		if (arr[start] > arr[end])
			swap(&arr[start], &arr[end]);
		return ;
	}
	i = start;
	j = end - 1;
	while (i < j)
	{
		while (arr[i] <= arr[end] && i <= end - 1)
			i++;
		while (arr[j] > arr[end])
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[end]);
	quick_sort(arr, start, j);
	quick_sort(arr, i + 1, end);
}
