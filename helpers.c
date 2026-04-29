#include "cub3D.h"
#include "mlx/mlx.h"
#include "game.h"

void	free_textures(t_game *game, t_texture textures[4])
{
	if (textures[0].ptr_to_img)
		mlx_destroy_image(game->connection, textures[0].ptr_to_img);
	if (textures[1].ptr_to_img)
		mlx_destroy_image(game->connection, textures[1].ptr_to_img);
	if (textures[2].ptr_to_img)
		mlx_destroy_image(game->connection, textures[2].ptr_to_img);
	if (textures[3].ptr_to_img)
		mlx_destroy_image(game->connection, textures[3].ptr_to_img);
}

int	get_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
