/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:05:48 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/07 02:59:11 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*big_start(void)
{
	char	*sub;

	sub = malloc(sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

static char	*big_len(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	if (sub == NULL)
		return (NULL);
	while (s[i + start] != 0 && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	i = 0;
	sub = NULL;
	if (ft_strlen(s) < start)
	{
		sub = big_start();
		return (sub);
	}
	else if (ft_strlen(s) <= len)
		sub = big_len(s, start, len);
	else
	{
		sub = malloc(sizeof(char) * len + 1);
		if (sub == NULL)
			return (NULL);
		while (s[i] != 0 && i < len)
		{
			sub[i] = s[i + start];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
/*
#include <string.h>
int	main(void)
{
	char	*str = strdup("0123456789");
//	char s[] = "tripouille";
	char	*test = ft_substr(str, 9, 10);
//	if (strcmp(ft_substr(str, 42, 42000), "") == 0)
//		printf("correct\n");
	printf("%s\n", test);
//	printf("%zu\n", ft_strlen(s));
	//free(test);
	free(test);
	return 0;
}*/
