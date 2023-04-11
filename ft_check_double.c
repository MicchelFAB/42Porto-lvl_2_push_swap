/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:24:51 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/11 09:55:22 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(int argc, char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (i < argc)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
			{
				printf("Duplicate found: %d at indices %d and %d\n", num1, i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
