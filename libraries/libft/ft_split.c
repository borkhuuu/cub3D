/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:38:39 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/11 17:11:16 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		res[j] = my_strdup(&s[i], c);
	if (!res[j])
		return (freefunc(res, j), NULL);
	j++;
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
