/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:42:05 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 14:59:19 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"

int	ft_printf(const char *fmt, ...);
int	ft_putcharpf(char c);
int	ft_putstrpf(char *s);
int	ft_puthexpf(unsigned long n, char format);
int	ft_putnbrpf(int n);
int	ft_putunbrpf(unsigned int n);
int	ft_putptrpf(unsigned long n);

#endif