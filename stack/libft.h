/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:39:53 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/17 12:53:22 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stk
{
	void			*content;
	struct s_stk	*first;
	struct s_stk	*next;
}					t_stk;

/*
*	@brief		Allocates (with malloc(3)) and returns a new stack node. The
*				variable content is initialized with the value of the parameter
*				content. The variable next is initialized to NULL. The node created
*				is assigned as the first element of its own stack.
*
*	@param		content	Content of the new stack node.
*
*	@return		The new stack node. NULL if memory allocation fails.
*/
t_stk	*ft_stknew(void *content);

#endif