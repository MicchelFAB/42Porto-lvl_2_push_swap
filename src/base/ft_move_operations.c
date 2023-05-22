/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:52:16 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 18:50:59 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	less_moves_sort(t_stash *stash)
{
	int	less_moves;
	int	j;
	int	mv_a;
	int	mv_b;

	less_moves = INT_MAX;
	j = 0;
	while (j < stash->b.len)
	{
		if (absolute(stash->a.moves[j]) + absolute(stash->b.moves[0]) < absolute(less_moves))
		{
			less_moves = absolute(stash->a.moves[0]) + absolute(stash->b.moves[0]);
			mv_a = stash->a.moves[j];
			mv_b = stash->b.moves[j];
		}
		j++;
	}
	if (mv_a < 0 && mv_a < 0)
		reverse_both(stash, &mv_a, &mv_b);
	else if (mv_a > 0 && mv_a > 0)
		rotate_both(stash, &mv_a, &mv_b);
	rotate_a(stash, &mv_a);
	rotate_b(stash, &mv_b);
	ft_pa(stash);
}

void	reverse_both(t_stash *stash, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		ft_rrr(*stash);
	}
}

void	rotate_both(t_stash *stash, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		ft_rr(*stash);
	}
}

void	rotate_a(t_stash *stash, int *mv_a)
{
	while (*mv_a)
	{
		if (*mv_a > 0)
		{
			ft_ra(*stash);
			(*mv_a)--;
		}
		else if (*mv_a < 0)
		{
			ft_rra(*stash);
			(*mv_a)++;
		}
	}
}

void	rotate_b(t_stash *stash, int *mv_b)
{
	while (*mv_b)
	{
		if (*mv_b > 0)
		{
			ft_rb(*stash);
			(*mv_b)--;
		}
		else if (*mv_b < 0)
		{
			ft_rrb(*stash);
			(*mv_b)++;
		}
	}
}
