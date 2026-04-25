#include "game.h"
#include "map.h"
void	forward(t_game *game)
{
	t_vec	new_pos;

	new_pos.x = game->player.pos.x + game->player.dir.x * SPEED;
	new_pos.y = game->player.pos.y + game->player.dir.y * SPEED;
	if (game->map->map_arr[(int)new_pos.y][(int)new_pos.x] != '1')
		game->player.pos = new_pos;
}

void	backward(t_game *game)
{
	t_vec	new_pos;

	new_pos.x = game->player.pos.x - game->player.dir.x * SPEED;
	new_pos.y = game->player.pos.y - game->player.dir.y * SPEED;
	if (game->map->map_arr[(int)new_pos.y][(int)new_pos.x] != '1')
		game->player.pos = new_pos;
}

void	left(t_game *game)
{
	t_vec	new_pos;

	new_pos.x = game->player.pos.x - game->player.camera.x * SPEED;
	new_pos.y = game->player.pos.y - game->player.camera.y * SPEED;
	if (game->map->map_arr[(int)new_pos.y][(int)new_pos.x] != '1')
		game->player.pos = new_pos;
}

void	right(t_game *game)
{
	t_vec	new_pos;

	new_pos.x = game->player.pos.x + game->player.camera.x * SPEED;
	new_pos.y = game->player.pos.y + game->player.camera.y * SPEED;
	if (game->map->map_arr[(int)new_pos.y][(int)new_pos.x] != '1')
		game->player.pos = new_pos;
}
