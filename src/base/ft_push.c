/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:53 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 13:00:50 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_push() the main push function, moves the first element of stack x to	*
 * the top of stack y, and updates the length of the stack x and y			*/

void	ft_push(t_stack *x, t_stack *y)
{	
	x->base.i = 0;
	if (x->len == 0)
	{
		return ;
	}
	if (y->len > 0)
	{
		x->base.i = y->len;
		while (x->base.i > 0)
		{
			y->stack[x->base.i] = y->stack[x->base.i - 1];
			x->base.i--;
		}
	}
	y->stack[0] = x->stack[0];
	y->len++;
	x->base.i = 0;
	while (x->base.i < x->len - 1)
	{
		x->stack[x->base.i] = x->stack[x->base.i + 1];
		x->base.i++;
	}
	x->len--;
}

/* ft_pb() call ft_push() to move the first element of stack a to the top	*
 * of stack b, and prints the operation to stdout							*/

void	ft_pb(t_stash *a)
{
	ft_push(&a->a, &a->b);
	ft_putstr_fd("pb\n", 1);
}

/* ft_pa() call ft_push() to move the first element of stack b to the top	*
 * of stack a, and prints the operation to stdout							*/

void	ft_pa(t_stash *b)
{
	ft_push(&b->b, &b->a);
	ft_putstr_fd("pa\n", 1);
}
