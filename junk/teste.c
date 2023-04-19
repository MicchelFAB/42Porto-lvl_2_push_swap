#include "../inc/push_swap.h"

void	ft_sort5(int *a, int *b, int len_a, int len_b)

{
	int	min_x;
	int	min_z;
	int	i;

	i = len_a;
	while (i > 3)
	{
		min_x = ft_min_if(a, len_a, 1);
		min_z = ft_min_if(a, len_a, 2);
		if (ft_is_sorted(a, len_a))
			break ;
		else if (a[0] == min_x)
		{
			ft_pb(a, b, &len_a, &len_b);
			if (a[0] > a[1] && a[1] == min_z)
				ft_sa(a);
		}
		else if (a[4] == min_x)
		{
			ft_rra(a, len_a);
		}
		// else if (a[0] == min_z)
		// {
			// ft_pb(a, b, &len_a, &len_b);
		// }
		i--;
		if (ft_is_sorted(a, len_a))
			ft_print_stack_all(a, b, len_a, len_b);
	}
	ft_sort3(a, len_a);
	if (len_b == 2 && b[0] < b[1])
		ft_sb(b);
	while (len_b > 0)
	{
		min_z = ft_max(b, len_b);
		if (b[0] == min_z)
			ft_pa(a, b, &len_a, &len_b);
		else if (b[len_b - 1] == min_z)
			ft_rrb(b, len_b);
		else if (b[0] < min_z && b[len_b - 1] < min_z)
		{
			ft_pa(a, b, &len_a, &len_b);
			if (a[0] > a[1])
				ft_sa(a);
		}
		else if (b[0] < min_z)
			ft_pa(a, b, &len_a, &len_b);
		else
			ft_rb(b, len_b);
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
		printf("Error: No arguments enouth");
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
	ft_sort5(stsha, stshb, len_a, len_b);
	
	// ft_pb(&stsha, &stshb, &len_a, &len_b);
	// ft_pb(&stsha, &stshb, &len_a, &len_b);
	// ft_pa(&stsha, &stshb, &len_a, &len_b);
		
	// ft_sa(&stsha);
	// ft_ra(&stsha, *len_a);
	// ft_rrr(&stsha, &stshb, *len_a, *len_b);
	// ft_sb(&stshb);
	// ft_pb(&stsha, &stshb, len_a, len_b);
	// ft_rb(&stshb);
	//ft_rrr(&stsha, &stshb);
	// i = 0;
	// while(i < argc-1)
	// {
	// 	printf("%d ", stsha[i]);
	// 	i++;
	// }
	printf("\nstack a: \n");
    for (int j = 0; j < len_a; j++)
        printf("%d ", stsha[j]);

    printf("\nstack b: \n");
    for (int j = 0; j < len_b; j++)
        printf("%d ", stshb[j]);

    printf("\n");
    free(stsha);
    free(stshb);
    return (0);
}


