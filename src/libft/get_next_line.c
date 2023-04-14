/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:38:06 by mamaral-          #+#    #+#             */
/*   Updated: 2023/04/14 11:48:28 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*save_rest(char	*str)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = ft_calloc(sizeof(char), ((ft_strlen(str) - i) + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*ft_get_line(char *save)
{
	char	*dest;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	dest = ft_calloc(sizeof(char), (i + 2));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		dest[i] = save[i];
		i++;
	}
	dest[i] = save[i];
	return (dest);
}

char	*ft_read_line(char *str, char *buffer, ssize_t len_read)
{
	char	*tmp;

	buffer[len_read] = '\0';
	if (str == NULL)
	{
		tmp = ft_strdup(buffer);
		free(str);
		return (tmp);
	}
	else
	{
		tmp = ft_strjoin(str, buffer);
		free(str);
		return (tmp);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		stored;
	static char	*save[FOPEN_MAX];
	char		*line;

	stored = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (!(ft_strchr(buffer, '\n')) && stored != 0)
	{
		stored = read(fd, buffer, BUFFER_SIZE);
		if (stored < 0)
		{
			free (buffer);
			free (save[fd]);
			save[fd] = NULL;
			return (NULL);
		}
		save[fd] = ft_read_line(save[fd], buffer, stored);
	}
	free(buffer);
	line = ft_get_line(save[fd]);
	save[fd] = save_rest(save[fd]);
	return (line);
}

/* 
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}

// create main function
int	main(void)
{
	int		fd;
	char	*str;
	int		i;
	ssize_t	len_read = BUFFER_SIZE;

	i = 1;
	fd = open("tst1.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
	{
		perror("r1");
		exit(1);
	}
	printf("BUFFER SIZE is:%lu\n", len_read);
	while ((str = get_next_line(fd)))
		printf("LINE - %3d || lengh - %3zu: %s", i++, ft_strlen(str), str);
	free(str);
	return (0);
}
 */