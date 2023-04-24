/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:33 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/24 18:36:17 by mamaral-         ###   ########.fr       */
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

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int ft_find_min_pos_if(const int *x, int len_x, int n)
{
    int i;
    int min_pos;
    int min;

	min_pos = 0;
	min = ft_min_if(x, len_x, n);
	i = 0;
    if (n < 0 || n > len_x) 
	{
        return -1;
    }
    
    while (i < len_x)
    {
        if (x[i] == min)
        {
            min = x[i];
            min_pos = i;
        }
		i++;
    }
    return (min_pos);
}

void	ft_print_stack(int *x, int *y, int lenx, int leny)
{
    int i;

    i = 0;
    while (i < lenx || i < leny)
    {
        if (i < lenx)
            ft_printf("%d ", x[i]);
        else
            ft_printf("  ");

        if (i < leny)
            ft_printf(" %d", y[i]);
        else
            ft_printf("  ");

        ft_printf("\n");
        i++;
    }
	ft_printf("_  _\na  b\n");
}
