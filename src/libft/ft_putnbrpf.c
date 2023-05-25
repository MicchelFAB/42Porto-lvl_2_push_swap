/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:49:17 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/24 17:23:49 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putnbrpf(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putnbrpf(n / 10);
		write(1, "8", 1);
		return (11);
	}
	if (n < 0)
	{
		i += ft_putcharpf('-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
		i += ft_putcharpf(n + 48);
	else if (n > 9)
	{
		i += ft_putnbrpf(n / 10);
		i += ft_putnbrpf(n % 10);
	}
	return (i);
}
