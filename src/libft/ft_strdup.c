/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:18:58 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/24 20:30:45 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!src)
		return (NULL);
	while (*s)
		src[i++] = *s++;
	return (src);
}
