#ifndef GAME_H
#define GAME_H

#ifndef WIDTH
# define WIDTH 1600 
#endif
#ifndef HEIGHT
# define HEIGHT 900
#endif
# define SPEED	0.1
#include "vec.h"
#include <stdbool.h>
typedef struct s_map t_map;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec_fov	camera;
	char	spawn;
}	t_player;

typedef struct s_image
{
	void	*ptr_to_img;
	char	*ptr_to_pixel;
	int		line_len;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_movement
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
}	t_movement;

typedef struct s_game
{
	t_map		*map;
	t_image		image;
	void		*connection;
	void		*window;
	t_player	player;
	t_movement	movement;
	t_vec		ray_dir;
	int			color_f;
	int			color_c;
}	t_game;

typedef struct s_raycast
{
	t_vec	ray_dir;
	t_vec	side_dist;
	t_vec	delta_dist;
	double	perp_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		map_x;
	int		map_y;
	int		wall_height;
}	t_raycast;

/*					game.c					*/
int		start_game(t_game *game);
int		setup_game(t_map *map);

/*					dda.c					*/

int		raycaster(t_game *game);
void	calculate_delta_dist(t_raycast *ray);
void	calculate_side_dist(t_raycast *ray, t_player *player);
void	calculate_ray_dir(t_raycast *ray, t_player *player, int x);

/*					dda_helper.c			*/
void	cast_ray(t_raycast *ray, t_game *game, int x);
void	calculate_wall_height(t_raycast *ray, t_game *game);
void	init_step_dir(t_raycast *ray, t_vec	ray_dir);
double	left_up(double ppos, double ratio);
double	right_down(double ppos, double ratio);

/*					render.c				*/
int		render_player(t_game *game);
void	draw(t_game *game, int height, int x);

/*					movement.c					*/
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	movement(t_game *game);

/*					movement_helper.c			*/
void	forward(t_game *game);
void	backward(t_game *game);
void	left(t_game *game);
void	right(t_game *game);

#endif
