/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:52:42 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/24 12:03:05 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/push_swap.h"

void	last_rotates(t_stash *stash)
{
	int	lower_position;

	lower_position = ft_find_min_pos_if(stash->a, 0);
	if (lower_position > stash->a.len / 2)
	{
		while (lower_position++ < stash->a.len)
			ft_rra(*stash);
	}
	else
	{
		while (lower_position--)
			ft_ra(*stash);
	}
}

void	ft_calc_moviment(t_stash *stash)
{	
	int	i;

	i = 0;
	while (i < stash->b.len)
	{
		stash->b.moves[i] = i;
		if (i > stash->b.len / 2)
			stash->b.moves[i] = (stash->b.len - i) * -1;
		stash->a.moves[i] = stash->b.base.result[i];
		if (stash->b.base.result[i] > stash->a.len / 2)
			stash->a.moves[i] = (stash->a.len - stash->b.base.result[i]) * -1;
		i++;
	}
}

int	ft_sort_a(t_stash *stash, int b_num, int pos_a)

{
	stash->tmp = 0;
	stash->b.base.max = INT_MAX;
	while (stash->tmp < stash->a.len)
	{
		if (stash->a.stack[stash->tmp] > b_num && stash->a.stack[stash->tmp] < \
		stash->b.base.max)
		{
			stash->b.base.max = stash->a.stack[stash->tmp];
			pos_a = stash->tmp;
		}
		stash->tmp++;
	}
	if (stash->b.base.max != INT_MAX)
		return (pos_a);
	stash->tmp = 0;
	while (stash->tmp <= stash->a.len)
	{
		if (stash->a.stack[stash->tmp] < stash->b.base.max)
		{
			stash->b.base.max = stash->a.stack[stash->tmp];
			pos_a = stash->tmp;
		}
		stash->tmp++;
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
		pos_a = ft_sort_a(stash, stash->b.stack[i], pos_a);
		stash->b.base.result[i] = pos_a;
		i++;
	}
}

void	ft_send_half(t_stash *half)
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
	ft_sort3(*half);
}
