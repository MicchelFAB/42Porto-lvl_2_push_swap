/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrpf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:49:27 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 11:47:23 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putunbrpf(unsigned int n)
{
	int		i;

	i = 0;
	if ((int)n >= 0 && n <= 9)
		i += ft_putcharpf(n + 48);
	else if (n > 9)
	{
		i += ft_putunbrpf(n / 10);
		i += ft_putunbrpf(n % 10);
	}
	return (i);
}
