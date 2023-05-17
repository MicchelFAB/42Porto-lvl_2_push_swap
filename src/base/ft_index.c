/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:10:45 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/16 09:47:27 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_index(t_stack stack)
{
	int	*tmp;

	tmp = malloc(stack.len * sizeof(int));
	ft_memcpy(tmp, stack.stack, stack.len * sizeof(int));
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.base.j = ft_find_min_pos_if(stack, stack.base.i);
		tmp[stack.base.j] = stack.base.i;
		stack.base.i++;
	}
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.stack[stack.base.i] = tmp[stack.base.i];
		stack.base.i++;
	}
	free(tmp);
}
