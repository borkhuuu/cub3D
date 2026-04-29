#include "cub3D.h"
#include "game.h"
#include "mlx/mlx.h"
#include "map.h"

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
