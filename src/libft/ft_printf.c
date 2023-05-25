/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:44:45 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/24 17:23:49 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_vprintf(const char fmt, va_list args)
{
	unsigned int	prnt;

	prnt = 0;
	if (fmt == 'c')
		prnt += ft_putcharpf(va_arg(args, int));
	else if (fmt == 's')
		prnt += ft_putstrpf(va_arg(args, char *));
	else if (fmt == 'x' || fmt == 'X')
		prnt += ft_puthexpf(va_arg(args, unsigned int), fmt);
	else if (fmt == 'd' || fmt == 'i')
		prnt += ft_putnbrpf(va_arg(args, int));
	else if (fmt == 'u')
		prnt += ft_putunbrpf(va_arg(args, unsigned int));
	else if (fmt == 'p')
		prnt += ft_putptrpf(va_arg(args, unsigned long long));
	return (prnt);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	result;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				result += write(1, &str[i], 1);
			else
				result += ft_vprintf(str[i + 1], args);
			i++;
		}
		else
			result += write(1, &str[i], 1);
	i++;
	}
	va_end(args);
	return (result);
}
