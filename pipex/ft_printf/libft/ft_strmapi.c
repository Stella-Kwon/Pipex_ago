/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:11:04 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 13:17:22 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			n;
	unsigned int	i;
	char			*temp;

	if (!s || !f)
		return (NULL);
	n = ft_strlen(s);
	i = 0;
	temp = (char *)malloc(n + 1);
	if (!temp)
		return (NULL);
	while (i < n)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
