/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:22:05 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 13:17:42 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	temp = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (*(temp + i) == (char)c)
			return (temp + i);
		i--;
	}
	if (*(temp + i) == (char)c)
		return (temp);
	return (NULL);
}
