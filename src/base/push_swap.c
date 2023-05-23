/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:50:46 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 19:26:07 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_is_sorted(t_stack stack)
{
	t_stack	tmp;

	tmp.stack = stack.stack;
	stack.base.i = 0;
	while (stack.base.i < stack.len - 1)
	{
		if (tmp.stack[stack.base.i] > tmp.stack[stack.base.i + 1])
		{
			return (0);
		}
		stack.base.i++;
	}
	return (1);
}

void	ft_big_numbers(t_stash *stash)
{
	ft_send_half(stash);
	while (stash->b.len > 0)
	{
		ft_fit_a(stash);
		ft_calc_moviment(stash);
		less_moves_sort(stash);
	}
	if (!ft_is_sorted(stash->a))
		last_rotates(stash);
}

void	push_swap(t_stash *stash)
{
	if (stash->a.len == 2 && !ft_is_sorted(stash->a))
		ft_sa(*stash);
	else if (stash->a.len == 3)
		ft_sort3(*stash);
	else if (stash->a.len > 3 && !ft_is_sorted(stash->a))
		ft_big_numbers(stash);
}

void	ft_malloc_all(t_stash *stash, int argc)
{
	stash->a.stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.moves = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.moves = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.base.result = (int *)ft_calloc(sizeof(int), (argc - 1));
}

int	main(int argc, char **argv)
{
	t_stash	stash;
	int		i;

	if (argc < 2)
		return (0);
	if (!ft_all_good(argc, argv))
		return (0);
	ft_malloc_all(&stash, argc);
	i = 0;
	while (++i < argc)
		stash.a.stack[i - 1] = ft_atol(argv[i]);
	stash.a.len = argc - 1;
	stash.b.len = 0;
	ft_index(stash.a);
	push_swap(&stash);
	// ft_print_stack(stash);
	ft_free_all(&stash);
	return (0);
}
