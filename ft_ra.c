/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:59:49 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/15 13:49:24 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(int **a)
{
	int	*ptr;
	size_t	i;

	i = 1;
	ptr = malloc(sizeof(int) * (ft_strlen(*a) + 1));
	while(i < ft_strlen(*a))
	{
		ptr[i-1] = (*a)[i];
		i++;
	}
	ptr[ft_strlen(*a) - 1] = (*a)[0];
	*a = ptr;
	return (1);
}
