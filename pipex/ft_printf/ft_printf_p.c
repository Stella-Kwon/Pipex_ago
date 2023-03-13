/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:46:56 by sukwon            #+#    #+#             */
/*   Updated: 2023/01/10 13:27:54 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex_ptr(unsigned long long n)
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
		length += put_hex_ptr(n / 16);
		put_hex_ptr(n % 16);
	}
	return (length);
}

int	put_ptr(void *n)
{
	int	length;

	put_char('0');
	put_char('x');
	length = 2;
	length += put_hex_ptr((unsigned long long)n);
	return (length);
}
