/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:59:32 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/14 18:09:00 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libraries/libft/libft.h"
#include "../../includes/cub3D_bonus.h"
#include <stdbool.h>
#include <string.h>

void	strerror_wrapper(const int errnum)
{
	char	*err;

	err = strerror(errnum);
	write(2, err, ft_strlen(err));
}

bool	is_valid(const char c)
{
	if (!ft_iswspace(c) && c != '0' && c != '1' && c != 'M'
		&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
		return (false);
	return (true);
}

bool	is_player(const char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (true);
	return (false);
}

bool	is_enemy(const char c)
{
	if (c == 'M')
		return (true);
	return (false);
}

bool	is_path(const char *s)
{
	if (!ft_strcmp(s, "NO") || !ft_strcmp(s, "SO")
		|| !ft_strcmp(s, "WE") || !ft_strcmp(s, "EA")
		|| !ft_strcmp(s, "M")
		|| !ft_strcmp(s, "F") || !ft_strcmp(s, "C"))
		return (true);
	return (false);
}
