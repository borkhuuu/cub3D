/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:42:40 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:38:02 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../includes/cub3D_bonus.h"

int	check_format(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}

size_t	check_comma(const char *line)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	check_hidden_file(t_map *map, const char *path)
{
	const char	*tmp;

	tmp = ft_strrchr(path, '/');
	if (!tmp && path[0] == '.')
		return (map->err_msg = "Error\nHidden files are not accepted\n", 0);
	else if (!tmp)
		return (1);
	if (*(++tmp) == '.')
		return (map->err_msg = "Error\nHidden files are not accepted\n", 0);
	return (1);
}

int	check_extension(t_map *map, const char *path, const char *ext)
{
	const char	*tmp;

	tmp = ft_strrchr(path, '.');
	if (!tmp)
		return (map->err_msg = "Error\nPath doesnt have extension\n", 0);
	if (ft_strcmp(tmp, ext))
		return (map->err_msg = "Error\nPath has wrong extension\n", 0);
	return (1);
}

bool	check_missing_path(t_map *map)
{
	if (!map->path_no || !map->path_so || !map->path_we || !map->path_ea
		|| !map->path_m || !map->color_f.set || !map->color_c.set)
		return (map->err_msg = "Error\nA path or color is missing/misconfigured"
			" or map is not last\n", true);
	return (false);
}
