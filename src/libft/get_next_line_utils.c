/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:29:44 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 15:01:41 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

//create ft_calloc function
void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void			*p;
	unsigned char	*s;
	size_t			len;

	len = nmemb * size;
	p = (void *)malloc(nmemb * size);
	if (p == NULL)
		return (p);
	s = p;
	while (len--)
		*(s++) = 0;
	return (p);
}
