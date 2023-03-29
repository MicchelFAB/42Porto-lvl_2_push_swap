/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/28 19:22:01 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(int **a)
{
	int	*ptr;
	size_t	i;

	i = 1;
	ptr = malloc(sizeof(int) * (ft_intlen(*a) + 1));
	while(i < ft_intlen(*a))
	{
		ptr[i-1] = (*a)[i];
		i++;
	}
	ptr[ft_intlen(*a) - 1] = (*a)[0];
	*a = ptr;
	return (1);
}

int	ft_rb(int **b)
{
	int	*ptr;
	size_t	i;

	i = 1;
	ptr = malloc(sizeof(int) * (ft_intlen(*b) + 1));
	while(i < ft_intlen(*b))
	{
		ptr[i-1] = (*b)[i];
		i++;
	}
	ptr[ft_intlen(*b) - 1] = (*b)[0];
	*b = ptr;
	return (1);
}
