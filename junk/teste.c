#include "../push_swap.h"

int main(int argc, char **argv) // ./a.out 3 2 1
{
    int *a; // 3 2 1
	int *b; // 0 0 0
    int i; // 0 1 2
	int len_a;
	int len_b;

    if (argc != 6) // 5 < 6
        return (1);

    a = (int*)malloc(sizeof(int) * (argc-1));
    i = 0;
	len_a = argc - 1;
	len_b = 0;

    while (++i < argc)
        a[i - 1] = ft_atol(argv[i]);

    ft_sort5(&a, &b, len_a, len_b);

    printf("stack a: \n");
    for (int j = 0; j < argc - 1; j++)
        printf("%d\n", a[j]);

    printf("\n");
    free(a);
    return (0);
}
