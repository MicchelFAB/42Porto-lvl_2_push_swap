/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 18:39:56 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void ft_rotate(int *stack, int len)
{
    int first;
	int i;

	first = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = first;
}

void	ft_ra(int *a, int len_a)
{
	ft_rotate(a, len_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(int *b, int len_b)
{
	ft_rotate(b, len_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(int *a, int *b, int len_a, int len_b)
{
	ft_rotate(a, len_a);
	ft_rotate(b, len_b);
	ft_putstr_fd("rr\n", 1);
}
