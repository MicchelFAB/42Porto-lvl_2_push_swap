/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:40:39 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 13:09:06 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_sa() call ft_swap() to swap the first two elements	*
 * of stack a and prints the operation to stdout.			*/

void	ft_sa(t_stash a)
{
	ft_swap(&a.a.stack[0], &a.a.stack[1]);
	ft_putstr_fd("sa\n", 1);
}

/* ft_sb() call ft_swap() to swap the first two elements	*
 * of stack b and prints the operation to stdout.			*/

void	ft_sb(t_stash b)
{
	ft_swap(&b.b.stack[0], &b.b.stack[1]);
	ft_putstr_fd("sb\n", 1);
}

/* ft_ss() call ft_swap() to swap the first two elements	*
 * of both stacks a and b and prints the operation to		*
 * stdout.													*/

void	ft_ss(t_stash ab)
{
	ft_swap(&ab.a.stack[0], &ab.a.stack[1]);
	ft_swap(&ab.b.stack[0], &ab.b.stack[1]);
	ft_putstr_fd("ss\n", 1);
}
