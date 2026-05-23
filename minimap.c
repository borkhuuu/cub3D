#include "color.h"
#include "map.h"
#include "game.h"
#include "cub3D.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include "minimap.h"

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			ft_pixel_put(game, MINIMAP_X_OFFSET + x,
				MINIMAP_Y_OFFSET + y, 0xCCCCFF);
			x++;
		}
		y++;
	}
}

void	minimap_player(t_game *game)
{
	int	x;
	int	y;

	y = MINIMAP_HEIGHT / 2 - MINIMAP_HEIGHT / 10;
	while (y < MINIMAP_HEIGHT / 2 + MINIMAP_HEIGHT / 10)
	{
		x = MINIMAP_WIDTH / 2 - MINIMAP_WIDTH / 10;
		while (x < MINIMAP_WIDTH / 2 + MINIMAP_WIDTH / 10)
		{
			ft_pixel_put(game, MINIMAP_X_OFFSET + x,
				MINIMAP_Y_OFFSET + y, 0x000000);
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
{
	draw_minimap(game);
	minimap_player(game);
}
