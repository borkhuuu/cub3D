#include "../../includes/cub3D_bonus.h"
#include "../../../libraries/mlx/mlx.h"
#include "../../includes/game_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <string.h>

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

void	strerror_wrapper(const int errnum)
{
	char	*err;

	err = strerror(errnum);
	write(2, err, ft_strlen(err));
}

void	vector_setter(t_vec *v, double x, double y)
{
	v->x = x;
	v->y = y;
}


