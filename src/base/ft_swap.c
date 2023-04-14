/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:40:39 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 18:38:30 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void ft_swap(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void ft_sa(int *a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void ft_sb(int *b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void ft_ss(int *a, int *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
