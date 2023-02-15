/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:06:11 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/15 17:06:44 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_idx(t_list *lst, int idx)
{
	int		size;
	t_list	*popped;

	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	if (idx >= size || idx < 0)
		return (NULL);
	while (idx > 0)
	{
		lst = lst->next;
		idx--;
	}
	popped = lst;
	return (popped);
}
