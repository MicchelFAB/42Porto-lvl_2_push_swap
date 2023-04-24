/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:49:58 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/24 18:53:27 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>
#include <stdlib.h>

// function that convert the value of the element to the index of the stack
int ft_pre_radix(int *m, int size_m)
{
	int *tmp;
	int i;
	int j;
		
	tmp = malloc(sizeof(int) * size_m);
	i = 0;
	while (i < size_m)
	{
		j = ft_find_min_pos_if(m, size_m, i);
		tmp[j] = i;
		i++;
	}
	i = 0;
	while (i < size_m)
	{
		m[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (0);
}

void radix_sort(int *arr, int n) {
    int max_digit_count = 0;
    int i, j, divisor = 1;
    int *tmp = malloc(n * sizeof(int));
    int digit_count;
	int num = 0;
	int digit_value;
	
    // Determine the maximum number of digits in the input integers
    for (i = 0; i < n; i++) {
        digit_count = 0;
        num = arr[i];
        while (num != 0) {
            digit_count++;
            num /= 10;
        }
        if (digit_count > max_digit_count) {
            max_digit_count = digit_count;
        }
    }
    
    // Sort the input integers by each digit position
    for (i = 0; i < max_digit_count; i++) {
        int bucket[10] = {0};
        
        // Count the number of integers with each digit value
        for (j = 0; j < n; j++) {
            int digit_value = (arr[j] / divisor) % 10;
            bucket[digit_value]++;
        }
        
        // Calculate the starting index of each bucket
        for (j = 1; j < 10; j++) {
            bucket[j] += bucket[j-1];
        }
        
        // Move integers into temporary array in bucket order
        for (j = n-1; j >= 0; j--) {
            digit_value = (arr[j] / divisor) % 10;
            tmp[--bucket[digit_value]] = arr[j];
        }
        
        // Copy the temporary array back to the original array
        for (j = 0; j < n; j++) {
            arr[j] = tmp[j];
        }
        
        divisor *= 10;
    }
    
    free(tmp);
}

void radix_sort_stacks(int *a, int *b, int len_a, int len_b) 
{
    // Concatenate stacks a and b into a single array for sorting
    int *arr = malloc((len_a + len_b) * sizeof(int));
    int i;

	ft_print_stack(a, b, len_a, len_b);
	ft_pre_radix(a, len_a);
	ft_print_stack(a, b, len_a, len_b);
	
    for (i = 0; i < len_a; i++) {
        arr[i] = a[i];
    }
    for (i = 0; i < len_b; i++) {
        arr[len_a + i] = b[i];
    }
    
    // Sort the concatenated array
    radix_sort(arr, len_a + len_b);
    
    // Split the sorted array back into stacks a and b
    for (i = 0; i < len_a; i++) {
        a[i] = arr[i];
    }
    for (i = 0; i < len_b; i++) {
        b[i] = arr[len_a + i];
    }
    
    free(arr);
}

int main(int argc, char **argv) {
    int *a;
    int *b;
    int len_a;
    int len_b;
    int i;
    
    if (argc < 2) {
        ft_printf("Error: No arguments enough\n");
        return 0;
    }
    
    a = (int*) malloc(sizeof(int) * (argc-1));
    b = (int*) malloc(sizeof(int) * (argc-1));
    i = 0;
    
    while (++i < argc) {
        a[i-1] = atoi(argv[i]);
    }
    
    len_a = argc - 1;
    len_b = 0;
	
	// for(int i = 1; i < len_a; i++)
	// 	ft_printf("%d ", ft_find_min_pos_if(a, len_a, i));
	radix_sort_stacks(a, b, len_a, len_b);
    	
	ft_printf("\nstack a: \n");
    for (int j = 0; j < len_a; j++)
        ft_printf("%d ", a[j]);

    ft_printf("\nstack b: \n");
    for (int j = 0; j < len_b; j++)
        ft_printf("%d ", b[j]);

    ft_printf("\n");
    free(a);
    free(b);
    return (0);
}

