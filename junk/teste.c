/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:53 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/14 16:40:06 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stash	stash;
	int		i;

	i = 0;
	stash.a.len = argc - 1;
	stash.b.len = 0;
	stash.a.stack = (int *)malloc(sizeof(int) * stash.a.len);
	stash.b.stack = (int *)malloc(sizeof(int) * stash.a.len);
	while (i < stash.a.len)
	{
		stash.a.stack[i] = ft_atol(argv[i + 1]);
		i++;
	}
	ft_sort3(stash);
	ft_printf("\nstack a: \n");
	for (int j = 0; j < stash.a.len; j++)
		ft_printf("%d ", stash.a.stack[j]);
	ft_printf("\nstack b: \n");
	for (int j = 0; j < stash.b.len; j++)
		ft_printf("%d ", stash.b.stack[j]);
	ft_printf("\n");
	free(stash.a.stack);
	free(stash.b.stack);
	return (0);
}
