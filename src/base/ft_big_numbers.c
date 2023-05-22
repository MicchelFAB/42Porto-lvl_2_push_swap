/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:06:48 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 17:28:06 by mamaral-         ###   ########.fr       */
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
			stash->b.moves[i] = (stash->b.len - \
			i) * -1;
		stash->a.moves[i] = stash->b.base.result;
		if (stash->b.base.result > stash->a.len / 2)
			stash->a.moves[i] = (stash->a.len - \
			stash->b.base.result) * -1;
		i++;
	}
}

int	ft_sort_a(t_stash *stash)
{
	int	pos_a;
	int	i;
	int	max;

	pos_a = 0;
	i = 0;
	max = INT_MAX;
	while (i < stash->a.len)
	{
		if (stash->a.stack[i] > stash->b.stack[0] && stash->a.stack[i] < \
		max)
		{
			max = stash->a.stack[i];
			pos_a = i;
		}
		i++;
	}
	return (pos_a);
}

void	ft_fit_a(t_stash *stash)
{
	int	pos_a;
	int	i;

	pos_a = 0;
	i = 0;
	if (stash->b.len > 0)
		stash->b.base.result = ft_sort_a(stash);
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
