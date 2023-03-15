/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:37 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/15 13:50:34 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rra(int **a)
{
	int	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(int) * (ft_strlen(*a) + 1));
	while(i < ft_strlen(*a) - 1)
	{
		ptr[i+1] = (*a)[i];
		i++;
	}
	ptr[0] = (*a)[ft_strlen(*a) - 1];
	*a = ptr;
	return (1);
}
