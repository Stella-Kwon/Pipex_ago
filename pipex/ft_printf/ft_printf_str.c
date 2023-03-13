/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:47:00 by sukwon            #+#    #+#             */
/*   Updated: 2023/01/10 14:29:12 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	length;

	length = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[length] != '\0')
	{
		write(1, &str[length], 1);
		length++;
	}
	return (length);
}
