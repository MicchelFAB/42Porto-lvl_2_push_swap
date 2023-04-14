# include "../inc/push_swap.h"

void	ft_sort3(int *stack, int len)
{
	if (len == 3)
	{
		if ((stack[1] > stack[2] && stack[0] > stack[1]) \
		|| (stack[1] < stack[2] && stack[0] > stack[2]))
		{
			ft_ra(stack, len);
		}
		else if (stack[1] > stack[2] && stack[0] < stack[1])
		{
			ft_rra(stack, len);
		}
		else if (stack[1] < stack[2] && stack[0] > stack[1])
		{
			ft_sa(stack);
		}
		if (stack[0] > stack[1] || stack[0] > stack[2] \
		|| stack[1] > stack[2])
		{
			ft_sort3(stack, len);
		}
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

	// ft_rotate(stsha, len_a);
	// ft_swap(stsha);
	// ft_reverse_rotate(stsha, len_a);
	//ft_sort3(stsha, len_a);
	
	ft_pb(stsha, stshb, len_a, len_b);
	ft_pb(stsha, stshb, len_a, len_b);
	ft_pa(stsha, stshb, len_a, len_b);

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
