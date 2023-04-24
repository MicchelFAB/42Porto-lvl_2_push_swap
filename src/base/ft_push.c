/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:53 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/24 11:56:57 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_push(int *x, int *y, int *len_x, int *len_y)
{
	int i;

	i = 0;
	if (*len_x == 0)
	{
		return;
	}
	if(*len_y > 0)
	{
		i = *len_y;
		while(i > 0)
		{
			y[i] = y[i - 1];
			i--;
		}
	}
	y[0] = x[0];
	(*len_y)++;
	i = 0;
	while (i < (*len_x) - 1)
	{
		x[i] = x[i + 1];
		i++;
	}
	(*len_x)--;
}

void	ft_pb(int *a, int *b, int *len_a, int *len_b)
{
	ft_push(a, b, len_a, len_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(int *a, int *b, int *len_a, int *len_b)
{
	ft_push(b, a, len_b, len_a);
	ft_putstr_fd("pa\n", 1);
}
