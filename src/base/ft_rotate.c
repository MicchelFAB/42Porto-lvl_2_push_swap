/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/24 17:21:50 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void	ft_ra(t_stash a)
{
	ft_rotate(a.a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stash b)
{
	ft_rotate(b.b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stash ab)
{
	ft_rotate(ab.a);
	ft_rotate(ab.b);
	ft_putstr_fd("rr\n", 1);
}
