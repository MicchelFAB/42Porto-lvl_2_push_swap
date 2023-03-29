/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:48:30 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/29 14:21:58 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_int(const char *arg) // check if the string is an integer
{
    size_t len = ft_strlen(arg);
    int i = 0;

    if (len == 0)
        return (1);
    if (arg[i] == '-' || arg[i] == '+') // check if the string initial character is a sign
    {
        if (len == 1) // if the string is only a sign, return 1
            return (1);
        i++;
    }
    while (arg[i] != '\0') // iterate through the string until the end
    {
        if (!ft_isdigit(arg[i])) // check if the character is a digit and return 1 if it isn't
            return (1);
        i++;
    }
    return (0);
}
