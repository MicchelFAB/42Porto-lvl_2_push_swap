#include "push_swap.h"

int main(int argc, char **argv) 
{
    int i;
	int *stsha;
	int *stshb;
	
	stsha = (int*)malloc(sizeof(int) * (argc-1));
	stshb = (int*)malloc(sizeof(int) * (argc-1));
	i = 1;
	while(i < argc)
	{
		if (argc < 3)
		{
			printf("Error: No arguments enouth");
			return (0);
		}
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
