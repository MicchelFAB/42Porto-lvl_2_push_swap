/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:33 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 14:35:48 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

long long int	ft_atol(const char *nptr)
{
	long long int	res;
	int				sinal;

	res = 0;
	sinal = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sinal *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sinal);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	// if (ptr == NULL)
	// 	return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

void	ft_print_stack(int *a, int len_a)
{
	int	i;

	i = 0;
	while (i < len_a)
	{
		ft_printf("%d ", a[i]);
		i++;
	}
	ft_printf("\n");
}

void ft_print_stack_all(int *a, int *b, int len_a, int len_b)
{
	ft_print_stack(a, len_a);
	ft_print_stack(b, len_b);
}


int ft_min_if(const int *a, int len_a, int pos)
{
    int temp;
    int *a_copy;
	int i;
    int j;
    
    // Create a copy of the input array
    a_copy = (int*) malloc(len_a * sizeof(int));
    ft_memcpy(a_copy, a, len_a * sizeof(int));
    
    i = 0;
    if (pos > len_a)
        exit(0);
    while (i < len_a)
    {
        j = i + 1;
        while (j < len_a)
        {
            if (a_copy[i] > a_copy[j])
            {
                temp = a_copy[i];
                a_copy[i] = a_copy[j];
                a_copy[j] = temp;
            }
            j++;
        }
        i++;
    }    
    
    // Get the n-th minimum number from the sorted copy of the array
    int result = a_copy[pos - 1];
    
    // Free the memory allocated for the copy of the array
    free(a_copy);
    
    return result;
}



int ft_max(int *a, int len_a)
{
	int i;
	int max;

	i = 0;
	max = a[0];
	while (i < len_a)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}
/* 
int main(int argc, char **argv)
{
	int *a;
	int len_a;
	int i;
	int min;

	i = 0;
	len_a = argc - 1;
	a = (int *)malloc(sizeof(int) * len_a);
	while (i < len_a)
	{
		a[i] = ft_atol(argv[i + 1]);
		i++;
	}
	min = ft_min(a, len_a, 4);
	ft_printf("min: %d \n", min);
	free(a);
	return (0);
} */