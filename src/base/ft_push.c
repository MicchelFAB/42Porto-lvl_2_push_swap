/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:53 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/09 18:55:24 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_push(t_stack *x, t_stack *y)
{
	int i;

	i = 0;
	if (x.len == 0)
	{
		return;
	}
	if(y.len > 0)
	{
		i = y.len;
		while(i > 0)
		{
			y.stack[i] = y.stack[i - 1];
			i--;
		}
	}
	y.stack[0] = x.stack[0];
	(&y.len)++;
	i = 0;
	while (i < (x.len) - 1)
	{
		x.stack[i] = x.stack[i + 1];
		i++;
	}
	(&x.len)--;
}

void	ft_pb(t_stash t_stash)
{
	ft_push(t_stash.a, t_stash.b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stash t_stash)
{
	ft_push(&t_stash.b, &t_stash.a);
	ft_putstr_fd("pa\n", 1);
}
