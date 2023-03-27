#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	if (*len_a == 0)
		return (0);
	if (*len_b == 0)
	{
		*b = ft_realloc(*b, *len_b);
		ft_memset(*b, 0, sizeof(int) * (*len_b));
		(*b)[0] = (*a)[0];
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
		*a = ft_realloc(*a, *len_a);
		*len_b += 1;
	}
	else
	{ 
		*b = ft_realloc(*b, *len_b);
		ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
		(*b)[0] = (*a)[0];
		ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
		*len_a -= 1;
		*a = ft_realloc(*a, *len_a);
		*len_b += 1;
	}
	return (1);
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
	ft_pa(&a, &b, &len_a, &len_b);
	ft_pa(&a, &b, &len_a, &len_b);
	ft_pa(&a, &b, &len_a, &len_b);
	ft_pa(&a, &b, &len_a, &len_b);
	ft_pa(&a, &b, &len_a, &len_b);
	ft_pa(&a, &b, &len_a, &len_b);
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
