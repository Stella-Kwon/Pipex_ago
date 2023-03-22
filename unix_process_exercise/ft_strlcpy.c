/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:21:58 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/19 15:45:02 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	//size_t x;
	
	//x = ft_strlen(src);
	i = 0;
	if(!dst || !src)
		return 0;
	// if (dstsize == 0)
	// 	return (ft_strlen(src)); no really need because of i < (dstsize - 1)
	// while (i < x && i < (dstsize -1))
	// {
	// 	dst[i] = src[i];
	// 	i++;
	// }
	// if (dstsize > 0)
	// 	dst[i] = '\0';
	while (*(src + i) != '\0' && i < (dstsize - 1))
	{
		*dst= *(src + i);
		dst++;
		i++;
	}
	*dst = '\0';
	return (ft_strlen(src));
}

int main()
{
	typedef struct N_d
	{
		char *dst;
		char *src;
	} N_M;
	
	N_M *str;
	str = (N_M*)malloc(sizeof(N_M)); 
	str->dst = malloc(6);
	str->src = "hello";
	//printf("%s, %s\n", str->dst, str->src);
	//free(str->dst);
	//char *dst = "HELLO";********//bus error because it is string literal and it is only read-only section of memeory, cannot write
	/// char *dst = malloc(6);
	/// dst = "HELLO"; **************//bus error same reason
	// const char *src = "hello";
	size_t c = 6;
	printf("%zu", ft_strlcpy(str->dst, str->src, c));
	
	// printf("%zu, %zu\n", &str->dst, &str->src);
	printf("%s, %s\n", str->dst, str->src);
	// printf("%zu, %zu\n", dst, src);
	free(str->dst);
	free(str);
	return 0;
}