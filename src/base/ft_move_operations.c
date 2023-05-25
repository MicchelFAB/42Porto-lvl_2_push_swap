/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:52:16 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 12:36:40 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_less_movement(t_stash *stash)
{
	int	less_moves;

	less_moves = INT_MAX;
	stash->base.i = 0;
	while (stash->base.i < stash->b.len)
	{
		if (ft_absolute(stash->a.moves[stash->base.i])
			+ ft_absolute(stash->b.moves[stash->base.i])
			< ft_absolute(less_moves))
		{
			less_moves = ft_absolute(stash->a.moves[stash->base.i])
				+ ft_absolute(stash->b.moves[stash->base.i]);
			stash->a.base.mv_a = stash->a.moves[stash->base.i];
			stash->a.base.mv_b = stash->b.moves[stash->base.i];
		}
		stash->base.i++;
	}
	if (stash->a.base.mv_a < 0 && stash->a.base.mv_a < 0)
		ft_rrr_move(stash);
	else if (stash->a.base.mv_a > 0 && stash->a.base.mv_a > 0)
		ft_rr_move(stash);
	ft_ra_rra(stash);
	ft_rb_rrb(stash);
	ft_pa(stash);
}

void	ft_rrr_move(t_stash *stash)
{
	while (stash->a.base.mv_a < 0 && stash->a.base.mv_b < 0)
	{
		(stash->a.base.mv_a)++;
		(stash->a.base.mv_b)++;
		ft_rrr(*stash);
	}
}

void	ft_rr_move(t_stash *stash)
{
	while (stash->a.base.mv_a > 0 && stash->a.base.mv_b > 0)
	{
		(stash->a.base.mv_a)--;
		(stash->a.base.mv_b)--;
		ft_rr(*stash);
	}
}

void	ft_ra_rra(t_stash *stash)
{
	while (stash->a.base.mv_a)
	{
		if (stash->a.base.mv_a > 0)
		{
			ft_ra(*stash);
			(stash->a.base.mv_a)--;
		}
		else if (stash->a.base.mv_a < 0)
		{
			ft_rra(*stash);
			(stash->a.base.mv_a)++;
		}
	}
}

void	ft_rb_rrb(t_stash *stash)
{
	while (stash->a.base.mv_b)
	{
		if (stash->a.base.mv_b > 0)
		{
			ft_rb(*stash);
			(stash->a.base.mv_b)--;
		}
		else if (stash->a.base.mv_b < 0)
		{
			ft_rrb(*stash);
			(stash->a.base.mv_b)++;
		}
	}
}
