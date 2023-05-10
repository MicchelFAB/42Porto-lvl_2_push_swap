/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:50:46 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/09 18:12:07 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stash	stash;
	int i;
	
	if (argc < 2)
	{
		ft_printf("Error: No arguments enouth");
		return (0);
	}
	// stash = (t_stash *)malloc(sizeof(int) * (argc-1));
	stash.a.stack = (int *)malloc(sizeof(int) * (argc-1));
	stash.b.stack = (int *)malloc(sizeof(int) * (argc-1));
	i = 0;
	while (++i < argc)
		stash.a.stack[i - 1] = ft_atol(argv[i]);

	stash.a.len = argc - 1;
	stash.b.len = 0;
	i = 0;

	ft_sort3(stash.a.stack, stash.a.len);
	// ft_sort5(&stash.a.stack, &stash.b.stack, stash.a.len, stash.b.len);
	
	// ft_pb(&stash.a.stack, &stash.b.stack, &stash.a.len, &stash.b.len);
	// ft_pb(&stash.a.stack, &stash.b.stack, &stash.a.len, &stash.b.len);
	// ft_pa(&stash.a.stack, &stash.b.stack, &stash.a.len, &stash.b.len);
		
	// ft_sa(&stash.a.stack);
	// ft_ra(&stash.a.stack, stash.a.len);
	// ft_rrr(&stash.a.stack, &stash.b.stack, stash.a.len, stash.b.len);
	// ft_sb(&stash.b.stack);
	// ft_pb(&stash.a.stack, &stash.b.stack, &stash.a.len, &stash.b.len);
	// ft_rb(&stash.b.stack);
	//ft_rrr(&stash.a.stack, &stash.b.stack);
	// i = 0;
	// while(i < argc-1)
	// {
	// 	ft_printf("%d ", stash.a.stack[i]);
	// 	i++;
	// }
	ft_printf("\nstack a: \n");
    for (int j = 0; j < stash.a.len; j++)
        ft_printf("%d ", stash.a.stack[j]);

    ft_printf("\nstack b: \n");
    for (int j = 0; j < stash.b.len; j++)
        ft_printf("%d ", stash.b.stack[j]);

    ft_printf("\n");
    free(stash.a.stack);
    free(stash.b.stack);
	return (0);
}
