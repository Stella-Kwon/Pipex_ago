/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:44:59 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 13:16:45 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	n;

	if (!s || !f)
		return ;
	i = 0;
	n = ft_strlen(s);
	while (n--)
	{
		(f)(i, s);
		i++;
		s++;
	}
	*s = '\0';
}
