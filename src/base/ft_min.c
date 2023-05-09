/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:57 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/08 11:56:30 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_min_if(const int *a, int len_a, int pos)
{
	int	result;
	int	*a_copy;
	int	i;
	int	j;

	a_copy = (int *) malloc(len_a * sizeof(int));
	i = 0;
	ft_memcpy(a_copy, a, len_a * sizeof(int));
	while (i < len_a)
	{
		j = i + 1;
		while (j < len_a)
		{
			if (a_copy[i] > a_copy[j])
			{
				ft_swap(&a_copy[i], &a_copy[j]);
			}
			j++;
		}
		i++;
	}	
	result = a_copy[pos];
	free(a_copy);
	return (result);
}

int	ft_max(int *a, int len_a)
{
	int	i;
	int	max;

	i = 0;
	max = a[0];
	while (i < len_a)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	ft_find_min_pos_if(const int *x, int len_x, int n)
{
	int	i;
	int	min_pos;
	int	min;

	min_pos = 0;
	min = ft_min_if(x, len_x, n);
	i = 0;
	if (n < 0 || n > len_x)
	{
		return (-1);
	}
	while (i < len_x)
	{
		if (x[i] == min)
		{
			min = x[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}
