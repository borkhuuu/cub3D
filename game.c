#include "map.h"
#include "game.h"
#include "cub3D.h"

int	start_game(t_map *map)
{
	t_game	game;

	game.map = map;
	if (!init_mlx(&game))
		return (0);
	return (1);
}
