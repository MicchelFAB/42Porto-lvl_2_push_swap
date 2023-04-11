/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/11 10:00:25 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(int **a, int **b, int *len_a, int *len_b)
{
	static int	total_alloc_size;

	total_alloc_size = 0;
	if (*len_a == 0)
		ft_putstr_fd("Error - trying to push from empty stack\n", 2);
	if (total_alloc_size == 0)
	{
		total_alloc_size = (*len_a + *len_b);
		*a = ft_realloc(*a, sizeof(int) * total_alloc_size);
		*b = ft_realloc(*b, sizeof(int) * total_alloc_size);
	}
	if (*len_b == total_alloc_size)
	{
		total_alloc_size *= 2;
		*b = ft_realloc(*b, sizeof(int) * total_alloc_size);
	}
	ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
	(*b)[0] = (*a)[0];
	*len_b += 1;
	if (*len_a > 0)
	{
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
	}
}

void	ft_pb(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(a, b, len_a, len_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(b, a, len_b, len_a);
	ft_putstr_fd("pa\n", 1);
}
