/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:52:42 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 12:26:11 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_last_rotates(t_stash *stash)
{
	int	low_pos;

	low_pos = ft_pos_value(stash->a, 0);
	if (low_pos > stash->a.len / 2)
	{
		while (low_pos++ < stash->a.len)
			ft_rra(*stash);
	}
	else
	{
		while (low_pos--)
			ft_ra(*stash);
	}
}

void	ft_compute_moves(t_stash *stash)
{	
	stash->base.i = 0;
	while (stash->base.i < stash->b.len)
	{
		stash->b.moves[stash->base.i] = stash->base.i;
		if (stash->base.i > stash->b.len / 2)
			stash->b.moves[stash->base.i] = (stash->b.len - stash->base.i) * -1;
		stash->a.moves[stash->base.i] = stash->base.result[stash->base.i];
		if (stash->base.result[stash->base.i] > stash->a.len / 2)
			stash->a.moves[stash->base.i] = (stash->a.len
					- stash->base.result[stash->base.i]) * -1;
		stash->base.i++;
	}
}

int	ft_compare_a(t_stash *stash, int b_val, int pos_a)

{
	stash->base.i = 0;
	stash->base.max = INT_MAX;
	while (stash->base.i < stash->a.len)
	{
		if (stash->a.stack[stash->base.i] > b_val
			&& stash->a.stack[stash->base.i] < stash->base.max)
		{
			stash->base.max = stash->a.stack[stash->base.i];
			pos_a = stash->base.i;
		}
		stash->base.i++;
	}
	if (stash->base.max != INT_MAX)
		return (pos_a);
	stash->base.i = 0;
	while (stash->base.i <= stash->a.len)
	{
		if (stash->a.stack[stash->base.i] < stash->base.max)
		{
			stash->base.max = stash->a.stack[stash->base.i];
			pos_a = stash->base.i;
		}
		stash->base.i++;
	}
	return (pos_a);
}

void	ft_fit_a(t_stash *stash)
{
	int	pos_a;
	int	i;

	i = 0;
	pos_a = 0;
	while (stash->b.len >= i)
	{
		pos_a = ft_compare_a(stash, stash->b.stack[i], pos_a);
		stash->base.result[i] = pos_a;
		i++;
	}
}

void	ft_sort_three(t_stash stash)
{
	if (stash.a.len == 3)
	{
		if ((stash.a.stack[1] > stash.a.stack[2] && stash.a.stack[0]
				> stash.a.stack[1]) || (stash.a.stack[1] < stash.a.stack[2]
				&& stash.a.stack[0] > stash.a.stack[2]))
		{
			ft_ra(stash);
		}
		else if (stash.a.stack[1] > stash.a.stack[2]
			&& stash.a.stack[0] < stash.a.stack[1])
		{
			ft_rra(stash);
		}
		else if (stash.a.stack[1] < stash.a.stack[2]
			&& stash.a.stack[0] > stash.a.stack[1])
		{
			ft_sa(stash);
		}
		if (stash.a.stack[0] > stash.a.stack[1] || stash.a.stack[0]
			> stash.a.stack[2] || stash.a.stack[1] > stash.a.stack[2])
		{
			ft_sort_three(stash);
		}
	}
}
