/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:35 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/07 00:34:57 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*fk;
	unsigned char	*this;

	i = 0;
	fk = (unsigned char *)s1;
	this = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (fk[i] != this[i])
			return (fk[i] - this[i]);
		i++;
	}
	return (fk[i] - this[i]);
}
/*
#include <string.h>
int	main(void)
{
	const void *str1 = strdup("abc");
	const void *str2 = strdup("abc");
	printf("%i\n", ft_memcmp(str1, str2, 1234567890000));
	printf("%i\n", memcmp(str1, str2, 1234567890000));
	return 0;
}*/
