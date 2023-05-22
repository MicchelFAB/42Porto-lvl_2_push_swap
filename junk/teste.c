/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   teste.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mamaral- <mamaral-@student.42porto.com	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/17 11:54:53 by mamaral-		  #+#	#+#			 */
/*   Updated: 2023/05/17 17:07:53 by mamaral-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack stack)
{
	t_stack	tmp;

	tmp.stack = stack.stack;
	stack.base.i = 0;
	while (stack.base.i < stack.len - 1)
	{
		if (tmp.stack[stack.base.i] > tmp.stack[stack.base.i + 1])
		{
			return (0);
		}
		stack.base.i++;
	}
	return (1);
}


/* void push_swap(t_stash stash)
{
	
} */

int main(int argc, char **argv)
{
	int i;
	
	i = 1;
	while (i < argc)
	{
	printf("%d",ft_check_is_int(argv[i]));
	i++;
	}
	return (0);
}
