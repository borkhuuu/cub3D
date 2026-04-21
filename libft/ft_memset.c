/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:18:54 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/29 23:21:10 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	if (!s)
		return (NULL);
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <string.h>
int	main(void)
{
	char	str[10] = "abcdefgh";
	char	str2[10] = "abcdefgh";
	int	c = 'z';
	printf("my memset: %s\n", (char*)ft_memset(&str[2], c, 4));
	printf("th memset: %s\n", (char*)memset(&str2[2], c, 4));
	return 0;
}*/
