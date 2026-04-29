#include "cub3D.h"
#include "game.h"
#include "mlx/mlx.h"
#include "map.h"

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
	r->tex_pos = (r->start - (double)HEIGHT / 2.0 + ray->wall_height / 2.0) * r->step;
}

int	get_texture_pixel_color(t_texture t, int x, int y)
{
	return (*(int *)(t.ptr_to_pixel + (y * t.line_len + x * (t.bpp / 8))));
}

int	load_textures(t_game *game)
{
	t_texture	texture;

	texture.ptr_to_img = mlx_xpm_file_to_image(game->connection, game->map->path_no, &texture.width, &texture.height);
	if (!texture.ptr_to_img)
		return (game->map->err_msg = "Error\nLoading NO texture failed\n", mlx_cleanup(game), 0);
	texture.ptr_to_pixel = mlx_get_data_addr(texture.ptr_to_img, &texture.bpp, &texture.line_len, &texture.endian);
	game->textures[0] = texture;
	texture.ptr_to_img = mlx_xpm_file_to_image(game->connection, game->map->path_so, &texture.width, &texture.height);
	if (!texture.ptr_to_img)
		return (game->map->err_msg = "Error\nLoading SO texture failed\n", free_textures(game, game->textures), mlx_cleanup(game), 0);
	texture.ptr_to_pixel = mlx_get_data_addr(texture.ptr_to_img, &texture.bpp, &texture.line_len, &texture.endian);
	game->textures[1] = texture;
	texture.ptr_to_img = mlx_xpm_file_to_image(game->connection, game->map->path_we, &texture.width, &texture.height);
	if (!texture.ptr_to_img)
		return (game->map->err_msg = "Error\nLoading WE texture failed\n", free_textures(game, game->textures), mlx_cleanup(game), 0);
	texture.ptr_to_pixel = mlx_get_data_addr(texture.ptr_to_img, &texture.bpp, &texture.line_len, &texture.endian);
	game->textures[2] = texture;
	texture.ptr_to_img = mlx_xpm_file_to_image(game->connection, game->map->path_ea, &texture.width, &texture.height);
	if (!texture.ptr_to_img)
		return (game->map->err_msg = "Error\nLoading EA texture failed\n", free_textures(game, game->textures), mlx_cleanup(game), 0);
	texture.ptr_to_pixel = mlx_get_data_addr(texture.ptr_to_img, &texture.bpp, &texture.line_len, &texture.endian);
	game->textures[3] = texture;
	return (1);
}
