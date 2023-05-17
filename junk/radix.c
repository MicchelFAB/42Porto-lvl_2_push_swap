/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   radix.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mamaral- <mamaral-@student.42porto.com	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/24 16:49:58 by mamaral-		  #+#	#+#			 */
/*   Updated: 2023/05/08 08:54:23 by mamaral-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stash	stash;
	int	i;

	if (argc < 2)
	{
		ft_printf("Error: No arguments enough\n");
		return (0);
	}
	stash.a.stack = (int *)malloc(sizeof(int) * (argc-1));
	stash.b.stack = (int *)malloc(sizeof(int) * (argc-1));
	i = 0;
	while (++i < argc)
		stash.a.stack[i - 1] = ft_atol(argv[i]);

	stash.a.len = argc - 1;
	stash.b.len = 0;

	ft_index(stash.a);
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
