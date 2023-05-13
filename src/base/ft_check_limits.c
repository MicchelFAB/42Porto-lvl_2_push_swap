/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_check_limits.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mamaral- <mamaral-@student.42porto.com	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/19 10:09:45 by mamaral-		  #+#	#+#			 */
/*   Updated: 2023/05/10 15:38:34 by mamaral-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_integer_limits(const char *arg)
{
	long long	num;

	num = ft_atol(arg);
	if (num > 2147483647 || num < -2147483648)
	{
		ft_exit_error();
		return (0);
	}
	return (1);
}

int	ft_check_stack(const t_stack stack)
{
	stack.base.i = 0;
	while (stack.base.i < stack.len)
	{
		if (stack.stack[stack.base.i] > 2147483647 \
		|| stack.stack[stack.base.i] < -2147483648)
		{
			ft_exit_error();
			return (0);
		}
		stack.base.i++;
	}
	return (1);
}
