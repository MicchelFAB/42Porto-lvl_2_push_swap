/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 18:39:49 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_reverse_rotate(int *stack, int len)
{
	int		last;
	int	i;

	i = len - 1;
	last = stack[len - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	ft_rra(int *a, int len_a)
{
	ft_reverse_rotate(a, len_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(int *b, int len_b)
{
	ft_reverse_rotate(b, len_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(int *a, int *b, int len_a, int len_b)
{
	ft_reverse_rotate(a, len_a);
	ft_reverse_rotate(b, len_b);
	ft_putstr_fd("rrr\n", 1);
}
