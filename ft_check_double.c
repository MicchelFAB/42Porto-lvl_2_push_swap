/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:24:51 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/29 12:25:07 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_check_double(int argc, char **argv) // check if there are any duplicate integers in the stack
{
    int i = 1;
    while (i < argc)
    {
        int num1 = ft_atoi(argv[i]); // convert the string to an integer
        int j = i + 1;
        while (j < argc)
        {
            int num2 = ft_atoi(argv[j]); // convert the string to an integer
            if (num1 == num2) // check if the integers are the same
            {
                printf("Duplicate found: %d at indices %d and %d\n", num1, i, j);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}
