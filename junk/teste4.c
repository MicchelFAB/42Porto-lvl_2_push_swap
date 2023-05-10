/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:11:17 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/10 08:08:43 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stash	*stash;
	int i;
	
	ft_memset(&stash, 0, sizeof(stash));
	stash = (t_stash *)malloc(sizeof(t_stash) * (argc - 1));
	stash->a = (t_stack *)malloc(sizeof(t_stack) * (argc-1));
	stash->b = (t_stack *)malloc(sizeof(t_stack) * (argc-1));
	if (argc < 2)
	{
		ft_printf("Error: No arguments enouth");
		return (0);
	}
	// stash = (t_stash *)malloc(sizeof(int) * (argc-1));
	i = 0;
	while (++i < argc)
		stash->a->stack[i - 1] = ft_atol(argv[i]);

	stash->a->len = argc - 1;
	stash->b->len = 0;
	i = 0;

	ft_pb(*stash);
	ft_pb(*stash);
	ft_pb(*stash);
		
	ft_printf("\nstack a: \n");
    for (int j = 0; j < stash->a->len; j++)
        ft_printf("%d ", stash->a->stack[j]);

    ft_printf("\nstack b: \n");
    for (int j = 0; j < stash->b->len; j++)
        ft_printf("%d ", stash->b->stack[j]);

    ft_printf("\n");
    free(stash->a->stack);
    free(stash->b->stack);
	return (0);
}
