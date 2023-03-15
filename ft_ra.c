/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/15 12:44:07 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(int **a)
{
	int	*rotated_arguments;
	size_t	i;

	i = 1;
	rotated_arguments = malloc(sizeof(int) * (ft_strlen(*a) + 1));
	while(i < ft_strlen(*a))
	{
		rotated_arguments[i-1] = (*a)[i];
		i++;
	}
	rotated_arguments[ft_strlen(*a) - 1] = (*a)[0];
	*a = rotated_arguments;
	return (1);
}

