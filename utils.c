/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:33 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/21 17:43:36 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sinal;

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

// create function to convert string to long long int
long long int ft_atol(const char *nptr)
{
	long long int	res;
	int	sinal;

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

size_t	ft_strlen(int *s) // returns the length of the array
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

int ft_arrlen(int *a) // returns the length of the array
{
    int len;
	
	len = 0;
    while (a[len])
        len++;
    return len;
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

int *ft_realloc(int *a, int len)
{
    int *alloc;
    alloc = (int *)malloc(sizeof(int) * len);
    if (!alloc)
        exit(1);
    alloc = ft_memcpy(alloc, a, sizeof(int) * len);
    return (alloc);
}
