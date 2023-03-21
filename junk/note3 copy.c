#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// int *ft_realloc(int *a, int len)
// {
//     int *alloc;
//     alloc = (int *)malloc(sizeof(int) * len);
//     if (!alloc)
//         exit(1);
//     alloc = ft_memcpy(alloc, a, sizeof(int) * len);
//     return (alloc);
// }

int ft_pb(int **a, int **b, int *len_a, int *len_b)
{
    if (*len_a == 0)
        return (0);

    *b = ft_realloc(*b, (*len_b + 1) * sizeof(int));
    if (*b == NULL)
        return (-1);

    (*b)[*len_b] = (*a)[*len_a-1];

	for (int i = 0; i < *len_a - 1; i++)
		(*a)[i] = (*a)[i + 1];

    *a = ft_realloc(*a, (*len_a - 1) * sizeof(int));
    if (*a == NULL && *len_a > 1)
        return (-1);

    (*len_a)--;
    (*len_b)++;

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
    b = malloc(sizeof(int));
    i = 0;

    while (++i < argc)
        a[i - 1] = ft_atol(argv[i]);

    int len_a = argc - 1;
    int len_b = 0;
    ft_pb(&a, &b, &len_a, &len_b);

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
