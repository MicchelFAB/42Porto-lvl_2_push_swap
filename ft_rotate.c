/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/05 11:54:21 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(int **stack)
{
	int	*ptr;
	size_t	i;

	i = 1;
	ptr = malloc(sizeof(int) * (ft_intlen(*stack) + 1));
	while(i < ft_intlen(*stack))
	{
		ptr[i-1] = (*stack)[i];
		i++;
	}
	ptr[ft_intlen(*stack) - 1] = (*stack)[0];
	free(*stack);
	*stack = ptr;
}

void	ft_ra(int **a)
{
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(int **b)
{
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(int **a, int **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", 1);
}