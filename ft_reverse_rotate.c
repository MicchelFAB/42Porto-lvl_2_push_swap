/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/11 10:02:08 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(int **stack, size_t len)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(int) * (len + 1));
	while (i < len - 1)
	{
		ptr[i + 1] = (*stack)[i];
		i++;
	}
	ptr[0] = (*stack)[len - 1];
	free(*stack);
	*stack = ptr;
}

void	ft_rra(int **a, size_t len_a)
{
	ft_reverse_rotate(a, len_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(int **b, size_t len_b)
{
	ft_reverse_rotate(b, len_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(int **a, int **b, size_t len_a, size_t len_b)
{
	ft_reverse_rotate(a, len_a);
	ft_reverse_rotate(b, len_b);
	ft_putstr_fd("rrr\n", 1);
}
