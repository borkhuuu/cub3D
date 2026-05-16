/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:31:06 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 22:39:07 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../../libraries/libft/libft.h"

void	draw_ceiling(t_game *game, t_render *r)
{
	size_t	start;

	start = (size_t)r->start;
	while (r->y < start)
	{
		ft_pixel_put(game, r->x, r->y, game->color_c);
		(r->y)++;
	}
}

void	draw_middle(t_game *game, t_texture t, t_render *r)
{
	size_t	end;

	end = (size_t)r->end;
	while (r->y <= end)
	{
		r->tex_y = (int)r->tex_pos;
		r->tex_pos += r->step;
		t.color = get_texture_pixel_color(t, r->tex_x, r->tex_y);
		ft_pixel_put(game, r->x, r->y, t.color);
		(r->y)++;
	}
}

void	draw_floor(t_game *game, t_render *r)
{
	while (r->y < HEIGHT)
	{
		ft_pixel_put(game, r->x, r->y, game->color_f);
		(r->y)++;
	}
}

void	draw(t_game *game, t_texture t, int height, size_t x)
{
	t_render	r;

	ft_memset(&r, 0, sizeof(t_render));
	r.start = HEIGHT / 2 - height / 2;
	r.end = HEIGHT / 2 + height / 2;
	r.y = 0;
	r.x = x;
	if (r.start < 0)
		r.start = 0;
	if ((size_t)r.end >= HEIGHT)
		r.end = HEIGHT - 1;
	draw_ceiling(game, &r);
	calculate_texture_pixel(&game->ray, &r, t);
	draw_middle(game, t, &r);
	draw_floor(game, &r);
}
