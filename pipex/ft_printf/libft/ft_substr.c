/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:06:52 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 13:18:00 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_min(size_t len, unsigned int max)
{
	if (len < max)
		return (len);
	else
		return (max);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	min;
	unsigned int	slen;
	unsigned int	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start || len == 0)
		return (ft_strdup(""));
	min = get_min(len, slen - start + 1);
	temp = (char *)malloc(sizeof(char) * min + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < min)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}
