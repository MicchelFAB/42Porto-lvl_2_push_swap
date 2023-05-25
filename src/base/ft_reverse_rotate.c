/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 13:05:58 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_reverse_rotate() shifts all elements of a stack down by one.	*
The last element becomes the first one.								*/

void	ft_reverse_rotate(t_stack stack)
{
	stack.base.i = stack.len - 1;
	stack.base.last = stack.stack[stack.len - 1];
	while (stack.base.i > 0)
	{
		stack.stack[stack.base.i] = stack.stack[stack.base.i - 1];
		stack.base.i--;
	}
	stack.stack[0] = stack.base.last;
}

/* ft_rra() call ft_reverse_rotate() to shift all elements of 	*
 * stack a down by one. and prints the operation to stdout.		*/

void	ft_rra(t_stash a)
{
	ft_reverse_rotate(a.a);
	ft_putstr_fd("rra\n", 1);
}

/* ft_rrb() call ft_reverse_rotate() to shift all elements of 	*
 * stack b down by one. and prints the operation to stdout.		*/

void	ft_rrb(t_stash b)
{
	ft_reverse_rotate(b.b);
	ft_putstr_fd("rrb\n", 1);
}

/* ft_rrr call ft_reverse_rotate() to shift all elements of		*
 * both stacks a and b down by one. and prints the operation to *
 * stdout.														*/

void	ft_rrr(t_stash ab)
{
	ft_reverse_rotate(ab.a);
	ft_reverse_rotate(ab.b);
	ft_putstr_fd("rrr\n", 1);
}
