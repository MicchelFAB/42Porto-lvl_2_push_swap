#include <stdio.h>
#include <stdlib.h>

void ft_print_stack(int *a, int len_a)
{
    int i;

    for (i = 0; i < len_a; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int *a;
    int i;
    int len_a = argc - 1;

    a = (int *)malloc(sizeof(int) * len_a);
    for (i = 1; i < argc; i++)
    {
        a[i - 1] = atoi(argv[i]);
    }
    
    free(a);

    return 0;
}
