#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <stddef.h>

int	rerun_bfs(t_game *game)
{
	double	dx;
	double	dy;

	dx = game->player.pos.x - game->enemy.last_bfs_player_pos.x;
	dy = game->player.pos.y - game->enemy.last_bfs_player_pos.y;
	if (dx * dx + dy * dy > BFS_THRESHOLD * BFS_THRESHOLD
			|| !game->enemy.bfs_path
			|| (!game->enemy.bfs_path[game->enemy.path_index] && !game->enemy.has_target))
	{
		free(game->enemy.bfs_path);
		game->enemy.bfs_path = bfs(game);
		if (!game->enemy.bfs_path)
			return (0);
		game->enemy.path_index = 0;
		game->enemy.last_bfs_player_pos = (t_vec){game->player.pos.x, game->player.pos.y};
		game->enemy.has_target = false;
		game->enemy.bfs_path_len = ft_strlen(game->enemy.bfs_path);
	}
	return (1);
}

int	setup_bfs(t_bfs *bfs, t_game *game)
{
	bfs->map = game->map;
	bfs->came_from = ft_calloc((bfs->map->map_height * bfs->map->map_max_width) + 1, sizeof(char));
	if (!bfs->came_from)
		return (0);
	bfs->queue = ft_calloc(bfs->map->map_height * bfs->map->map_max_width, sizeof(t_vec_int));
	if (!bfs->queue)
		return (free(bfs->came_from), 0);
	if (game->enemy.has_target)
	{
		bfs->queue[0] = (t_vec_int){(int)game->enemy.target_pos.x, (int)game->enemy.target_pos.y};
		bfs->came_from[(int)game->enemy.target_pos.y * bfs->map->map_max_width + (int)game->enemy.target_pos.x] = 'V';
	}
	else
	{
		bfs->queue[0] = (t_vec_int){(int)game->enemy.pos.x, (int)game->enemy.pos.y};
		bfs->came_from[(int)game->enemy.pos.y * bfs->map->map_max_width + (int)game->enemy.pos.x] = 'V';
	}
	return (1);
}

char	*reconstruct_path(t_game *game, t_bfs *bfs)
{
	t_vec_int	curr;
	char		*path;
	char		*rev_path;
	char		dir;
	size_t		path_len;
	
	path = ft_calloc((bfs->map->map_height * bfs->map->map_max_width) + 1, sizeof(char));
	if (!path)
		return (NULL);
	path_len = 0;
	curr = (t_vec_int){(int)game->player.pos.x, (int)game->player.pos.y};
	while (curr.x != bfs->queue[0].x || curr.y != bfs->queue[0].y)
	{
		dir = bfs->came_from[curr.y * bfs->map->map_max_width + curr.x];
		if (dir == 'N')
		{
			path[path_len] = 'S';
			curr.y -= 1;
		}
		else if (dir == 'S')
		{
			path[path_len] = 'N';
			curr.y += 1;
		}
		else if (dir == 'W')
		{
			path[path_len] = 'E';
			curr.x -= 1;
		}
		else if (dir == 'E')
		{
			path[path_len] = 'W';
			curr.x += 1;
		}
		else
			break ;
		path_len++;
	}
	rev_path = ft_strrev(path);
	free(path);
	return (rev_path);
}

char	*bfs(t_game *game)
{
	t_bfs		bfs;
	t_vec_int	curr;
	char		*path;
	size_t		head;
	size_t		tail;
	
	head = 0;
	tail = 1;
	if (!setup_bfs(&bfs, game))
		return (NULL);
	while (head != tail)
	{
		curr = bfs.queue[head++];
		if ((curr.x >= 0 && curr.y >= 0 && curr.y < (int)bfs.map->map_height))
		{
			if (curr.x == (int)game->player.pos.x && curr.y == (int)game->player.pos.y)
				break ;
			if (curr.y + 1 < (int)bfs.map->map_height && curr.x < (int)bfs.map->strlen_arr[curr.y + 1] && bfs.map->map_arr[curr.y + 1][curr.x] != '1'
				&& bfs.came_from[(curr.y + 1) * bfs.map->map_max_width + curr.x] == 0)
			{
				bfs.came_from[(curr.y + 1) * bfs.map->map_max_width + curr.x] = 'N';
				bfs.queue[tail++] = (t_vec_int){curr.x, curr.y + 1};
			}
			if (curr.y - 1 >= 0 && curr.x < (int)bfs.map->strlen_arr[curr.y - 1] && bfs.map->map_arr[curr.y - 1][curr.x] != '1'
				&& bfs.came_from[(curr.y - 1) * bfs.map->map_max_width + curr.x] == 0)
			{
				bfs.came_from[(curr.y - 1) * bfs.map->map_max_width + curr.x] = 'S';
				bfs.queue[tail++] = (t_vec_int){curr.x, curr.y - 1};
			}
			if (curr.x + 1 < (int)bfs.map->strlen_arr[curr.y] && bfs.map->map_arr[curr.y][curr.x + 1] != '1'
				&& bfs.came_from[curr.y * bfs.map->map_max_width + curr.x + 1] == 0)
			{
				bfs.came_from[curr.y * bfs.map->map_max_width + curr.x + 1] = 'W';
				bfs.queue[tail++] = (t_vec_int){curr.x + 1, curr.y};
			}
			if (curr.x - 1 >= 0 && curr.x - 1 < (int)bfs.map->strlen_arr[curr.y] && bfs.map->map_arr[curr.y][curr.x - 1] != '1'
				&& bfs.came_from[curr.y * bfs.map->map_max_width + curr.x - 1] == 0)
			{
				bfs.came_from[curr.y * bfs.map->map_max_width + curr.x - 1] = 'E';
				bfs.queue[tail++] = (t_vec_int){curr.x - 1, curr.y};
			}
		}
	}
	path = reconstruct_path(game,&bfs);
	free(bfs.queue);
	free(bfs.came_from);
	return (path);
}
