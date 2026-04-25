#include "game.h"
#include "cub3D.h"
#include <X11/keysym.h>
int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->movement.w = true;
	if (keycode == XK_a)
		game->movement.a = true;
	if (keycode == XK_s)
		game->movement.s = true;
	if (keycode == XK_d)
		game->movement.d = true;
	if (keycode == XK_Escape)
		mlx_cleanup(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->movement.w = false;
	if (keycode == XK_a)
		game->movement.a = false;
	if (keycode == XK_s)
		game->movement.s = false;
	if (keycode == XK_d)
		game->movement.d = false;
	return (0);
}

void	movement(t_game *game)
{
	if (game->movement.w)
		forward(game);
	if (game->movement.a)
		left(game);
	if (game->movement.s)
		backward(game);
	if (game->movement.d)
		right(game);
}
