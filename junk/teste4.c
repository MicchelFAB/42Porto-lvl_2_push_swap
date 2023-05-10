/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:53 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 09:48:58 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push(t_stack *x, t_stack *y)
{	
	int	i;

	i = 0;
	if (x->len == 0)
	{
		return ;
	}
	if (y->len > 0)
	{
		i = y->len;
		while (i > 0)
		{
			y->stack[i] = y->stack[i - 1];
			i--;
		}
	}
	y->stack[0] = x->stack[0];
	y->len++;
	i = 0;
	while (i < x->len - 1)
	{
		x->stack[i] = x->stack[i + 1];
		i++;
	}
	x->len--;
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

int	main(int argc, char **argv)
{
	t_stash	stash;
	int		i;

	i = 0;
	stash.a.len = argc - 1;
	stash.b.len = 0;
	stash.a.stack = (int *)malloc(sizeof(int) * stash.a.len);
	stash.b.stack = (int *)malloc(sizeof(int) * stash.a.len);
	while (i < stash.a.len)
	{
		stash.a.stack[i] = ft_atol(argv[i + 1]);
		i++;
	}
	ft_pb(&stash.a, &stash.b);
	ft_pb(&stash.a, &stash.b);
	ft_pb(&stash.a, &stash.b);
	ft_printf("\nstack a: \n");
	for (int j = 0; j < stash.a.len; j++)
		ft_printf("%d ", stash.a.stack[j]);
	ft_printf("\nstack b: \n");
    for (int j = 0; j < stash.b.len; j++)
		ft_printf("%d ", stash.b.stack[j]);
	ft_printf("\n");
	free(stash.a.stack);
	free(stash.b.stack);
	return (0);
}
