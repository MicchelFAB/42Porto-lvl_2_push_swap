#include "../push_swap.h"

void	ft_sort5(int **a, int **b, int len_a, int len_b)
{
	int min_a;
	int min_b;
	
	min_a = ft_min(*a, len_a, 1);
	min_b = ft_min(*a, len_a, 2);

	while (len_a > 3)
	{
		if ((*a)[0] == min_a)
		{
			ft_pb(a, b, &len_a, &len_b);
			if ((*a)[1] == min_b)
				ft_pb(a, b, &len_a, &len_b);
				ft_sort3(a, len_a);
			else 
				ft_sort3(a, len_a - 1);
		}
		len_a--;
	}
}
int main(int argc, char **argv) 
{
	int *stsha;
	int *stshb;
    int len_a;
	int len_b;

	int i;
	
	if (argc < 2)
	{
		ft_printf("Error: No arguments enouth");
		return (0);
	}
	stsha = (int*)malloc(sizeof(int) * (argc-1));
	stshb = (int*)malloc(sizeof(int) * (argc-1));
	i = 0;
	
	while (++i < argc)
		stsha[i - 1] = ft_atol(argv[i]);

	len_a = argc - 1;
	len_b = 0;
	i = 0;

	// ft_sort3(&stsha, len_a);
	ft_sort5(&stsha, &stshb, len_a, len_b);
	
	// ft_pb(&stsha, &stshb, &len_a, &len_b);
	// ft_pb(&stsha, &stshb, &len_a, &len_b);
	// ft_pa(&stsha, &stshb, &len_a, &len_b);
		
	// ft_sa(&stsha);
	// ft_ra(&stsha, len_a);
	// ft_rrr(&stsha, &stshb, len_a, len_b);
	// ft_sb(&stshb);
	// ft_pb(&stsha, &stshb, &len_a, &len_b);
	// ft_rb(&stshb);
	//ft_rrr(&stsha, &stshb);
	// i = 0;
	// while(i < argc-1)
	// {
	// 	ft_printf("%d ", stsha[i]);
	// 	i++;
	// }
	ft_printf("\nstack a: \n");
    for (int j = 0; j < len_a; j++)
        ft_printf("%02d ", stsha[j]);

    ft_printf("\nstack b: \n");
    for (int j = 0; j < len_b; j++)
        ft_printf("%02d ", stshb[j]);

    ft_printf("\n");
    free(stsha);
    free(stshb);
    return (0);
}


