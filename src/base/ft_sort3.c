/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:12:07 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 19:47:18 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sort3(t_stack stack)
{
	if (len == 3)
	{
		if ((stack.stack[1] > stack.stack[2] && stack.stack[0] > \
		stack.stack[1]) || (stack.stack[1] < stack.stack[2] && stack.stack[0] > \
		stack.stack[2]))
		{
			ft_ra(stack);
		}
		else if (stack.stack[1] > stack.stack[2] && \
		stack.stack[0] < stack.stack[1])
		{
			ft_rra(stack);
		}
		else if (stack.stack[1] < stack.stack[2] && \
		stack.stack[0] > stack.stack[1])
		{
			ft_sa(stack);
		}
		if (stack.stack[0] > stack.stack[1] || stack.stack[0] > stack.stack[2] \
		|| stack.stack[1] > stack.stack[2])
		{
			ft_sort3(stack);
		}
	}
}
