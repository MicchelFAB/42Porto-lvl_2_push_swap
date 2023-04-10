/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:12:07 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/10 11:29:54 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort3(int **stack, int len) // 3 2 1
{
	int a = (*stack)[0];
	int b = (*stack)[1];
	int c = (*stack)[2];
		
    if (b > c)
    {
        if (a > b)
       {
            ft_ra(stack, len);
            ft_sa(stack);
			// ** DEBUG **
			ft_print_stack(*stack, len);
        }
        else
        {
            ft_rra(stack, len);
            if (a < c)
            {
                ft_sa(stack);
				// ** DEBUG **
				ft_print_stack(*stack, len);
            }
        }
    }
    else //(y < z)
    {
        if (a > c)
        {
            ft_ra(stack, len);
        }
        else if (a > b)
       {
            ft_sa(stack);
			// ** DEBUG **
			ft_print_stack(*stack, len);
        }
    }
	// if (a > b  || a > c || b > c)
	// {
	// 	ft_sort3(stack, len);
	// }
}
