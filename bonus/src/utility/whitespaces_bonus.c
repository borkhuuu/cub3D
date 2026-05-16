/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:50:09 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/14 18:42:33 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <stdint.h>
#include <stdbool.h>

size_t	first_char(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && ft_iswspace(s[i]))
		i++;
	return (i);
}

size_t	last_char(const char *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (i > 0)
		i--;
	n = i;
	while (i >= 0 && ft_iswspace(s[i]))
	{
		n = i;
		i--;
		if (i == SIZE_MAX)
			break ;
	}
	return (n);
}

char	**trim_ws_loop(char **arr)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		tmp = ft_strtrim(arr[i], " \t\n\v\f\r");
		if (!tmp)
			return (NULL);
		free(arr[i]);
		arr[i] = tmp;
		i++;
	}
	return (arr);
}

void	trim_ws_back(char *s)
{
	size_t	i;
	size_t	last;

	i = 0;
	if (!s)
		return ;
	last = last_char(s);
	ft_memset(&s[last], 0, 1);
}
