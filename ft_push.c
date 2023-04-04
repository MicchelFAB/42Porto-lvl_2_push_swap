/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:53 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(int **a, int **b, int *len_a, int *len_b)
{
	if (*len_a == 0)
		exit(0);
	if (*len_b == 0)
	{	
		if(**b == NULL)
			*b[0] = 0;
		*b = ft_realloc(*b, *len_b + 1);
		ft_calloc(**b, sizeof(int) * (*len_b + 1));
		(*b)[0] = (*a)[0];
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
		*a = ft_realloc(*a, *len_a);
		*len_b += 1;
	}
	else
	{
		*b = ft_realloc(*b, *len_b + 1);
		ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
		(*b)[0] = (*a)[0];
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
		*a = ft_realloc(*a, *len_a);
		*len_b += 1;
	}
}

void	ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(a, b, len_a, len_b);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(b, a, len_b, len_a);
	ft_putstr_fd("pb\n", 1);
}
