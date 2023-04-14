/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:18:58 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 11:47:35 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!src)
		return (NULL);
	while (*s)
		src[i++] = *s++;
	src[i] = '\0';
	return (src);
}
