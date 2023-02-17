/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:39:53 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/17 15:23:45 by fgomez-d         ###   ########.fr       */
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

/*
*	@brief		Returns the last element of the stack.
*
*	@param		stk	Stack out of which the last element will be returned.
*
*	@return		The last element of the stack.
*/
t_stk	*ft_stklast(t_stk *stk);

/*
*	@brief		Gets the index of the stack node `search` in the stack `stk`. Returns
*				-1 if the node wasn't found.
*
*	@param		stk	Stack to be searched.
*	@param		search	Stack node to search.
*
*	@return		The index of the searched node within the stack, -1 if is not present.
*/
int		ft_getstkidx(t_stk *stk, t_stk *search);

/*
*	@brief		Gets the size of the stack.
*
*	@param		stk	Stack to get the size of. Must be the first node of the stack.
*
*	@return		The size of the stack. -1 if the node passed is not the first element.
*/
int		ft_stksize(t_stk *stk);

/*
*	@brief		Gets the element in the position `idx` in the stack `stk`.
*
*	@param		stk	Stack where the node will be searched.
*	@param		idx	Index of the element to get.
*
*	@return		The node in position `idx` or NULL if error or node not present.
*/
t_stk	*ft_getstknode(t_stk *stk, int idx);

#endif