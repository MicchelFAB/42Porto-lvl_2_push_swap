/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:12:07 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/17 11:49:24 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sort3(int *stack, int len)
{
	if (len == 3)
	{
		if ((stack[1] > stack[2] && stack[0] > stack[1]) \
		|| (stack[1] < stack[2] && stack[0] > stack[2]))
		{
			ft_ra(stack, len);
		}
		else if (stack[1] > stack[2] && stack[0] < stack[1])
		{
			ft_rra(stack, len);
		}
		else if (stack[1] < stack[2] && stack[0] > stack[1])
		{
			ft_sa(stack);
		}
		if (stack[0] > stack[1] || stack[0] > stack[2] \
		|| stack[1] > stack[2])
		{
			ft_sort3(stack, len);
		}
	}
}
