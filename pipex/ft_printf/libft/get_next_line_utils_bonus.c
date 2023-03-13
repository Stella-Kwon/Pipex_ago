/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:00:13 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/13 13:30:49 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*gnl_ft_strjoin(char *backup, char *buff)
{
	char			*temp;
	unsigned int	i;
	unsigned int	j;

	if (!backup || !buff)
		return (NULL);
	i = gnl_ft_strlen(backup);
	j = gnl_ft_strlen(buff);
	temp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!temp)
		return (NULL);
	i = -1;
	j = -1;
	while (backup[++i])
		temp[i] = backup[i];
	while (buff[++j])
		temp[i++] = buff[j];
	temp[i] = '\0';
	free(backup);
	backup = NULL;
	return (temp);
}

char	*gnl_ft_strchr(char *str, int character)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (character == '\0')
		return (&str[gnl_ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)character)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
