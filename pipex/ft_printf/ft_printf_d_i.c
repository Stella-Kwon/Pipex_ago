/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:46:24 by sukwon            #+#    #+#             */
/*   Updated: 2023/01/10 14:27:54 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_d_i(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		put_char(45);
		put_char('2');
		length += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		put_char(45);
		length += 1;
		n *= -1;
	}
	length += put_unsigned_int(n);
	return (length);
}
