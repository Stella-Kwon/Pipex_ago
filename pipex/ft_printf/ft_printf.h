/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:48:57 by sukwon            #+#    #+#             */
/*   Updated: 2023/01/10 14:30:55 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	put_hex_up(unsigned int n);
int	put_hex_low(unsigned int n);
int	put_d_i(int n);
int	put_unsigned_int(unsigned int n);
int	put_str(char *str);
int	put_ptr(void *n);
int	put_char(int c);

#endif
