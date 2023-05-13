/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:57 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 19:56:31 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

long long int	ft_atol(const char *nptr)
{
	long long int	res;
	int				sinal;

	res = 0;
	sinal = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sinal *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sinal);
}

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_print_stack(t_stash stash)
{
	stash.a.base.i = 0;
	while (stash.a.base.i < stash.a.len || stash.a.base.i < stash.b.len)
	{
		if (stash.a.base.i < stash.a.len)
			ft_printf("%d ", stash.a.stack[stash.a.base.i]);
		else
			ft_printf("  ");
		if (stash.a.base.i < stash.b.len)
			ft_printf(" %d", stash.b.stack[stash.a.base.i]);
		else
			ft_printf("  ");
		ft_printf("\n");
		stash.a.base.i++;
	}
	ft_printf("_  _\na  b\n");
}
