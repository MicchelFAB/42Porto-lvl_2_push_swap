/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:40:39 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/08 11:07:26 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sa(int *a)
{
	ft_swap(&a[0], &a[1]);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(int *b)
{
	ft_swap(&b[0], &b[1]);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(int *a, int *b)
{
	ft_swap(&a[0], &a[1]);
	ft_swap(&b[0], &b[1]);
	ft_putstr_fd("ss\n", 1);
}
