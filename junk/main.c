#include "../push_swap.h"

/* int main(int argc, char **argv) 
{
    int i;
	int *stsha;
	int *stshb;
	
	if (argc < 2)
	{
		printf("Error: No arguments enouth");
		return (0);
	}
	stsha = (int*)malloc(sizeof(int) * (argc-1));
	stshb = (int*)malloc(sizeof(int) * (argc-1));
	i = 1;
	while(i < argc)
	{
		stsha[i-1] = ft_atoi(argv[i]);
		i++;
	}


	// ft_ra(&stsha);
	// ft_rra(&stsha);
	// ft_sa(&stsha[0], &stsha[1]);
	ft_pa(&stsha, &stshb[0]);
	i = 0;
	while(i < argc-1)
	{
		printf("%d ", stsha[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while(i < argc-1)
	{
		printf("%d ", stshb[i]);
		i++;
	}
	printf("\n");
	// if (ft_ra(&stsha) == 1)
	// 	printf("ra\n");
	// if (ft_sa(&stsha[0], &stsha[1]) == 1)
	// 	printf("sa\n");
	// if (ft_rra(&stsha) == 1)
	// 	printf("rra\n");
	// if (ft_pa(&stsha, stshb[0]) == 1)
	// 	printf("pa\n");
	free(stsha);
	return (0);
}

 */

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
	for (int i = 0; i < 3; i++)
	{
		ft_pa(&a, &b, &len_a, &len_b);
	}
	/* for (int i = 0; i < 6; i++)
	{
		ft_pa(&b, &a, &len_b, &len_a);
	} */
    printf("stack a: \n");
    for (int j = 0; j < len_a; j++)
        printf("%d\n", a[j]);

    printf("\nstack b: \n");
    for (int j = 0; j < len_b; j++)
        printf("%d\n", b[j]);

    printf("\n");
    free(a);
    free(b);
    return (0);
}

