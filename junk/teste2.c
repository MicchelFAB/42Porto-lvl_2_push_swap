#include "../inc/push_swap.h"

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
			if (is_sorted(a, len_a))
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

// function that put the stack in order and store on the stack index
void	ft_find_order (int *x, int len_x)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len_x)
	{
		j = i + 1;
		while (j < len_x)
		{
			if (x[i] > x[j])
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
			j++;
		}
		i++;
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
	ft_find_order(stsha, len_a);
	// ft_min1(stsha, stshb, len_a, len_b);
	ft_print_stack_all(stsha, stshb, len_a, len_b);
	free (stsha);
	free (stshb);
	return (0);
}

