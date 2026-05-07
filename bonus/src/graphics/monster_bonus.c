#include "../../includes/game_bonus.h"
#include "../../../libraries/libft/libft.h"

t_vec	trans_to_cam_space(t_game *game, t_entity p)
{
	t_vec	camera;
	double	inv_det;
	double	relative_x;
	double	relative_y;

	relative_x = game->enemy.pos.x - p.pos.x;
	relative_y = game->enemy.pos.y - p.pos.y;
	inv_det = 1.0 / (p.camera.x * p.dir.y - p.dir.x * p.camera.y);
	camera.x = inv_det * (p.dir.y * relative_x
		- p.dir.x * relative_y);
	camera.y = inv_det * (-p.camera.y * relative_x
		+ p.camera.x * relative_y);
	return (camera);
}

void	draw_vert_line(t_game *game, t_render *r, t_texture t, int stripe)
{
	size_t	y;
	size_t	end;

	y = (size_t)r->v_start;
	end = (size_t)r->v_end;
	while (y < end)
	{
		r->tex_y = (int)r->tex_pos;
		r->tex_pos += r->step;
		t.color = get_texture_pixel_color(t, r->tex_x, r->tex_y);
		if ((t.color & 0x00FFFFFF) != 0)
			ft_pixel_put(game, stripe, y, t.color);
		y++;
	}
}

void	draw_monster(t_game *game, t_texture t)
{
	t_render	r;
	double		cam_y;
	int			stripe;

	ft_memset(&r, 0, sizeof(t_render));
	game->enemy.camera = trans_to_cam_space(game, game->player);
	cam_y = game->enemy.camera.y;
	r.s_height = abs((int)(HEIGHT / cam_y));
	r.ratio = (double)t.width / (double)t.height;
	r.s_width = abs((int)(r.s_height * r.ratio));
	r.m_center = WIDTH / 2 * (1 + (game->enemy.camera.x / cam_y));
	r.start = (int)(r.m_center - (r.s_width / 2));
	r.end = (int)(r.m_center + (r.s_width / 2));
	if (r.start < 0)
		r.start = 0;
	if (r.end >= WIDTH)
		r.end = WIDTH - 1;
	r.v_start = -r.s_height / 2 + HEIGHT / 2;
	r.v_end = r.s_height / 2 + HEIGHT / 2;
	if (r.v_start < 0)
		r.v_start = 0;
	if (r.v_end >= HEIGHT)
		r.v_end = HEIGHT - 1;
	r.step = (double)t.height / r.s_height;
	stripe = r.start;
	while (stripe < r.end && stripe >= 0 && stripe < WIDTH)
	{
		r.tex_x = (int)((stripe - (r.m_center - r.s_width / 2)) * t.width / r.s_width);
		if (cam_y > 0 && cam_y < game->pdist_buffer[stripe])
		{
			r.tex_pos = (r.v_start - HEIGHT / 2.0 + r.s_height / 2.0) * r.step;
			draw_vert_line(game, &r, t, stripe);
		}
		stripe++;
	}
}
