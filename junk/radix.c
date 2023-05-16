/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   radix.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mamaral- <mamaral-@student.42porto.com	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/24 16:49:58 by mamaral-		  #+#	#+#			 */
/*   Updated: 2023/05/08 08:54:23 by mamaral-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/push_swap.h"

// function that convert the value of the element to the index of the stack
void	ft_pre_radix(t_stack stack)
{
	int	*tmp;
	tmp = malloc(stack.len * sizeof(int));
	ft_memcpy(tmp, stack.stack, stack.len * sizeof(int));
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.base.j = ft_find_min_pos_if(stack, stack.base.i);
		tmp[stack.base.j] = stack.base.i;
		stack.base.i++;
	}
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		stack.stack[stack.base.i] = tmp[stack.base.i];
		stack.base.i++;
	}
	free(tmp);
}

/* void	radix_sort(int *arr, int n)
{
	int	max_digit_count = 0;
	int	i,	j,	divisor = 1;
	int	*tmp = malloc(n * sizeof(int));
	int	digit_count;
	int	num = 0;
	int	digit_value;

	// Determine the maximum number of digits in the input integers
	for	(i = 0; i < n; i++)
	{
		digit_count = 0;
		num = arr[i];
		while (num != 0)
		{
			digit_count++;
			num /= 10;
		}
		if (digit_count > max_digit_count)
		{
			max_digit_count = digit_count;
		}
	}
	// Sort the input integers by each digit position
	for (i = 0; i < max_digit_count; i++)
	{
		int	bucket[10] = {0};

		// Count the number of integers with each digit value
		for (j = 0; j < n; j++) 
		{
			int digit_value = (arr[j] / divisor) % 10;
			bucket[digit_value]++;
		}

		// Calculate the starting index of each bucket
		for (j = 1; j < 10; j++) 
		{
			bucket[j] += bucket[j - 1];
		}

		// Move integers into temporary array in bucket order
		for (j = n-1; j >= 0; j--) 
		{
			digit_value = (arr[j] / divisor) % 10;
			tmp[--bucket[digit_value]] = arr[j];
		}

		// Copy the temporary array back to the original array
		for (j = 0; j < n; j++) 
		{
			arr[j] = tmp[j];
		}

		divisor *= 10;
	}

	free(tmp);
}

void	radix_sort_stacks(t_stash stash)
{
	// Concatenate stacks a and b into a single array for sorting
	t_stash *arr;
	int	i;

	arr = malloc((stash.a.len + stash.b.len) * sizeof(int));
	ft_print_stack(stash);
	ft_pre_radix(arr.a);
	ft_print_stack(stash);
	for (i = 0; i < len_a; i++) 
	{
		arr[i] = a[i];
	}
	for (i = 0; i < len_b; i++) 
	{
		arr[len_a + i] = b[i];
	}
	// Sort the concatenated array
	radix_sort(arr, len_a + len_b);
	// Split the sorted array back into stacks a and b
	for (i = 0; i < len_a; i++) 
	{
		a[i] = arr[i];
	}
	for (i = 0; i < len_b; i++) 
	{
		b[i] = arr[len_a + i];
	}
	free(arr);
}
 */
int	main(int argc, char **argv)
{
	t_stash	stash;
	int	i;

	if (argc < 2)
	{
		ft_printf("Error: No arguments enough\n");
		return (0);
	}
	stash.a.stack = (int *)malloc(sizeof(int) * (argc-1));
	stash.b.stack = (int *)malloc(sizeof(int) * (argc-1));
	i = 0;
	while (++i < argc)
		stash.a.stack[i - 1] = ft_atol(argv[i]);

	stash.a.len = argc - 1;
	stash.b.len = 0;

	// for(int i = 1; i < len_a; i++)
	// 	ft_printf("%d ", ft_find_min_pos_if(a, len_a, i));
	// printf("min pos: %d\n", ft_find_min_pos_if(stash.a, 0));
	// printf("min 0: %d  position 0: %d\n", ft_min_if(stash.a, 0), ft_find_min_pos_if(stash.a, 0));
	// printf("min 1: %d  position 1: %d\n", ft_min_if(stash.a, 1), ft_find_min_pos_if(stash.a, 1));
	// printf("min 2: %d  position 2: %d\n", ft_min_if(stash.a, 2), ft_find_min_pos_if(stash.a, 2));

	ft_pre_radix(stash.a);
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
