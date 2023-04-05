/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/05 11:54:38 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(int **stack)
{
	int	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(int) * (ft_intlen(*stack) + 1));
	while(i < ft_intlen(*stack) - 1)
	{
		ptr[i+1] = (*stack)[i];
		i++;
	}
	ptr[0] = (*stack)[ft_intlen(*stack) - 1];
	free(*stack);
	*stack = ptr;
}

void ft_rra(int **a)
{
	ft_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void ft_rrb(int **b)
{
	ft_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void ft_rrr(int **a, int **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}