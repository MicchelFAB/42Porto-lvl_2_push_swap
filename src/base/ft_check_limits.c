/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:09:45 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/19 12:47:37 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int ft_integer_limits(const char *arg) 
{
	long long num = ft_atol(arg); 

	if (num > 2147483647 || num < -2147483648)
		ft_exit_error();
		return (0);
	return (1);
}

int ft_check_stack(const int *stack, int len)
{
    int i;
    
	i = 0;
    while (i < len)
    {
        if (stack[i] > 2147483647 || stack[i] < -2147483648)
			ft_exit_error();
            return (0);
        i++;
    }
    return (1);
}
