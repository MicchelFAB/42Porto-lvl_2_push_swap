/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_is_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:48:30 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/17 09:33:08 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_is_sorted(t_stack stack)
{
	t_stack	tmp;

	tmp.stack = stack.stack;
	stack.base.i = 0;
	while (stack.base.i < stack.len - 1)
	{
		if (tmp.stack[stack.base.i] > tmp.stack[stack.base.i + 1])
		{
			return (0);
		}
		stack.base.i++;
	}
	return (1);
}
