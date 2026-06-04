/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:34:10 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/01 15:41:15 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <X11/keysym.h>
#include <math.h>
#include <stdbool.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->movement.w = true;
	if (keycode == XK_a)
		game->movement.a = true;
	if (keycode == XK_s)
		game->movement.s = true;
	if (keycode == XK_d)
		game->movement.d = true;
	if (keycode == XK_Left)
		game->movement.left = true;
	if (keycode == XK_Right)
		game->movement.right = true;
	if (keycode == XK_Escape)
		mlx_cleanup(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->movement.w = false;
	if (keycode == XK_a)
		game->movement.a = false;
	if (keycode == XK_s)
		game->movement.s = false;
	if (keycode == XK_d)
		game->movement.d = false;
	if (keycode == XK_Left)
		game->movement.left = false;
	if (keycode == XK_Right)
		game->movement.right = false;
	return (0);
}

void	movement(t_game *game, double delta_time)
{
	t_vec	move;
	
	ft_memset(&move, 0, sizeof(t_vec));
	if (game->movement.w)
	{
		move.x += game->player.dir.x;
		move.y += game->player.dir.y;
	}
	if (game->movement.a)
	{
		move.x += game->player.dir.y;
		move.y -= game->player.dir.x;
	}
	if (game->movement.s)
	{
		move.x -= game->player.dir.x;
		move.y -= game->player.dir.y;
	}
	if (game->movement.d)
	{
		move.x -= game->player.dir.y;
		move.y += game->player.dir.x;
	}
	if (game->movement.left)
		rotate(game, 0, delta_time);
	if (game->movement.right)
		rotate(game, 1, delta_time);
	player_move(game, move.x, move.y, delta_time);
}

bool	boundary_check_x(t_map *map, double new_x, double pos_y)
{
	char	**map_arr;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	
	x1 = (int)(new_x - PADDING);
	x2 = (int)(new_x + PADDING);
	y1 = (int)(pos_y - PADDING);
	y2 = (int)(pos_y + PADDING);
	if (y1 < 0 || y2 < 0
		|| y1 >= (int)map->map_height
		|| y2 >= (int)map->map_height)
		return (false);
	if (x1 < 0 || x2 < 0
		|| x2 >= (int)map->strlen_arr[y1]
		|| x2 >= (int)map->strlen_arr[y2]
		|| x1 >= (int)map->strlen_arr[y1]
		|| x1 >= (int)map->strlen_arr[y2])
		return (false);
	map_arr = map->map_arr;
	if (map_arr[y1][x1] != '1' && map_arr[y2][x2] != '1'
			&& map_arr[y1][x2] != '1' && map_arr[y2][x1] != '1')
		return (true);
	return (false);
}

bool	boundary_check_y(t_map *map, double new_y, double pos_x)
{
	char	**map_arr;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = (int)(pos_x - PADDING);
	x2 = (int)(pos_x + PADDING);
	y1 = (int)(new_y - PADDING);
	y2 = (int)(new_y + PADDING);
	if (y1 < 0 || y2 < 0
		|| y1 >= (int)map->map_height
		|| y2 >= (int)map->map_height)
		return (false);
	if (x1 < 0 || x2 < 0
		|| x2 >= (int)map->strlen_arr[y1] 
		|| x2 >= (int)map->strlen_arr[y2]
		|| x1 >= (int)map->strlen_arr[y1]
		|| x1 >= (int)map->strlen_arr[y2])
		return (false);
	map_arr = map->map_arr;
	if (map_arr[y1][x1] != '1' && map_arr[y2][x2] != '1'
			&& map_arr[y1][x2] != '1' && map_arr[y2][x1] != '1')
		return (true);
	return (false);
}
