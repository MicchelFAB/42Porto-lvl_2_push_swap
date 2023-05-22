/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:06:48 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/21 10:30:02 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_a_position(t_stack **sa, int b_index, int max, int a_pos)
{
	t_stack	*a;

	a = *sa;
	while (a)
	{
		if (a->main_index > b_index && a->main_index < max)
		{
			max = a->main_index;
			a_pos = a->position;
		}
		a = a->next;
	}
	if (max != INT_MAX)
		return (a_pos);
	a = *sa;
	while (a)
	{
		if (a->main_index < max)
		{
			max = a->main_index;
			a_pos = a->position;
		}
		a = a->next;
	}
	return (a_pos);
}

void	ft_sort_a(t_stash *stash)
{
	int	pos_a;

	pos_a = 0;
	while (i < stash->b.len)
	{
		pos_a = ft_a_pos(stash->a, stash->b);
		b->base.last = pos_a;
		i++;
	}
}

void	ft_big_numbers(t_stash *stash)
{
	ft_send_half(stash);
	while (stash->b.len > 0)
	{
		ft_sort_a(stash);
	}
}

void	ft_send_half(t_stash *half)
{
	int		pushed;

	half->a.base.result = half->a.len;
	pushed = 0;
	half->a.base.i = 0;
	while (half->a.base.result > 6 && half->a.base.i < half->a.base.result && \
	pushed < half->a.base.result / 2)
	{
		if (*half->a.stack <= half->a.base.result / 2)
		{
			ft_pb(&half->a, &half->b);
			pushed++;
		}
		else
			ft_ra(*half);
		half->a.base.i++;
	}
	while (half->a.base.result - pushed > 3)
	{
		ft_pb(&half->a, &half->b);
		pushed++;
	}
	ft_sort3(*half);
}
