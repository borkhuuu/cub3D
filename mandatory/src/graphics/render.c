#include "../../includes/game.h"
#include "../../includes/cub3D.h"

void	draw(t_game *game, t_texture t, int height, int x)
{
	t_render	r;
	int	y;

	r.start = HEIGHT / 2 - height / 2;
	r.end = HEIGHT / 2 + height / 2;
	y = 0;
	if (r.start < 0)
		r.start = 0;
	if (r.end >= HEIGHT)
		r.end = HEIGHT - 1;
	while (y < r.start)
	{
		ft_pixel_put(game, x, y, game->color_c);
		y++;
	}
	calculate_texture_pixel(&game->ray, &r, t);
	while (y <= r.end)
	{
		r.tex_y = (int)r.tex_pos;// % t.height;
		r.tex_pos += r.step;
		t.color = get_texture_pixel_color(t, r.tex_x, r.tex_y);
		ft_pixel_put(game, x, y, t.color);
		y++;
	}
	while (y < HEIGHT)
	{
		ft_pixel_put(game, x, y, game->color_f);
		y++;
	}
}
