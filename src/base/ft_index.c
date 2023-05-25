/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:15:20 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 12:40:24 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_min() is used to find the min and max values in the stack to find *
 * the min value, I copy the stack to a temporary stack and then I		*
 * compare the values of the temporary stack. The min value is the 		*
 * first value of the temporary stack, i put the pos value so i can 	*
 * find the others minimum too.											*
 * pos 0 = first minimum value											*
 * pos 1 = second minimum value											*
 * pos 2 = third minimum value 											*
 * pos n = n+1th minimum value											*/

int	ft_min(t_stack stack, int pos)
{
	ft_memcpy(stack.base.tmp, stack.stack, stack.len * sizeof(int));
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.base.j = stack.base.i + 1;
		while (stack.base.j < stack.len)
		{
			if (stack.base.tmp[stack.base.i] > stack.base.tmp[stack.base.j])
			{
				ft_swap(&stack.base.tmp[stack.base.i], \
				&stack.base.tmp[stack.base.j]);
			}
			stack.base.j++;
		}
		stack.base.i++;
	}	
	stack.base.min = stack.base.tmp[pos];
	return (stack.base.min);
}

/* ft_max() is used to find the max value in the stack, I copy the stack	*
 * to a temporary stack and then I compare the values of the temporary		*
 * stack. The max value is the last value of the temporary stack.			*/

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

/* ft_pos_value() is used to find the position of the minimum value in the	*
 * stack. I copy the stack to a temporary stack and then I compare the		*
 * values of the temporary stack. The min value is the first value of the	*
 * temporary stack, i put the pos value so i can find the others minimum	*
 * positions too.															*
 * pos 0 = the position of the first minimum value							*
 * pos 1 = the position of the second minimum value							*
 * pos 2 = the position of the third minimum value							*
 * pos n = the position of the n+1th minimum value							*/

int	ft_pos_value(t_stack stack, int pos)
{
	stack.base.min = ft_min(stack, pos);
	ft_memcpy(stack.base.tmp, stack.stack, stack.len * sizeof(int));
	stack.base.min_pos = 0;
	stack.base.i = 0;
	if (pos < 0 || pos > stack.len)
	{
		return (-1);
	}
	while (stack.base.i < stack.len)
	{
		if (stack.base.tmp[stack.base.i] == stack.base.min)
		{
			stack.base.min = stack.base.tmp[stack.base.i];
			stack.base.min_pos = stack.base.i;
		}
		stack.base.i++;
	}
	return (stack.base.min_pos);
}

/* ft_index() is used to index the stack, I copy the stack to a temporary	*
 * stack and then I compare the values of the temporary stack. The min		*
 * value is the first value of the temporary stack, i put the pos value so	*
 * i can find the others minimum positions too. This way i transform the	*
 * values into an limit index.												*/

void	ft_index(t_stash stash)
{
	ft_memcpy(stash.a.base.tpm, stash.a.stack, stash.a.len * sizeof(int));
	stash.a.base.i = 0;
	while (stash.a.base.i < stash.a.len)
	{
		stash.a.base.j = ft_pos_value(stash.a, stash.a.base.i);
		stash.a.base.tpm[stash.a.base.j] = stash.a.base.i + 1;
		stash.a.base.i++;
	}
	stash.a.base.i = 0;
	while (stash.a.base.i < stash.a.len)
	{
		stash.a.stack[stash.a.base.i] = stash.a.base.tpm[stash.a.base.i];
		stash.a.base.i++;
	}
}

/* ft_absolute() is used to find the absolute value of a number.			*/

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
