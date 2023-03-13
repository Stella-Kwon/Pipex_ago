/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:09:38 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/18 14:02:12 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_words(char const *s, char c)

{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	split_words_pointers(char **s, size_t len, char c)

{
	size_t	i;

	i = 0;
	*s += len;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[i])
	{
		if ((*s)[i] == c)
			break ;
		i++;
	}
	return (i);
}

static char	**allfree(char **result)

{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*str;
	char	**result;
	size_t	count;
	size_t	len;

	if (!s)
		return (NULL);
	count = split_words(s, c);
	result = ft_calloc(sizeof(char *), count + 1);
	if (!result)
		return (NULL);
	i = 0;
	str = (char *)s;
	len = 0;
	while (i < count)
	{
		len = split_words_pointers(&str, len, c);
		result[i] = (char *)malloc(sizeof(char) * len + 1);
		if (!result[i])
			return (allfree(result));
		ft_strlcpy(result[i], str, len + 1);
		i++;
	}
	return (result);
}
