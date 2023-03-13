/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:47:04 by sukwon            #+#    #+#             */
/*   Updated: 2023/01/10 14:28:09 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned_int(unsigned int n)
{
	int	length;

	length = 1;
	if (0 <= n && n < 10)
		put_char(48 + n);
	if (n >= 10)
	{
		length += put_unsigned_int(n / 10);
		put_unsigned_int(n % 10);
	}
	return (length);
}
