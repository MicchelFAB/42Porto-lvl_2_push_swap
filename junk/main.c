#include "../push_swap.h"

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

	ft_sort3(&stsha, len_a);

	printf("-+-+-+-++---+-+-+-+-+-\n");

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
	// 	printf("%d ", stsha[i]);
	// 	i++;
	// }
	printf("\nstack a: \n");
    for (int j = 0; j < len_a; j++)
        printf("%02d ", stsha[j]);

    printf("\nstack b: \n");
    for (int j = 0; j < len_b; j++)
        printf("%02d ", stshb[j]);

    printf("\n");
    free(stsha);
    free(stshb);
    return (0);
}
