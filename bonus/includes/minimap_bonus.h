/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:56:36 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 18:38:12 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "game_bonus.h"

# define MINIMAP_SIZE 170
# define MINIMAP_OFFSET 10
# define MINIMAP_TILE_SIZE 10

void	minimap(t_game *game);
bool	is_border(int x, int y);
void	get_color(int *color, char tile);
char	get_tile(t_game *game, int map_x, int map_y);
void	get_start_pos(t_game *game, int tile_count, int *x, int *y);

bool	get_enemy_pos(t_game *game, int *m_x, int *m_y, int tile_count);
void	draw_background(t_game *game);

#endif