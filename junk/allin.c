// #include "../push_swap.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

int	ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	if (*len_a == 0)
		return (0);
	if (*len_b == 0)
	{
		*b = ft_realloc(*b, *len_b + 1 * sizeof(int *) );
		ft_memset(*b, 0, sizeof(int) * (*len_b + 1));
		(*b)[0] = (*a)[0];
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
		*a = ft_realloc(*a, *len_a);
		*len_b += 1;
	}
	else
	{
		*b = ft_realloc(*b, *len_b + 1);
		ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
		(*b)[0] = (*a)[0];
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
		*a = ft_realloc(*a, *len_a);
		*len_b += 1;
	}
	return (1);
}

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

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int i;

	if (argc < 3)
		return (1);

	a = malloc((argc - 1) * sizeof(int));
	b = malloc((argc - 1) * sizeof(int));
	i = 0;

	while (++i < argc)
		a[i - 1] = ft_atol(argv[i]);

	int len_a = argc - 1;
	int len_b = 0;
	ft_pa(&a, &b, &len_a, &len_b);
	ft_pa(&a, &b, &len_a, &len_b);
		
    printf("stack a: ");
    for (int j = 0; j < len_a; j++)
        printf("%d ", a[j]);

    printf("\nstack b: ");
    for (int j = 0; j < len_b; j++)
        printf("%d ", b[j]);

    printf("\n");
    free(a);
    free(b);
    return (0);
}
