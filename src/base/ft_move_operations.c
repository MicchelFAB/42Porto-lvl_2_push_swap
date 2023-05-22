/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:52:16 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 16:03:58 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	less_moves_sort(t_stash *stash)
{
	int	less_moves;
	int	j;

	less_moves = INT_MAX;
	j = 0;
	while (j < stash->b.len)
	{
		if (absolute(stash->a.moves[0]) + \
		absolute(stash->b.moves[j]) < absolute(less_moves))
		{
			less_moves = absolute(stash->a.moves[0]) + \
			absolute(stash->b.moves[j]);
			stash->a.base.result = stash->a.moves[0];
			stash->b.base.result = stash->b.moves[j];
		}
		j++;
	}
	if (stash->a.base.result < 0 && stash->b.base.result < 0)
		reverse_both(stash);
	else if (stash->a.base.result > 0 && stash->b.base.result > 0)
		rotate_both(stash);
	rotate_a(stash);
	rotate_b(stash);
	ft_pa(stash);
}

void	reverse_both(t_stash *stash)
{
	while (stash->a.base.result < 0 && stash->b.base.result < 0)
	{
		(stash->a.base.result)++;
		(stash->b.base.result)++;
		ft_rrr(*stash);
	}
}

void	rotate_both(t_stash *stash)
{
	while (stash->a.base.result > 0 && stash->b.base.result > 0)
	{
		(stash->a.base.result)--;
		(stash->b.base.result)--;
		ft_rr(*stash);
	}
}

void	rotate_a(t_stash *stash)
{
	while (stash->a.base.result)
	{
		if (stash->a.base.result > 0)
		{
			ft_ra(*stash);
			(stash->a.base.result)--;
		}
		else if (stash->a.base.result < 0)
		{
			ft_rra(*stash);
			(stash->a.base.result)++;
		}
	}
}

void	rotate_b(t_stash *stash)
{
	while (stash->b.base.result)
	{
		if (stash->b.base.result > 0)
		{
			ft_rb(*stash);
			(stash->b.base.result)--;
		}
		else if (stash->b.base.result < 0)
		{
			ft_rrb(*stash);
			(stash->b.base.result)++;
		}
	}
}
