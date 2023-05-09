/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:11:12 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/08 14:32:51 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort5_helper(int *stacka, int *stackb, int *len_a, int *len_b)
{
	while (stacka[0] != min_x)
	{
		if (posx > posz && *len_a > 4)
		{
			while (stacka[0] != min_z)
			{
				if (posz > (*len_a / 2 && *len_b < 1))
					ft_rra(stacka, *len_a);
				else if (posz < (*len_a / 2))
					ft_ra(stacka, *len_a);
			}
			if (stacka[0] > stacka[1] && stacka[0] == min_z && stacka[1] == min_x)
				ft_sa(stacka);
			else
				ft_pb(stacka, stackb, len_a, len_b);
		}	
		else if (posx < (*len_a / 2 && *len_b < 1))
			ft_rra(stacka, *len_a);
		else
			ft_ra(stacka, *len_a);
	}
}

void	*ft_sort5(int *stacka, int *stackb, int *len_a, int *len_b)
{
	int	min_x;
	int	min_z;
	int	posx;
	int	posz;

	while (*len_a > 3)
	{
		min_x = ft_min_if(stacka, *len_a, 0);
		min_z = ft_min_if(stacka, *len_a, 1);
		posx = ft_find_min_pos_if(stacka, *len_a, 0);
		posz = ft_find_min_pos_if(stacka, *len_a, 1);
		if (!ft_is_sorted(stacka, *len_a))
		{
			while (stacka[0] != min_x)
			{
				if (posx > posz && *len_a > 4)
				{
					while (stacka[0] != min_z)
					{
						if (posz > (*len_a / 2 && *len_b < 1))
							ft_rra(stacka, *len_a);
						else if (posz < (*len_a / 2))
							ft_ra(stacka, *len_a);
					}
					if (stacka[0] > stacka[1] && stacka[0] == min_z && stacka[1] == min_x)
						ft_sa(stacka);
					else
						ft_pb(stacka, stackb, len_a, len_b);
				}	
				else if (posx < (*len_a / 2 && *len_b < 1))
					ft_rra(stacka, *len_a);
				else
					ft_ra(stacka, *len_a);
			}
			if (stacka[0] == min_x)
				{ft_pb(stacka, stackb, len_a, len_b);
				ft_print_stack(stacka, stackb, *len_a, *len_b);}
		}
	}
	ft_sort3(stacka, *len_a);
	if (*len_b == 2 && stackb[0] < stackb[1])
		ft_sb(stackb);
	while (*len_b > 0)
	{
		min_z = ft_max(stackb, *len_b);
		if (stackb[0] == min_z)
			{ft_pa(stacka, stackb, len_a, len_b);
			ft_print_stack(stacka, stackb, *len_a, *len_b);}
		else if (stackb[*len_b - 1] == min_z)
			ft_rrb(stackb, *len_b);
		else if (stackb[0] < min_z && stackb[*len_b - 1] < min_z)
		{
			ft_pa(stacka, stackb, len_a, len_b);
			if (stacka[0] > stacka[1])
				ft_sa(stacka);
		}
		else if (stackb[0] < min_z)
			ft_pa(stacka, stackb, len_a, len_b);
		else
			ft_rb(stackb, *len_b);
	}
	return (0);
}
