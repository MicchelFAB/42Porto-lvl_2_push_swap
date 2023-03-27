/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:33 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/27 20:29:41 by mamaral-         ###   ########.fr       */
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

size_t	ft_strlen(int *s) 
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

int ft_arrlen(int *a)
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (unsigned char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
		while (n--)
			d[n] = s[n];
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

int *ft_realloc(int *a, int len)
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

int ft_check_double(int *a, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		if (a[i] == a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char *ft_check_char(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return ("ERRROR");
		i++;
	}
	return ("true");
}

int ft_check_stack(int *a, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		if (a[i] > 2147483647 || a[i] < -2147483648)
			return (0);
		i++;
	}
	return (1);
}