/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:11:17 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/08 10:13:53 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stsha;
	int	*stshb;
	int	len_a;
	int	len_b;
	int	i;

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
	for(int j = 0; j < len_a; j++)
		{printf("%d \n", ft_min_if(stsha, len_a, j));}
	for (int i = 0; i < len_a; ++i)
	{
		printf("\n%d", ft_find_min_pos_if(stsha, len_a, i));
	}
	
// 	printf("\nstack a: \n");
//     for (int j = 0; j < len_a; j++)
//         printf("%d ", stsha[j]);

//     printf("\nstack b: \n");
//     for (int j = 0; j < len_b; j++)
//         printf("%d ", stshb[j]);

//     printf("\n");

// 	free (stsha);
// 	free (stshb);
// 	return (0);
}