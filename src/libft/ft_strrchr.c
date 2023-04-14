/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:03 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 11:48:06 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;

	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (ptr);
}
