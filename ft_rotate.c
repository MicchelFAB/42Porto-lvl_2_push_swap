/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/05 15:25:07 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(int **stack, size_t len)
{
	int	*ptr;
	size_t	i;

	i = 1;
	ptr = malloc(sizeof(int) * len);
	while(i < len)
	{
		ptr[i-1] = (*stack)[i];
		i++;
	}
	ptr[len - 1] = (*stack)[0];
	free(*stack);
	*stack = ptr;
}

void	ft_ra(int **a, size_t len_a)
{
	ft_rotate(a, len_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(int **b, size_t len_b)
{
	ft_rotate(b, len_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(int **a, int **b, size_t len_a, size_t len_b)
{
	ft_rotate(a, len_a);
	ft_rotate(b, len_b);
	ft_putstr_fd("rr\n", 1);
}