/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:27:32 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/07 04:39:47 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
int	main(void)
{
	char	str[] = "ABCDEFGH";
	char	str2[] = "ABCD";
	printf("%s\n", (char*)memcpy(&str[3], &str2[4], 4));
	printf("%s\n", (char*)ft_memcpy(&str[3], &str2[4], 4));
	return 0;
}*/
