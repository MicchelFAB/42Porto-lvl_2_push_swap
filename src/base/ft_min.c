/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:57 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/16 07:57:36 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_min_if(t_stack stack, int pos)
{
	stack.base.tmp = malloc(stack.len * sizeof(int));
	ft_memcpy(stack.base.tmp, stack.stack, stack.len * sizeof(int));
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.base.j = stack.base.i + 1;
		while (stack.base.j < stack.len)
		{
			if (stack.base.tmp[stack.base.i] > stack.base.tmp[stack.base.j])
			{
				ft_swap(&stack.base.tmp[stack.base.i], &stack.base.tmp[stack.base.j]);
			}
			stack.base.j++;
		}
		stack.base.i++;
	}	
	stack.base.min = stack.base.tmp[pos];
	free(stack.base.tmp);
	return (stack.base.min);
}

int	ft_max(t_stack stack)
{
	stack.base.i = 0;
	stack.base.max = stack.stack[0];
	while (stack.base.i < stack.len)
	{
		if (stack.stack[stack.base.i] > stack.base.max)
			stack.base.max = stack.stack[stack.base.i];
		stack.base.i++;
	}
	return (stack.base.max);
}

int	ft_find_min_pos_if(t_stack stack, int pos)
{
	stack.base.tpm = malloc(stack.len * sizeof(int));
	ft_memcpy(stack.base.tpm, stack.stack, stack.len * sizeof(int));
	stack.base.min_pos = 0;
	stack.base.min = ft_min_if(stack, pos);
	stack.base.i = 0;
	if (pos < 0 || pos > stack.len)
	{
		return (-1);
	}
	while (stack.base.i < stack.len)
	{
		if (stack.base.tpm[stack.base.i] == stack.base.min)
		{
			stack.base.min = stack.base.tpm[stack.base.i];
			stack.base.min_pos = stack.base.i;
		}
		stack.base.i++;
	}
	free(stack.base.tpm);
	return (stack.base.min_pos);
}
