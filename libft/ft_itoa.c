/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:08:20 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/08 14:24:52 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str, int sign)
{
	size_t	i;
	int		j;
	char	*dup;

	dup = NULL;
	i = 0;
	j = ft_strlen(str);
	dup = ft_calloc(j + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	if (sign == 1)
		dup[i++] = '-';
	while (i < ft_strlen(str))
	{
		dup[i] = str[j - 1];
		j--;
		i++;
	}
	free(str);
	return (dup);
}

static char	*whynot(long l, char *res, int i)
{
	while (l > 0)
	{
		res[i++] = (l % 10) + '0';
		l = l / 10;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		sign;
	long	l;

	i = 0;
	sign = 0;
	l = (long)n;
	res = ft_calloc(14, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (l < 0)
	{
		l = l * -1;
		res[i++] = '-';
		sign = 1;
	}
	if (l == 0)
	{
		res[i] = '0';
		return (ft_strrev(res, i));
	}
	res = whynot(l, res, i);
	res = ft_strrev(res, sign);
	return (res);
}
/*
#include <limits.h>
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	return 0;
}*/
