/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:54:34 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 12:28:14 by mamaral-         ###   ########.fr       */
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

void	ft_send_max(t_stash *half)
{
	int	pushed;
	int	size;
	int	i;

	size = half->a.len;
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if (half->a.stack[0] <= size / 2)
		{
			ft_pb(half);
			pushed++;
		}
		else
			ft_ra(*half);
		i++;
	}
	while (size - pushed > 3)
	{
		ft_pb(half);
		pushed++;
	}
	ft_sort_three(*half);
}

void	ft_big_numbers(t_stash *stash)
{
	ft_send_max(stash);
	while (stash->b.len > 0)
	{
		ft_fit_a(stash);
		ft_compute_moves(stash);
		ft_less_movement(stash);
	}
	if (!ft_is_sorted(stash->a))
		ft_last_rotates(stash);
}

void	push_swap(t_stash *stash)
{
	if (stash->a.len == 2 && !ft_is_sorted(stash->a))
		ft_sa(*stash);
	else if (stash->a.len == 3)
		ft_sort_three(*stash);
	else if (stash->a.len > 3 && !ft_is_sorted(stash->a))
		ft_big_numbers(stash);
}

int	main(int argc, char **argv)
{
	t_stash	stash;
	int		i;

	ft_all_good(argc, argv);
	ft_malloc_all(&stash, argc);
	i = 0;
	while (++i < argc)
		stash.a.stack[i - 1] = ft_atol(argv[i]);
	stash.a.len = argc - 1;
	stash.b.len = 0;
	ft_index(stash);
	push_swap(&stash);
	ft_free_all(&stash);
	return (0);
}
