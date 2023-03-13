/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:46:28 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 13:16:26 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{	
	if (255 < character)
			character = character - 256;
	while (*str != character)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}
