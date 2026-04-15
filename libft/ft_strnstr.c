/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:46:11 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/06 20:11:13 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*ptr;

	ptr = NULL;
	i = 0;
	j = 0;
	l = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (little[l] != '\0')
		l++;
	while (i + l <= len && big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return (ptr = (char *)&big[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (ptr);
}
/*
#include <bsd/string.h>
#include <string.h>
int	main(int argc, const char **argv)
{
	(void)argc;
	printf("ft_strnstr: %s\n", ft_strnstr(argv[1], argv[2], 3));
	printf("strnstr: %s\n", strnstr(argv[1], argv[2], 3));
	return 0;
}*/
