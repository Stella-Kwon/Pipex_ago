/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:29:14 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 14:41:53 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_str(char *str, char *substr)
{
	while (*substr)
	{
		if (*str != *substr)
			return (0);
		str++;
		substr++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	haystack_len = ft_strlen(haystack);
	if (len != 0 || haystack_len != 0)
	{
		i = 0;
		while (i < haystack_len && i <= (len - ft_strlen(needle)))
		{
			if (find_str((char *)haystack + i, (char *)needle))
				return ((char *)haystack + i);
			i++;
		}
	}		
	return (NULL);
}
