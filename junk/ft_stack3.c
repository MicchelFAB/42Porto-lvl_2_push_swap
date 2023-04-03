/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:12:07 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/03 09:17:04 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_swap3(int *stack)
{
	int i;
	int x;
	int y;
	int z;
	
	i = 0;
	x = stack[0];
	y = stack[1];
	z = stack[2];
	while(stack)
	{
		if (y>z)
		{
			if (x>y)
			{
				ft_ra(*stack);
			}
			else
			{
				ft_rra(*stack);
			}
			ft_swap3(*stack);
		}
		else //(y < z)
		{
			if (x > z)
			{
				ft_ra(*stack);
			}
			else if (x > y)
			{
				ft_sa(*stack);
			}
			else // ( x < y < z)
			{
				return (0);
			}
			return(1);
		}
	}
}