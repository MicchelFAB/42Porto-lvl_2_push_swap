/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/20 19:15:06 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_pa(int **a, int **b)
{
	int *ptr;
	size_t i;

	i = 0;
	ptr = malloc(sizeof(int) * (ft_strlen(*a) + 1));
	while (i < ft_strlen(*a))
	{
		ptr[i + 1] = (*a)[i];
		i++;
	}
	ptr[0] = *b[0];
	*a = ptr;
	return (1);
}

// int main (int argc, char **argv)
// {
// 	int *a;
// 	int *b;
// 	int i;

// 	i = 0;
// 	a = malloc(sizeof(int) * (argc - 1));
// 	b = malloc(sizeof(int) * (argc - 1));
// 	while (i < argc - 1)
// 	{
// 		a[i] = ft_atoi(argv[i + 1]);
// 		i++;
// 	}
// 	ft_pa(&a, &b);
// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		printf("%d ", a[i]);
// 		i++;
// 	}
// 	return (0);
// }