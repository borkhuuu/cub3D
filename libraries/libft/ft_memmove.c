/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:30:11 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/05 13:53:49 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/*
#include <string.h>
int	main(void)
{
	char	str[] = "ABCDEFGH";
	char	str2[] = "ABCD";
	char	test[] = "ABCDEFGH";
	char	test2[] = "ABCD";
	printf("%s\n", (char*)ft_memmove(&str[3], &str[2], 4));
	printf("%s\n", (char*)memmove(&test[3], &test[2], 4));
	printf("%s\n", (char*)memmove(&test[3], &test[4], 4));
	printf("%s\n", (char*)ft_memmove(&str[3], &str[4], 4));

	return 0;
}*/
