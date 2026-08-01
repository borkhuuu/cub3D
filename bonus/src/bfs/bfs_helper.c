/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 20:39:36 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 21:11:41 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <stddef.h>

void	check_one(t_vec_int curr, t_bfs *bfs)
{
	if (curr.y + 1 < (int)bfs->map->map_height && curr.x
		< (int)bfs->map->strlen_arr[curr.y + 1]
		&& bfs->map->map_arr[curr.y + 1][curr.x] != '1'
		&& bfs->came_from[(curr.y + 1)
		* bfs->map->map_max_width + curr.x] == 0)
	{
		(*bfs).came_from[(curr.y + 1) * bfs->map->map_max_width + curr.x] = 'N';
		(*bfs).queue[bfs->tail++] = (t_vec_int){curr.x, curr.y + 1};
	}
}

void	check_two(t_vec_int curr, t_bfs *bfs)
{
	if (curr.y - 1 >= 0 && curr.x < (int)bfs->map->strlen_arr[curr.y - 1]
		&& bfs->map->map_arr[curr.y - 1][curr.x] != '1'
		&& bfs->came_from[(curr.y - 1)
		* bfs->map->map_max_width + curr.x] == 0)
	{
		bfs->came_from[(curr.y - 1) * bfs->map->map_max_width + curr.x] = 'S';
		bfs->queue[bfs->tail++] = (t_vec_int){curr.x, curr.y - 1};
	}
}

void	check_three(t_vec_int curr, t_bfs *bfs)
{
	if (curr.x + 1 < (int)bfs->map->strlen_arr[curr.y]
		&& bfs->map->map_arr[curr.y][curr.x + 1] != '1'
		&& bfs->came_from[curr.y
		* bfs->map->map_max_width + curr.x + 1] == 0)
	{
		bfs->came_from[curr.y * bfs->map->map_max_width + curr.x + 1] = 'W';
		bfs->queue[bfs->tail++] = (t_vec_int){curr.x + 1, curr.y};
	}
}

void	check_four(t_vec_int curr, t_bfs *bfs)
{
	if (curr.x - 1 >= 0 && curr.x - 1 < (int)bfs->map->strlen_arr[curr.y]
		&& bfs->map->map_arr[curr.y][curr.x - 1] != '1'
		&& bfs->came_from[curr.y
		* bfs->map->map_max_width + curr.x - 1] == 0)
	{
		bfs->came_from[curr.y * bfs->map->map_max_width + curr.x - 1] = 'E';
		bfs->queue[bfs->tail++] = (t_vec_int){curr.x - 1, curr.y};
	}
}

int	check_dir(char *path, size_t path_len, char dir, t_vec_int *curr)
{
	if (dir == 'N')
	{
		path[path_len] = 'S';
		(*curr).y -= 1;
	}
	else if (dir == 'S')
	{
		path[path_len] = 'N';
		(*curr).y += 1;
	}
	else if (dir == 'W')
	{
		path[path_len] = 'E';
		(*curr).x -= 1;
	}
	else if (dir == 'E')
	{
		path[path_len] = 'W';
		(*curr).x += 1;
	}
	else
		return (0);
	return (1);
}
