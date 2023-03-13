/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:09:03 by sukwon            #+#    #+#             */
/*   Updated: 2022/11/16 13:11:38 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_length(int n)
{
	unsigned int	nbr;
	unsigned int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count = 1;
		n *= -1;
	}
	nbr = n;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static int	nbr_sign(int n)
{
	if (n < 0)
		return ((unsigned int)(n * -1));
	else
		return ((unsigned int)n);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	len;
	char			*str;
	int				sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = find_length(n);
	nbr = nbr_sign(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	while (len > 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	else
		str[0] = (nbr % 10) + '0';
	return ((char *)str);
}
