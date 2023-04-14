/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:30:00 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/12 12:49:22 by mamaral-         ###   ########.fr       */
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

//define BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

//define functions
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
#endif
