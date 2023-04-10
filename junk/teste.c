#include "../push_swap.h"

void	ft_push(int **a, int **b, int *len_a, int *len_b)
{
  static int total_alloc_size = 0;
  
  if (*len_a == 0)
    ft_putstr_fd("Error - trying to push from empty stack\n", 2),
	exit(0);
    
  if (total_alloc_size == 0) {
    total_alloc_size = (*len_a + *len_b);
    *a = ft_realloc(*a, sizeof(int) * total_alloc_size);
    *b = ft_realloc(*b, sizeof(int) * total_alloc_size);
  }
  
  if (*len_b == total_alloc_size) {
    total_alloc_size *= 2;
    *b = ft_realloc(*b, sizeof(int) * total_alloc_size);
  }
  
  ft_memmove(*b + 1, *b, sizeof(int) * (*len_b));
  (*b)[0] = (*a)[0];
  *len_b += 1;
  
  if (*len_a > 0) {
    ft_memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
    *len_a -= 1; // decrement len_a after pushing to b
  }
}

void	ft_pb(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(a, b, len_a, len_b);
	ft_putstr_fd("pb\n", 1);
}
void	ft_pa(int **a, int **b, int *len_a, int *len_b)
{
	ft_push(b, a, len_b, len_a);
	ft_putstr_fd("pa\n", 1);
}


void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

void	ft_sort5(int **a, int **b, int len_a, int len_b)
{
	int min_a;
	int max_b;
	int max_a;
	int i;

	i = len_a;
	while (i > 3)
	{
		min_a = ft_min(*a, len_a);
		max_a = ft_max(*a, len_a);
		if ((*a)[0] == max_a)
			ft_pa(a, b, &len_a, &len_b);
		else if ((*a)[len_a - 1] == max_a)
			ft_pb(a, b, &len_a, &len_b);
		else if ((*a)[0] == min_a)
			ft_rra(a, len_a);
		else
			ft_ra(a, len_a);
		i--;
	}
	ft_sort3(a, len_a);
	if (len_b == 2 && (*b)[0] < (*b)[1])
		ft_sb(b);
	while (len_b > 0)
	{
		max_b = ft_max(*b, len_b);
		if ((*b)[0] == max_b)
			ft_pa(a, b, &len_a, &len_b);
		else if ((*b)[len_b - 1] == max_b)
			ft_rrb(b, len_b);
		else if ((*b)[0] < max_b && (*b)[len_b - 1] < max_b)
		{
			ft_pa(a, b, &len_a, &len_b);
			if ((*a)[0] > (*a)[1])
				ft_sa(a);
		}
		else if ((*b)[0] < max_b)
			ft_pa(a, b, &len_a, &len_b);
		else
			ft_rb(b, len_b);
	}
}

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


