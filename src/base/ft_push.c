/* ************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 19:10:13 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************* */

#include "../../inc/push_swap.h"

void	ft_push(int *x, int *y, int *len_x, int *len_y)
{
    if (*len_x == 0)
        return;
    (*len_y)++;
    y[*len_y - 1] = x[0];
    for (int i = 0; i < (*len_x) - 1; i++)
        x[i] = x[i + 1];
    (*len_x)--;
}

void	ft_pb(int *a, int *b, int *len_a, int *len_b)
{
	ft_push(a, b, len_a, len_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(int *a, int *b, int *len_a, int *len_b)
{
	ft_push(b, a, len_b, len_a);
	ft_putstr_fd("pa\n", 1);
}
