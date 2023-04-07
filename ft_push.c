/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/07 15:29:14 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_push(int **a, int **b, int *len_a, int *len_b)
{
	if (*len_a == 0)
		exit(0);
	*b = ft_realloc(*b, sizeof(int) * (*len_b + 1));
	ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
	(*b)[0] = (*a)[0];
	ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
	*len_a -= 1;
	*a = ft_realloc(*a, sizeof(int) * *len_a);
	*len_b += 1;
} */

void	ft_push(int **a, int **b, int *len_a, int *len_b)
{
  static int total_alloc_size = 0; // this will hold the total amount of memory allocated so far
  
  if (*len_a == 0)
    ft_putstr_fd("Error - trying to push from empty stack\n", 2),
	exit(0);
    
  if (total_alloc_size == 0) { // first call, allocate memory for both arrays
    total_alloc_size = (*len_a + *len_b);
    *a = ft_realloc(*a, sizeof(int) * total_alloc_size);
    *b = ft_realloc(*b, sizeof(int) * total_alloc_size);
  }
  
  if (*len_b == total_alloc_size) { // need to allocate more memory for b
    total_alloc_size *= 2; // double the amount of memory allocated so far
    *b = ft_realloc(*b, sizeof(int) * total_alloc_size);
  }
  ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
  (*b)[0] = (*a)[0]; // push element from a to b
  *len_b += 1;
  
  if (*len_a > 0) { // if there are more elements in a, shift the array left
    ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
    *len_a -= 1;
  }
}


void	ft_pb(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(a, b, len_a, len_b);
	ft_putstr_fd("pb\n", 1);
	// ** DEBUG **
	printf("\nstack a: \n");
	ft_print_stack(*a, *len_a);
    printf("\nstack b: \n");
    ft_print_stack(*b, *len_b);
    printf("\n");
}
void	ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(b, a, len_b, len_a);
	ft_putstr_fd("pa\n", 1);
	// ** DEBUG **
	printf("\nstack a: \n");
	ft_print_stack(*a, *len_a);
    printf("\nstack b: \n");
    ft_print_stack(*b, *len_b);
    printf("\n");
}
