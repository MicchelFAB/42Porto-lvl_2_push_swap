/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:49:13 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 11:47:01 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_puthexpf(unsigned long n, char format)
{
	int		i;
	char	*base;

	i = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
		i += ft_putcharpf(base[n]);
	else
	{
		i += ft_puthexpf(n / 16, format);
		i += ft_puthexpf(n % 16, format);
	}
	return (i);
}
