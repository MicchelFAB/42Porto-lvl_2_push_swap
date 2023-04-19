#include "../inc/push_swap.h"

int	find_limit(const int len)
{
	int	limit;
	int size;

	limit = 0;
	size = len;
	while ((size / 2) != 0)
	{
		limit++;
		size = size / 2;
	}
	return (limit);
}
	

void ft_min1(int *a, int *b, int len_a, int len_b)
{
	int	min_x;
	int	min_z;
	int	i;

	i = len_a;
	min_x = ft_min_if(a, len_a, 1);
	min_z = ft_min_if(a, len_a, 2);
	while (i > 3)
	{
		if (a[0] == min_x)
		{
			ft_pb(a, b, &len_a, &len_b);
			// ft_print_stack_all(a, b, len_a, len_b);
			if (a[1] == min_z)
			{
				ft_sa(a);
				// ft_print_stack_all(a, b, len_a, len_b);
			}
			else if (a[4] == min_z)
			{
				ft_rra(a, len_a);
				// ft_print_stack_all(a, b, len_a, len_b);
			}
			else 
			{
				ft_ra(a, len_a);
				ft_ra(a, len_a);
				// ft_print_stack_all(a, b, len_a, len_b);
			}
			if (ft_is_sorted(a, len_a))
			{
				ft_print_stack_all(a, b, len_a, len_b);
			}
			else
			{
				ft_pb(a, b, &len_a, &len_b);
				// ft_print_stack_all(a, b, len_a, len_b);
			}
		}
		i--;
	}
}

void	long_push_swap(int *a, int *b, int len_a, int len_b)
{
	int	i;
	int j;
	int limit;
	int min;

	limit = find_limit(len_a);
	min = ft_min_if(a, len_a, 1);
	i = 0;
	j = 1;
	while (limit >= 0)
	{
		while (i < len_a)
		{
			if (a[limit] == min)
			{
				ft_pb(a, b, &len_a, &len_b);
				min = ft_min_if(a, len_a, j);
				j++;
			}
			else if (a[limit] < limit + min)
				ft_ra(a, len_a);
			else if (a[limit] < limit + min)
				ft_rra(a, len_a);
			i++;
		}
		while (len_b)
			ft_pa(a, b, &len_a, &len_b);
		limit--;
		i = 0;
	}
}

int main(int argc, char **argv) 
{
	int *stsha;
	int *stshb;
	int len_a;
	int len_b;
	int i;

	i = 0;
	len_a = argc - 1;
	len_b = 0;
	stsha = (int *)malloc(sizeof(int) * len_a);
	stshb = (int *)malloc(sizeof(int) * len_b);
	while (i < len_a)
	{
		stsha[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	
	long_push_swap(stsha, stshb, len_a, len_b);
	printf("\nstack a: \n");
    for (int j = 0; j < len_a; j++)
        printf("%d ", stsha[j]);

    printf("\nstack b: \n");
    for (int j = 0; j < len_b; j++)
        printf("%d ", stshb[j]);

    printf("\n");

	free (stsha);
	free (stshb);
	return (0);
}

