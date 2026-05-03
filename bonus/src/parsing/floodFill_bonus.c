#include "../../../libraries/libft/libft.h"
#include "../../includes/map_bonus.h"

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = ft_calloc(map->map_height + 1, sizeof(char *));
	if (!copy)
		return (map->err_msg = "Error\nAllocation of copy of map failed", NULL);
	while (map->map_arr && map->map_arr[i])
	{
		copy[i] = ft_strdup(map->map_arr[i]);
		if (!copy[i])
			return (map->err_msg = "Error\nft_strdup in copy_map failed", free_func(NULL, copy), NULL);
		i++;
	}
	return (copy);
}

void	get_pos(t_map *m)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = m->map_arr;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == m->player_dir)
			{
				m->player.x = x;
				m->player.y = y;
			}
			else if (map[y][x] == '2')
			{
				m->enemy.x = x;
				m->enemy.y = y;
			}
			x++;
		}
		y++;
	}
}

int flood_fill(t_map *map, int x, int y, int height)
{
	if (y < 0 || y >= height)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map->copy[y]))
		return (0);
	if (map->copy[y][x] == '1' || map->copy[y][x] == 'V' || map->copy[y][x] == map->player_dir)
	{
		if (map->copy[y][x] == map->player_dir)
			map->player_hit = true;
		return (1);
	}
	if (map->copy[y][x] == ' ' || !map->copy[y][x])
		return (0);
	map->copy[y][x] = 'V';
	if (!flood_fill(map, x, y + 1, height))
		return (0);
	if (!flood_fill(map, x, y - 1, height))
		return (0);
	if (!flood_fill(map, x + 1, y, height))
		return (0);
	if (!flood_fill(map, x - 1, y, height))
		return (0);	
	return (1);
}

int validate_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	if (map->player_count != 1 || map->enemy_count != 1)
		return (map->err_msg = "Error\nPlayer/Enemy count not exactly 1\n", 0);
	map->copy = copy_map(map);
	if (!map->copy)
		return (0);
	get_pos(map);
	if (!flood_fill(map, map->enemy.x, map->enemy.y, map->map_height))
		return (map->err_msg = "Error\nEnemy room not enclosed\n", free_func(NULL, map->copy), 0);
	if (!map->player_hit)
		return (map->err_msg = "Error\nEnemy has no access to Player\n", free_func(NULL, map->copy), 0);
	while (map->copy[y])
	{
		x = 0;
		while (map->copy[y][x])
		{
			if (map->copy[y][x] == '0')
			{
				if (!flood_fill(map, x, y, map->map_height))
					return (map->err_msg = "Error\nIndependent room not enclosed\n", free_func(NULL, map->copy), 0);
			}
			x++;
		}
		y++;
	}
	return (free_func(NULL, map->copy), 1);
}
