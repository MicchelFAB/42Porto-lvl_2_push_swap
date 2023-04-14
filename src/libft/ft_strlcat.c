/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:31:19 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 11:47:46 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	d = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && d + 1 < size)
	{
		dst[d] = src[i];
		d++;
		i++;
	}
	dst[d] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
