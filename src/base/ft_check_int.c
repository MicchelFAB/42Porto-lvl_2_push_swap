/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:48:30 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 12:51:13 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_check_int(const char *arg)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(arg);
	if (len == 0)
		return (1);
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (len == 1)
			return (1);
		i++;
	}
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int is_sorted(const int *stack, int len) // check if the stack is sorted
{
	int i = 0;

	while (i < len - 1) // loop through the stack
	{
		if (stack[i] > stack[i + 1]) // check if the current value is greater than the next value
			return (0);
		i++;
	}
	return (1);
}