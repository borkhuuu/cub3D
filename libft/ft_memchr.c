/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:35:32 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/07 00:22:54 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;
	void			*ptr;

	ptr = NULL;
	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (ptr);
}
/*
#include <string.h>
int	main(void)
{
	char s[] = {1, 1, 0, 3 ,4 ,5};
	void *q = ft_memchr(s, 0, 3);
	void *b = memchr(s, 0, 3);
	printf("%s\n", (char *)q);
	printf("%s\n", (char *)b);
	return 0;
}*/
