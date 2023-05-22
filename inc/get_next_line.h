/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:30:00 by mamaral-          #+#    #+#             */
/*   Updated: 2023/05/22 15:00:56 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//create get_next_line.h
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//include libraries
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdio.h>
# include "libft.h"


//define BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

//define functions
char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
#endif
