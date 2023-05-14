/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/14 16:03:30 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void	ft_rra(t_stash a)
{
	ft_reverse_rotate(a.a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stash b)
{
	ft_reverse_rotate(b.b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stash ab)
{
	ft_reverse_rotate(ab.a);
	ft_reverse_rotate(ab.b);
	ft_putstr_fd("rrr\n", 1);
}
