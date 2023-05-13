/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:57 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 19:25:00 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_min_if(const t_stack stack, int pos)
{
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.base.j = stack.base.i + 1;
		while (stack.base.j < stack.len)
		{
			if (stack.stack[stack.base.i] > stack.stack[stack.base.j])
			{
				ft_swap(&stack.stack[stack.base.i], &stack.stack[stack.base.j]);
			}
			stack.base.j++;
		}
		stack.base.i++;
	}	
	stack.min = stack.stack[pos];
	return (stack.min);
}

int	ft_max(t_stack stack)
{
	stack.base.i = 0;
	stack.max = stack.stack[0];
	while (stack.base.i < stack.len)
	{
		if (stack.stack[stack.base.i] > stack.max)
			stack.max = stack.stack[stack.base.i];
		stack.base.i++;
	}
	return (stack.max);
}

int	ft_find_min_pos_if(const t_stack stack, int pos)
{
	stack.min_pos = 0;
	stack.min = ft_min_if(stack, pos);
	stack.base.i = 0;
	if (pos < 0 || pos > stack.len)
	{
		return (-1);
	}
	while (stack.base.i < stack.len)
	{
		if (stack.stack[stack.base.i] == stack.min)
		{
			stack.min = stack.stack[stack.base.i];
			stack.min_pos = stack.base.i;
		}
		stack.base.i++;
	}
	return (stack.min_pos);
}
