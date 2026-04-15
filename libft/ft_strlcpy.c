/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:33:27 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/29 23:33:28 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	i = 0;
	while (src[src_len] != 0)
		src_len++;
	if (size < 1)
		return (src_len);
	while (src[i] != 0 && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <string.h>
int	main(void)
{
	char	str[] = "abc";
	char	dest[10];
	size_t	n = 2;
	printf("my: %zu\n", ft_strlcpy(dest, str, 2));
	printf("th: %zu\n", strlcpy(dest, str, 2));
	return 0;
}*/
