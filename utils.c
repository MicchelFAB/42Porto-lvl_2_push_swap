/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:33 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/11 12:15:01 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

/* int *ft_realloc(int *a, int len)
{
    int *alloc;
	int i;
	
    alloc = (int *)malloc(sizeof(int) * len);
    if (!alloc)
	{
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		if (i < len - 1)
			alloc[i] = a[i];
		else
			alloc[i] = 0;
		i++;
	}
    alloc = ft_memcpy(alloc, a, sizeof(int) * len);
	free(a);
    return (alloc);
}

 */

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
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
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
}

int ft_min(int *a, int len_a)
{
	int i;
	int min;

	i = 0;
	min = a[0];
	while (i < len_a)
	{
		if (a[i] < min)
			min = a[i];
		i++;
	}
	return (min);
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