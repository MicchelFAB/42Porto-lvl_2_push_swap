/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:57 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 12:35:08 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_print_stack(t_stack stacka, t_stack stackb)
{
	stacka.base.i = 0;
	while (stacka.base.i < stacka.len || stacka.base.i < stackb.len)
	{
		if (stacka.base.i < stacka.len)
			ft_printf("%d ", stacka.stack[stacka.base.i]);
		else
			ft_printf("  ");
		if (stacka.base.i < stackb.len)
			ft_printf(" %d", stackb.stack[stacka.base.i]);
		else
			ft_printf("  ");
		ft_printf("\n");
		stacka.base.i++;
	}
	ft_printf("_  _\na  b\n");
}

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_free_all(t_stash *stash)
{
	free(stash->base.result);
	free(stash->a.base.tmp);
	free(stash->a.base.tpm);
	free(stash->a.stack);
	free(stash->b.stack);
	free(stash->a.moves);
	free(stash->b.moves);
}

void	ft_malloc_all(t_stash *stash, int argc)
{
	stash->a.stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.moves = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.moves = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->base.result = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.base.tmp = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.base.tpm = (int *)ft_calloc(sizeof(int), (argc - 1));
}
