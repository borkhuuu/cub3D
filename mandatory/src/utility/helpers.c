/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:49:47 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/13 20:59:44 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include "../../includes/game.h"

int	get_texture_pixel_color(t_texture t, int x, int y)
{
	return (*(int *)(t.ptr_to_pixel + (y * t.line_len + x * (t.bpp / 8))));
}

void	ft_pixel_put(t_game *game, int x, int y, int colour)
{
	char	*pixel_to_manipulate;

	pixel_to_manipulate = game->image.ptr_to_pixel
		+ (y * game->image.line_len + x * (game->image.bpp / 8));
	*(unsigned int *)pixel_to_manipulate = colour;
}
