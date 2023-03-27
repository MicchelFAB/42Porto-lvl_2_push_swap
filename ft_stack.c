/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/27 19:54:25 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	if (*len_a == 0)
		return (0);
	if (*len_b == 0)
	{
		*b = ft_realloc(*b, *len_b + 1 * sizeof(int *) );
		ft_memset(*b, 0, sizeof(int) * (*len_b + 1));
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
	return (1);
}