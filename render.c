#include "game.h"
#include "cub3D.h"
#include <stdio.h>
void	draw(t_game *game, int height, int x)
{
	int	y;
	int	start;
	int	end;

	start = HEIGHT / 2 - height / 2;
	end = HEIGHT / 2 + height / 2;
	y = 0;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (y < start)
	{
		ft_pixel_put(game, x, y, game->color_c);
		y++;
	}
	while (y <= end)
	{
		ft_pixel_put(game, x, y, 800080);
		y++;
	}
	while (y < HEIGHT)
	{
		ft_pixel_put(game, x, y, game->color_f);
		y++;
	}
}
