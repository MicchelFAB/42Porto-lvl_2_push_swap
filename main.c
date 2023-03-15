#include "push_swap.h"

int main(int argc, char **argv) 
{
    int i;
	int *str;
	
	str = (int*)malloc(sizeof(int) * (argc-1));
	i = 1;
	while(i < argc)
	{
		if (argc < 3)
		{
			printf("Error: No arguments enouth");
			return (0);
		}
		str[i-1] = ft_atoi(argv[i]);
		i++;
	}

	ft_ra(&str);
	ft_sa(&str[0], &str[1]);
	i = 0;
	while(i < argc-1)
	{
		printf("%d ", str[i]);
		i++;
	}
	if (ft_ra(&str) == 1)
		printf("\nra");
	if (ft_sa(&str[0], &str[1]) == 1)
		printf("\nsa");
	free(str);
	return (0);
}
