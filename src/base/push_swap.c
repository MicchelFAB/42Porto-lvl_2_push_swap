/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:54:34 by mamaral-          #+#    #+#             */
/*   Updated: 2023/06/26 21:42:47 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ft_send_max() start with a loop that pushes all numbers that has	*
 * value less than half of the stack size, to stack b, then it		*
 * pushes the rest of the numbers to stack b until there is only	*
 * three numbers left in stack a. Then it sorts the three numbers	*
 * and finishes the function.										*/

void	ft_send_max(t_stash *stash)
{
	stash->base.size = stash->a.len;
	stash->base.pushed = 0;
	stash->base.i = 0;
	while ((!ft_is_sorted(stash->a)) && (stash->base.size > 6 && stash->base.i
			< stash->base.size && stash->base.pushed < stash->base.size / 2))
	{
		if (stash->a.stack[0] <= stash->base.size / 2)
		{
			ft_pb(stash);
			stash->base.pushed++;
		}
		else
			ft_ra(*stash);
		stash->base.i++;
	}
	while ((!ft_is_sorted(stash->a)) && (stash->base.size
			- stash->base.pushed > 3))
	{
		ft_pb(stash);
		stash->base.pushed++;
	}
	ft_sort_three(*stash);
}

/* ft_big_numbers() is the main function for sorting big numbers.	*
 * It starts calling ft_send_max() to push all numbers but three	*
 * to stack b. after that starts a loop where it calls ft_fit_a()	*
 * to calculate the best way to push the numbers back to stack a.	*
 * Then it calls ft_compute_moves() to calculate the best moves		*
 * to push the numbers back to stack a. Then it calls ft_less_move()*
 * to sort and push the numbers back to stack a. At the end it		*
 * checks if the stack is sorted, if not it calls ft_last_rotates()	*
 * to finish the sorting, rotating the stack to the crescent order.	*/

void	ft_big_numbers(t_stash *stash)
{
	ft_send_max(stash);
	while (stash->b.len > 0)
	{
		ft_fit_a(stash);
		ft_compute_moves(stash);
		ft_less_movement(stash);
	}
	if (!ft_is_sorted(stash->a))
		ft_last_rotates(stash);
}

/* ft_push_swap() is the main function for sorting the numbers.	It	*
 * starts checking if the stack has two numbers and if they	are	not	*
 * sorted, it calls ft_sa() to swap them. If not, checks if	the		*
 * stack has three numbers and if not sorted, it calls the function	*
 * ft_sort_three() to sort them. If the stack has more than three	*
 * numbers and not sorted, it calls ft_big_numbers() to sort them.	*/

void	push_swap(t_stash *stash)
{
	if (stash->a.len == 2 && !ft_is_sorted(stash->a))
		ft_sa(*stash);
	else if (stash->a.len == 3)
		ft_sort_three(*stash);
	else if (stash->a.len > 3 && !ft_is_sorted(stash->a))
		ft_big_numbers(stash);
}

/* main() function receives the arguments from the terminal and	*
 * first checks if they are valid, if not it calls ft_error() 	*
 * to print the error message and exit the program. Then it		*
 * calls ft_malloc_all() to allocate memory for the stacks that	*
 * will be used. After that call ft_atol() to convert the 		*
 * values to long integers and store them in the stack a. Then	*
 * determines the length of the stack a and b, and calls 		*
 * ft_index() to index the stack a. At the end it calls	the 	*
 * push_swap() function to sort the numbers. When the sorting	*
 * is done, it calls ft_free_all() to free all the memory that 	*
 * was allocated for the stacks.								*/

int	main(int argc, char **argv)
{
	t_stash	stash;
	int		i;

	ft_all_good(argc, argv);
	ft_malloc_all(&stash, argc);
	i = 0;
	while (++i < argc)
		stash.a.stack[i - 1] = ft_atol(argv[i]);
	stash.a.len = argc - 1;
	stash.b.len = 0;
	ft_index(stash);
	push_swap(&stash);
	ft_free_all(&stash);
	return (0);
}
