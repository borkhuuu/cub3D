/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:54:38 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/14 18:40:39 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../includes/cub3D_bonus.h"
#include <errno.h>
#include <fcntl.h>

int	validate_line(const char *s)
{
	size_t	first;

	if (!s)
		return (0);
	first = first_char(s);
	if (!s[first] || s[first] == '\n')
		return (0);
	return (1);
}

int	validate_path(t_map *map, char *path, char *ext)
{
	int		fd;

	if (!path)
		return (map->err_msg = "Error\nPath is non existent\n", 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\n", 6), strerror_wrapper(errno), 0);
	close(fd);
	if (!check_hidden_file(map, path))
		return (0);
	if (!check_extension(map, path, ext))
		return (0);
	return (1);
}

int	handle_path(t_map *map, char **map_path, char *path, char type)
{
	if (!validate_path(map, path, ".xpm"))
		return (0);
	if (*map_path)
	{
		if (type == 'N')
			map->err_msg = "Error\nDuplicate NO texture path\n";
		else if (type == 'S')
			map->err_msg = "Error\nDuplicate SO texture path\n";
		else if (type == 'W')
			map->err_msg = "Error\nDuplicate WE texture path\n";
		else if (type == 'E')
			map->err_msg = "Error\nDuplicate EA texture path\n";
		else if (type == 'M')
			map->err_msg = "Error\nDuplicate M texture path\n";
		return (0);
	}
	*map_path = ft_strdup(path);
	if (!(*map_path))
		return (map->err_msg = "Error\nft_strdup failed in handle_path\n", 0);
	return (1);
}
