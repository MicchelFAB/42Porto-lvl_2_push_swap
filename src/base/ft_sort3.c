/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:12:07 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/16 10:11:27 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sort3(t_stash stash)
{
	if (stash.a.len == 3)
	{
		if ((stash.a.stack[1] > stash.a.stack[2] && stash.a.stack[0] > \
		stash.a.stack[1]) || (stash.a.stack[1] < stash.a.stack[2] && \
		stash.a.stack[0] > stash.a.stack[2]))
		{
			ft_ra(stash);
		}
		else if (stash.a.stack[1] > stash.a.stack[2] && \
		stash.a.stack[0] < stash.a.stack[1])
		{
			ft_rra(stash);
		}
		else if (stash.a.stack[1] < stash.a.stack[2] && \
		stash.a.stack[0] > stash.a.stack[1])
		{
			ft_sa(stash);
		}
		if (stash.a.stack[0] > stash.a.stack[1] || stash.a.stack[0] > \
		stash.a.stack[2] || stash.a.stack[1] > stash.a.stack[2])
		{
			ft_sort3(stash);
		}
	}
}

