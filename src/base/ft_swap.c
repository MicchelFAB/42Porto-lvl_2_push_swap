/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:40:39 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 19:41:51 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sa(t_stash a)
{
	ft_swap(&a.a.stack[0], &a.a.stack[1]);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stash b)
{
	ft_swap(&b.b.stack[0], &b.b.stack[1]);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stash ab)
{
	ft_swap(&a.a.stack[0], &a.a.stack[1]);
	ft_swap(&b.b.stack[0], &b.b.stack[1]);
	ft_putstr_fd("ss\n", 1);
}
