/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/07 15:23:58 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(int **stack, size_t len)
{
	int	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(int) * (len + 1));
	while(i < len - 1)
	{
		ptr[i+1] = (*stack)[i];
		i++;
	}
	ptr[0] = (*stack)[len - 1];
	free(*stack);
	*stack = ptr;
}

void ft_rra(int **a, size_t len_a)
{
	ft_reverse_rotate(a, len_a);
	ft_putstr_fd("rra\n", 1);
	// ** DEBUG **
	printf("\nstack a: \n");
	ft_print_stack(*a, (size_t)len_a);
}

void ft_rrb(int **b, size_t len_b)
{
	ft_reverse_rotate(b, len_b);
	ft_putstr_fd("rrb\n", 1);
	// ** DEBUG **
	printf("\nstack b: \n");
	ft_print_stack(*b, (size_t)len_b);
}

void ft_rrr(int **a, int **b, size_t len_a, size_t len_b)
{
	ft_reverse_rotate(a, len_a);
	ft_reverse_rotate(b, len_b);
	ft_putstr_fd("rrr\n", 1);
	// ** DEBUG **
	printf("\nstack a: \n");
	ft_print_stack(*a, (size_t)len_a);
	printf("\nstack b: \n");
	ft_print_stack(*b, (size_t)len_b);
}