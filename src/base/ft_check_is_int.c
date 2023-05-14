/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_is_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:48:30 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/14 16:30:31 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_check_is_int(const char *arg)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(arg);
	if (len == 0)
	{
		ft_exit_error();
		return (0);
	}
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i] || arg[i] == '-' || arg[i] == '+'))
		{
			if (len == 1)
			{
				ft_exit_error();
				return (0);
			}
		i++;
		}
	}
	return (1);
}

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
