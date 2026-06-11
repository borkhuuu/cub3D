/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:25:58 by rheidary          #+#    #+#             */
/*   Updated: 2026/04/29 15:46:10 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_WIDTH			200
# define MINIMAP_HEIGHT			200

# define MINIMAP_TILE_SIZE		8
# define MINIMAP_PLAYER_SIZE	4
# define MINIMAP_X_OFFSET		10
# define MINIMAP_Y_OFFSET		10
# define MINIMAP_BORDER			2

void	minimap(t_game *g);

#endif