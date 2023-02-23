/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:39:53 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/02/23 16:15:15 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

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
*	@return		The index of the searched node within the stack, 
*				-1 if is not present or error.
*/
int		ft_getstkidx(t_stk *stk, t_stk *search);

/*
*	@brief		Gets the size of the stack.
*
*	@param		stk	Stack to get the size of.
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

/*
*	@brief		Sets the node `new_first` as the new first node of stack `stk`.
*
*	@param		stk			Stack in where the first position will change.
*	@param		new_first	Node that will become the first in the stack.
*/
void	ft_stknewfirst(t_stk *stk, t_stk *new_first);

/*
*	@brief		Inserts the stack node `new` into `stk` and makes it the first node.
*
*	@param		stk	Stack where the node will be inserted.
*	@param		new	New stack node that will be added. It will become the first node.
*/
void	ft_stkadd_top(t_stk *stk, t_stk *new_node);

/*
*	@brief		Deletes and frees the given stack node using the function del
*				given as a parameter and free(3). The memory of next must not
*				be freed.
*
*	@param		*stk	Pointer to the stack node to be deleted.
*	@param		*del	Function used to delete the content of the stack node.
*/
void	ft_stkdelone(t_stk *stk, void (*del)(void*));

/*
*	@brief		Deletes and frees the given stack using the function del given
*				as a parameter and free(3). The pointer to the first node of
*				the stack must be set to NULL.
*
*	@param		*stk	Pointer to the first node of the stack. Must be the
*						first node of the stack.
*	@param		*del	Function used to delete the content of the stack node.
*/
void	ft_stkclear(t_stk **stk, void (*del)(void*));

/*
*	@brief		Iterates the stack `stk` and applies the function f to the content
*				of each node.
*
*	@param		*stk	Pointer to a node of a stack.
*	@param		*f		Function to apply to the content of each node.
*/
void	ft_stkiter(t_stk *stk, void (*f)(void *));

/*
*	@brief		Removes the stack node `to_pop` from the stack `stk`, connecting
*				the previous node to the next. Returns the removed node.
*
*	@param		*stk	Stack from which a node will be popped.
*	@param		*to_pop	Node to be popped.
*
*	@return		The node that was popped, NULL if error.
*/
t_stk	*ft_stkpop(t_stk *stk, t_stk *to_pop);

/*
*	@brief		Removes the stack node in the position `idx` from the stack `stk`, 
*				conecting the previous node to the next. Returns the removed node.
*
*	@param		*stk	Stack from which a node will be popped.
*	@param		*idx	Index of the node to be popped.
*
*	@return		The node that was popped.
*/
t_stk	*ft_stkpop_idx(t_stk *stk, int idx);

#endif