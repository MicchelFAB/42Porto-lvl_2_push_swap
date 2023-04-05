/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/05 10:06:10 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(int **a, int **b, int *len_a, int *len_b)
{
	if (*len_a == 0)
		exit(0);
	*b = realloc(*b, sizeof(int) * (*len_b + 1));
	ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
	(*b)[0] = (*a)[0];
	ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
	*len_a -= 1;
	*a = ft_realloc(*a, sizeof(int) * *len_a);
	*len_b += 1;
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
