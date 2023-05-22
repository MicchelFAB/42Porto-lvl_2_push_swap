/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:24:51 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/17 17:42:40 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_all_good(const int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_check_is_int(argv[i]))
			return (0);
		i++;
	}
	if (!ft_check_double(argc, argv))
		return (0);
	if (!ft_integer_limits(*argv))
		return (0);
	return (1);
}

int	ft_check_double(const int argc, char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (i < argc)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				ft_exit_error();
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_integer_limits(const char *arg)
{
	long long	num;

	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		ft_exit_error();
	return (1);
}

int	ft_check_is_int(const char *arg)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(arg);
	if (len == 0)
		ft_exit_error();
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (len == 1)
			ft_exit_error();
		i++;
	}
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			ft_exit_error();
		i++;
	}
	return (1);
}
