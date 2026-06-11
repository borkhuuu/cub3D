/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodFill_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:28:39 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/08 12:54:59 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libraries/libft/libft.h"
#include "../../includes/map_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include <stddef.h>

void	calculate_max_width(t_map *m, char **copy)
{
	size_t	i;
	size_t	width;

	i = 0;
	width = 0;
	if (!copy)
		return ;
	while (copy[i])
	{
		width = ft_strlen(copy[i]);
		if (width > m->map_max_width)
			m->map_max_width = width;
		i++;
	}
}

void	get_pos(t_map *m)
{
	size_t	y;
	size_t	x;
	char	**map;

	y = 0;
	map = m->map_arr;
	while (map[y] && (!m->player.set || !m->enemy.set))
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == m->player.spawn)
			{
				vector_setter(&m->player.pos, (double)x, (double)y);
				m->player.set = true;
			}
			else if (map[y][x] == 'M')
			{
				vector_setter(&m->enemy.pos, (double)x, (double)y);
				m->enemy.set = false;
			}
			x++;
		}
		y++;
	}
}

int	flood_fill(t_map *m, char **map, int x, int y)
{
	if (y < 0 || y >= (int)m->map_height)
		return (0);
	if (x < 0 || x >= (int)m->strlen_arr[y])
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	if (map[y][x] == m->player.spawn)
		return (m->player_hit = true, 1);
	if (map[y][x] == ' ' || !map[y][x])
		return (0);
	map[y][x] = 'V';
	if (!flood_fill(m, map, x, y + 1))
		return (0);
	if (!flood_fill(m, map, x, y - 1))
		return (0);
	if (!flood_fill(m, map, x + 1, y))
		return (0);
	if (!flood_fill(m, map, x - 1, y))
		return (0);
	return (1);
}

int	check_rem_rooms(t_map *map, char **copy)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == '0')
			{
				if (!flood_fill(map, copy, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	char	**copy;

	if (map->player.count != 1 || map->enemy.count != 1)
		return (map->err_msg = "Error\nPlayer/Enemy count not exactly 1\n", 0);
	if (!init_strlen_arr(map))
		return (map->err_msg = "Error\nAllocating strlen_arr has failed\n", 0);
	copy = ft_copy_arr((const char **)map->map_arr);
	if (!copy)
		return (map->err_msg = "Error\nCopying the map failed\n", 0);
	get_pos(map);
	if (!flood_fill(map, copy, map->enemy.pos.x, map->enemy.pos.y))
		return (map->err_msg = "Error\nFloodfill from enemy pos failed\n",
			free_func(NULL, copy), 0);
	if (!map->player_hit)
		return (map->err_msg = "Error\nEnemy doesn't have access to player\n",
			free_func(NULL, copy), 0);
	if (!check_rem_rooms(map, copy))
		return (map->err_msg = "Error\nFloodfill in independent room failed\n",
			free_func(NULL, copy), 0);
	calculate_max_width(map, copy);
	return (free_func(NULL, copy), 1);
}
