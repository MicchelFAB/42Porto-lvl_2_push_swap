/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:13:10 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/21 10:16:16 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_pa(int **a, int **b)
{
    int len_a = ft_arrlen(*a);
    int len_b = ft_arrlen(*b);

    if (len_a == 0)
        return (0);

    *b = (int*)realloc(*b, (len_b + 1) * sizeof(int));
    if (*b == NULL)
        return (-1);

    (*b)[len_b] = (*a)[0];

    for (int i = 0; i < len_a - 1; i++)
        (*a)[i] = (*a)[i + 1];
    (*a) = (int*)realloc(*a, (len_a - 1) * sizeof(int));
    if (*a == NULL && len_a > 1)
        return (-1);
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