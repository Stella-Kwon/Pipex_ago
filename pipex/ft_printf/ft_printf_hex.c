/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:46:28 by sukwon            #+#    #+#             */
/*   Updated: 2023/01/10 14:29:51 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_low(unsigned int n)
{
	int	length;

	length = 1;
	if (0 <= n && n < 16)
	{
		if (n < 10)
			put_char('0' + n);
		if (10 <= n && n < 16)
			put_char(('a' - 10) + n);
	}
	if (16 <= n)
	{
		length += put_hex_low(n / 16);
		put_hex_low(n % 16);
	}
	return (length);
}

int	put_hex_up(unsigned int n)
{
	int	length;

	length = 1;
	if (0 <= n && n < 16)
	{
		if (n < 10)
			put_char('0' + n);
		if (10 <= n && n < 16)
			put_char(('A' - 10) + n);
	}
	if (16 <= n)
	{
		length += put_hex_up(n / 16);
		put_hex_up(n % 16);
	}
	return (length);
}
