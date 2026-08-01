/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helpers2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:35:58 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 18:37:21 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minimap_bonus.h"

bool	get_enemy_pos(t_game *game, int *m_x, int *m_y, int tile_count)
{
	int	mm_x;
	int	mm_y;

	mm_x = (int)game->player.pos.x - tile_count / 2;
	mm_y = (int)game->player.pos.y - tile_count / 2;
	if (game->enemy.pos.x < mm_x
		|| game->enemy.pos.x >= mm_x + tile_count
		|| game->enemy.pos.y < mm_y
		|| game->enemy.pos.y >= mm_y + tile_count)
		return (false);
	*m_x = MINIMAP_OFFSET + MINIMAP_TILE_SIZE
		+ (int)(game->enemy.pos.x - mm_x) * MINIMAP_TILE_SIZE;
	*m_y = MINIMAP_OFFSET + MINIMAP_TILE_SIZE
		+ (int)(game->enemy.pos.y - mm_y) * MINIMAP_TILE_SIZE;
	return (true);
}

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
