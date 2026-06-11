/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:06:49 by rheidary          #+#    #+#             */
/*   Updated: 2026/05/23 16:32:33 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include <X11/X.h>
#include "../../includes/minimap_bonus.h"

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
		{
			if (is_border(x, y))
				ft_pixel_put(game, x + MINIMAP_OFFSET,
					y + MINIMAP_OFFSET, 0x444444);
			else
				ft_pixel_put(game, x + MINIMAP_OFFSET,
					y + MINIMAP_OFFSET, 0x666666);
			x++;
		}
		y++;
	}
}

void	draw_tiles(t_game *game, int x_offset, int y_offset, char tile)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;
	int	color;

	get_color(&color, tile);
	start_x = MINIMAP_OFFSET + MINIMAP_TILE_SIZE + x_offset * MINIMAP_TILE_SIZE;
	start_y = MINIMAP_OFFSET + MINIMAP_TILE_SIZE + y_offset * MINIMAP_TILE_SIZE;
	y = start_y;
	while (y < start_y + MINIMAP_TILE_SIZE)
	{
		x = start_x;
		while (x < start_x + MINIMAP_TILE_SIZE)
		{
			ft_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_slice(t_game *game, int tile_count)
{
	char	tile;
	int		x;
	int		y;
	int		start_x;
	int		start_y;

	get_start_pos(game, tile_count, &start_x, &start_y);
	y = 0;
	while (y < tile_count)
	{
		x = 0;
		while (x < tile_count)
		{
			tile = get_tile(game, start_x + x, start_y + y);
			if (tile != ' ' && tile != '\0')
				draw_tiles(game, x, y, tile);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	start_x;
	int	start_y;
	int	end;

	start_y = MINIMAP_OFFSET + (MINIMAP_SIZE / 2 - MINIMAP_TILE_SIZE / 2);
	end = MINIMAP_OFFSET + (MINIMAP_SIZE / 2 + MINIMAP_TILE_SIZE / 2);
	while (start_y < end)
	{
		start_x = MINIMAP_OFFSET + (MINIMAP_SIZE / 2 - MINIMAP_TILE_SIZE / 2);
		while (start_x < end)
		{
			ft_pixel_put(game, start_x, start_y, 0x000000);
			start_x++;
		}
		start_y++;
	}
}

// ---

void	minimap(t_game *game)
{
	int	tile_count;

	tile_count = (MINIMAP_SIZE / MINIMAP_TILE_SIZE) - 2;
	draw_background(game);
	draw_slice(game, tile_count);
	draw_player(game);
}
