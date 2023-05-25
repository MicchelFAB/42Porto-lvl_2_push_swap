/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:57 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/25 15:05:17 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_is_sorted() checks if all elements of the stack is sorted.	*/

int	ft_is_sorted(t_stack stack)
{
	t_stack	tmp;

	tmp.stack = stack.stack;
	stack.base.i = 0;
	while (stack.base.i < stack.len - 1)
	{
		if (tmp.stack[stack.base.i] > tmp.stack[stack.base.i + 1])
		{
			return (0);
		}
		stack.base.i++;
	}
	return (1);
}

/* ft_exit_error() prints "Error" to the standard error and exits	*/

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/* ft_print_stack() function created to emulate the output of the	*
 * subject.															*/

void	ft_print_stack(t_stack stacka, t_stack stackb)
{
	stacka.base.i = 0;
	while (stacka.base.i < stacka.len || stacka.base.i < stackb.len)
	{
		if (stacka.base.i < stacka.len)
			ft_printf("%d ", stacka.stack[stacka.base.i]);
		else
			ft_printf("  ");
		if (stacka.base.i < stackb.len)
			ft_printf(" %d", stackb.stack[stacka.base.i]);
		else
			ft_printf("  ");
		ft_printf("\n");
		stacka.base.i++;
	}
	ft_printf("_  _\na  b\n");
}

/* ft_free_all() frees all the allocated memory. */

void	ft_free_all(t_stash *stash)
{
	free(stash->base.result);
	free(stash->a.base.tmp);
	free(stash->a.base.tpm);
	free(stash->a.stack);
	free(stash->b.stack);
	free(stash->a.moves);
	free(stash->b.moves);
}

/* ft_malloc_all() allocates memory for all the stacks and arrays.	*/

void	ft_malloc_all(t_stash *stash, int argc)
{
	stash->a.stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.stack = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->b.moves = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.moves = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->base.result = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.base.tmp = (int *)ft_calloc(sizeof(int), (argc - 1));
	stash->a.base.tpm = (int *)ft_calloc(sizeof(int), (argc - 1));
}
