/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:07:20 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/08 12:55:37 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../../libraries/mlx/mlx.h"
#include "../../includes/map_bonus.h"

t_texture	select_texture(t_game *game, t_raycast ray)
{
	if (ray.side == 1)
	{
		if (ray.step_y > 0)
			return (game->textures[0]);
		else
			return (game->textures[1]);
	}
	else
	{
		if (ray.step_x > 0)
			return (game->textures[2]);
		else
			return (game->textures[3]);
	}
}

void	calculate_texture_pixel(t_raycast *ray, t_render *r, t_texture t)
{
	if (!r)
		return ;
	r->tex_x = ray->wall_hit * t.width;
	if (ray->side == 0 && ray->ray_dir.x < 0)
		r->tex_x = t.width - r->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir.y > 0)
		r->tex_x = t.width - r->tex_x - 1;
	r->step = (double)t.height / ray->wall_height;
	r->tex_pos = (r->start - (double)HEIGHT / 2.0
			+ ray->wall_height / 2.0) * r->step;
}

t_texture	texture_loader(void *mlx, char *path)
{
	t_texture	t;

	ft_memset(&t, 0, sizeof(t_texture));
	t.ptr_to_img = mlx_xpm_file_to_image(mlx, path, &t.width, &t.height);
	if (!t.ptr_to_img)
		return (t.valid = false, t);
	t.ptr_to_pixel = mlx_get_data_addr(t.ptr_to_img, &t.bpp,
			&t.line_len, &t.endian);
	if (!t.ptr_to_pixel)
		return (t.valid = false, t);
	return (t.valid = true, t);
}

void	load_textures(t_game *game)
{
	game->textures[0] = texture_loader(game->connection, game->map->path_no);
	if (!game->textures[0].valid)
	{
		game->map->err_msg = "Error\nLoading NO texture failed\n";
		mlx_cleanup(game);
	}
	game->textures[1] = texture_loader(game->connection, game->map->path_so);
	if (!game->textures[1].valid)
	{
		game->map->err_msg = "Error\nLoading SO texture failed\n";
		mlx_cleanup(game);
	}
	game->textures[2] = texture_loader(game->connection, game->map->path_we);
	if (!game->textures[2].valid)
	{
		game->map->err_msg = "Error\nLoading WE texture failed\n";
		mlx_cleanup(game);
	}
	game->textures[3] = texture_loader(game->connection, game->map->path_ea);
	if (!game->textures[3].valid)
	{
		game->map->err_msg = "Error\nLoading EA texture failed\n";
		mlx_cleanup(game);
	}
	game->textures[4] = texture_loader(game->connection, game->map->path_m);
	// if (!game->textures[4].valid)
	// {
	// 	game->map->err_msg = "Error\nLoading M texture failed\n";
	// 	mlx_cleanup(game);
	// }
}
