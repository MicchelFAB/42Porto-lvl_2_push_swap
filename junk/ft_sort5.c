/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:22:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/07 13:12:03 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void *ft_sort5(int **stacka, int **stackb, int lena, int lenb)
{
	int i;
	int min;
	int max;
	int *stack;

	i = 0;
	stack = *stacka;
	min = ft_min(stack, lena);
	max = ft_max(stack, lena);
	while (i < lena)
	{
		if (stack[i] == min)
		{
			ft_ra(stacka, lena);
			ft_pb(stacka, stackb, &lena, &lenb);
			lena--;
			lenb++;
		}
		else if (stack[i] == max)
		{
			ft_rra(stacka, lena);
			ft_pb(stacka, stackb, &lena, &lenb);
			lena--;
			lenb++;
		}
		else
			ft_ra(stacka, lena);
		i++;
	}
	ft_sort3(stacka, lena);
	ft_pa(stacka, stackb, &lena, &lenb);
	ft_pa(stacka, stackb, &lena, &lenb);
	return (0);
}


