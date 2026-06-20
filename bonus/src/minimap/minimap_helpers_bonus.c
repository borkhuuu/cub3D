/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:28:19 by rheidary          #+#    #+#             */
/*   Updated: 2026/06/14 13:04:30 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../../libraries/mlx/mlx.h"
#include <X11/X.h>
#include "../../includes/minimap_bonus.h"

bool	is_border(int x, int y)
{
	if ((x < MINIMAP_TILE_SIZE || x >= MINIMAP_SIZE - MINIMAP_TILE_SIZE)
		|| (y < MINIMAP_TILE_SIZE || y >= MINIMAP_SIZE - MINIMAP_TILE_SIZE))
		return (1);
	return (0);
}

void	get_color(int *color, char tile)
{
	if (tile == '1')
		*color = 0x40E0D0;
	else if (tile == '0' || tile == 'M'
		|| tile == 'N' || tile == 'S'
		|| tile == 'E' || tile == 'W')
		*color = 0x808080;
	else if (tile == 'D')
		*color = 0x40FFF1;
	else
		*color = 0xFF0000;
}

char	get_tile(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_y >= (int)game->map->map_height)
		return (' ');
	if (map_x >= (int)ft_strlen(game->map->map_arr[map_y]))
		return (' ');
	return (game->map->map_arr[map_y][map_x]);
}

void	get_start_pos(t_game *game, int tile_count, int *x, int *y)
{
	*x = (int)game->player.pos.x - (tile_count / 2);
	*y = (int)game->player.pos.y - (tile_count / 2);
}
