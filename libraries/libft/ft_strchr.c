/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:51:45 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/07 04:33:23 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = NULL;
	if ((unsigned char)c == 0)
	{
		return (ptr = (void *)&s[ft_strlen(s)]);
	}
	while (s[i - j] != 0)
	{
		if (s[i] == (unsigned char)c)
		{
			ptr = (char *)&s[i];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
/*
#include <string.h>
int	main(void)
{
	const char	*str = "";
	int	c = '\0';
	char	*ptr = ft_strchr(str, c);
	printf("%s\n", ptr);
	printf("%s\n", strchr(str, c));
	return 0;
}*/
