/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:12:17 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/13 13:31:41 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*all_free(char *backup)
{
	if (backup != NULL)
	{
		free(backup);
		backup = NULL;
	}
	return (NULL);
}

static char	*store_line(char *backup, int fd)
{
	int		read_size;
	char	*buffer;

	read_size = 1;
	while (read_size != 0 && !gnl_ft_strchr(backup, '\n'))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			all_free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		backup = gnl_ft_strjoin(backup, buffer);
		all_free(buffer);
	}
	return (backup);
}

static char	*seperate_line(char *backup)
{
	char	*result;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * i + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		result[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		result[i] = backup[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*store_rest(char *backup)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		all_free(backup);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * gnl_ft_strlen(backup) - i + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		rest[j++] = backup[i++];
	rest[j] = '\0';
	all_free(backup);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (read(fd, 0, 0) < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup == NULL)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	backup = store_line(backup, fd);
	if (!backup)
		return(0);
	line = seperate_line(backup);
	backup = store_rest(backup);
	if (!backup)
		return(0);
	return (line);
}
