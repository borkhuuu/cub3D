#include "../libft/libft.h"
#include "../map.h"

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

void	get_player_pos(t_map *m)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	x = 0;
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
				return ;
			}
			x++;
		}
		y++;
	}
}

int flood_fill(char **map, int x, int y, int height)
{
	if (y < 0 || y >= height)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	if (map[y][x] == ' ' || !map[y][x])
		return (0);
	map[y][x] = 'V';
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
	char	**copy;
	int		x;
	int		y;

	y = 0;
	if (map->player_count != 1)
		return (map->err_msg = "Error\nPlayer count not exactly 1\n", 0);
	copy = copy_map(map);
	if (!copy)
		return (0);
	get_player_pos(map);
	if (!flood_fill(copy, map->player.x, map->player.y, map->map_height))
		return (map->err_msg = "Error\nFloodfill from player pos failed\n", free_func(NULL, copy), 0);
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == '0')
			{
				if (!flood_fill(copy, x, y, map->map_height))
					return (map->err_msg = "Error\nFloodfill in independent room failed\n", free_func(NULL, copy), 0);
			}
			x++;
		}
		y++;
	}
	return (free_func(NULL, copy), 1);
}
