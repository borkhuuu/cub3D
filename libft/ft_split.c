/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:38:39 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/06 19:34:36 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	my_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static void	*my_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = NULL;
	if (nmemb == 0 || size == 0)
	{
		res = (void *)malloc(0);
		return (res);
	}
	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
*/
static char	*my_strdup(char const *str, char c)
{
	int		i;
	int		len;
	char	*dup;

	len = 0;
	i = 0;
	while (str[len] != 0 && str[len] != c)
		len++;
	dup = ft_calloc(len + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[i] != 0 && str[i] != c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	counter(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i] == c)
		i = i + 1;
	if (s[i] != '\0')
		counter = 1;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
		{
			counter++;
		}
		i = i + 1;
	}
	return (counter);
}

static void	freefunc(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
}

static char	**helper(char **res, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
		res[j++] = my_strdup(&s[i], c);
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
		{
			res[j] = my_strdup(&s[i + 1], c);
			if (res[j] == NULL)
				return (freefunc(res, j), NULL);
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	res = NULL;
	if (s == NULL)
		return (NULL);
	res = (char **)ft_calloc(counter(s, c) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	if (s[i] == '\0')
		return (res);
	res = helper(res, s, c);
	if (res == NULL)
		return (NULL);
	return (res);
}
/*
#include <string.h>
int	main(void)
{
	char	**s1;
	int	i = 0;
	//char	*l = NULL;
	if (!(s1 = ft_split("", ' ')))
		printf("fuck");
	else
		while (s1[i] != NULL)
		{
			printf("%s", s1[i]);
			printf("\n");
			i++;
		}
	//printf("%s\n", l);
	return 0;
}*/
