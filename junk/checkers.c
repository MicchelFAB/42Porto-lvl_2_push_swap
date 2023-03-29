#include "../push_swap.h"

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

int main(int argc, char **argv)
{
    int i = 1;
    int *a;

    a = (int*)malloc(sizeof(int) * (argc-1));
    while (i < argc)
    {
        if (ft_check_int(argv[i]) == 1)
        {
            printf("Error: Argument %d is not an integer\n", i);
            free(a);
            return (1);
        }
        a[i-1] = ft_atoi(argv[i]);
        if (ft_check_double(argc, argv) == 1)
        {
            printf("Error: Duplicate integer found\n");
            free(a);
            return (0);
        }
        i++;
    }

    if (!ft_check_stack(a, argc - 1))
    {
        printf("Error: Argument out of int range\n");
        free(a);
        return (1);
    }

    printf("Input stack:\n");
    i = 0;
    while (i < argc - 1)
    {
        printf("%d ", a[i]);
        i++;
    }
    
    free(a);
    return (0);
}
