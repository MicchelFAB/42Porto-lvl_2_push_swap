/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 13:07:59 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_rotate() shifts all elements of a stack up by one.	*
 * The first element becomes the last one.					*/

void	ft_rotate(t_stack stack)
{
	stack.base.first = stack.stack[0];
	stack.base.i = 0;
	while (stack.base.i < stack.len - 1)
	{
		stack.stack[stack.base.i] = stack.stack[stack.base.i + 1];
		stack.base.i++;
	}
	stack.stack[stack.len - 1] = stack.base.first;
}

/* ft_ra() call ft_rotate() to shift all elements of 		*
 * stack a up by one. and prints the operation to stdout.	*/

void	ft_ra(t_stash a)
{
	ft_rotate(a.a);
	ft_putstr_fd("ra\n", 1);
}

/* ft_rb() call ft_rotate() to shift all elements of 		*
 * stack b up by one. and prints the operation to stdout.	*/

void	ft_rb(t_stash b)
{
	ft_rotate(b.b);
	ft_putstr_fd("rb\n", 1);
}

/* ft_rr() call ft_rotate() to shift all elements of 		*
 * both stacks a and b up by one. and prints the operation	*
 * to stdout.												*/

void	ft_rr(t_stash ab)
{
	ft_rotate(ab.a);
	ft_rotate(ab.b);
	ft_putstr_fd("rr\n", 1);
}
