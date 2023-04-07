/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:12:07 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/07 15:37:51 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *ft_sort3(int **stack, int len) // 3 2 1
{
    if ((*stack)[1] > (*stack)[2])
    {
        if ((*stack)[0] > (*stack)[1])
        {
            ft_ra(stack, len);
            ft_sa(stack);
			// ** DEBUG **
			ft_print_stack(*stack, len);
        }
        else
        {
            ft_rra(stack, len);
            if ((*stack)[0] > (*stack)[2])
            {
                ft_sa(stack);
				// ** DEBUG **
				ft_print_stack(*stack, len);
            }
        }
    }
    else //(y < z)
    {
        if ((*stack)[0] > (*stack)[2])
        {
            ft_ra(stack, len);
        }
        else if ((*stack)[0] > (*stack)[1])
        {
            ft_sa(stack);
			// ** DEBUG **
			ft_print_stack(*stack, len);
        }
    }
	return (0);
}
