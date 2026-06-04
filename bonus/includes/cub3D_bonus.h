/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:58:35 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/01 12:48:01 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "vec_bonus.h"
# include "color_bonus.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_game		t_game;
typedef struct s_raycast	t_raycast;
typedef struct s_map		t_map;
typedef struct s_entity		t_entity;
typedef struct s_texture
{
	void	*ptr_to_img;
	char	*ptr_to_pixel;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
	unsigned int	color;
	bool	valid;
}	t_texture;

typedef struct s_render
{
	size_t	x;
	size_t	y;
	int		tex_x;
	int		tex_y;
	double	m_center;
	double	ratio;
	double	tex_pos;
	double	step;
	int		s_height;
	int		s_width;
	int		start;
	int		end;
	int		v_start;
	int		v_start_unclamped;
	int		v_end;

}	t_render;

/*					init_mlx.c				*/

void		init_mlx(t_game *game);
int			key_handler(int keycode, t_game *game);
int			x_window(void *param);
void		mlx_cleanup(t_game *game);

/*					render.c				*/
int			render_player(t_game *game);
void		draw(t_game *game, t_texture t, int height, size_t x);

/*					monster.c				*/
void		draw_monster(t_game *game, t_texture t);
t_vec		trans_to_cam_space(t_game *game, t_entity p);
void		draw_ceiling(t_game *game, t_render *r);
void		draw_middle(t_game *game, t_texture t, t_render *r);
void		draw_floor(t_game *game, t_render *r);

/*					textures.c				*/
void		load_textures(t_game *game);
t_texture	select_texture(t_game *game, t_raycast ray);
void		calculate_texture_pixel(t_raycast *ray, t_render *r, t_texture t);

/*					UTILITY					*/
//		general
int			init_strlen_arr(t_map *map);
int			get_texture_pixel_color(t_texture t, int x, int y);
void		ft_pixel_put(t_game *game, int x, int y, int colour);
double		get_time();
//		parsing
void		strerror_wrapper(const int errnum);
bool		is_valid(const char c);
bool		is_player(const char c);
bool		is_enemy(const char c);
bool		is_path(const char *s);
//		memory
void		free_paths(t_map *map);
void		free_func(t_map *map, char **arr);
void		free_textures(t_game *game, t_texture textures[4]);
void		mlx_cleanup(t_game *game);

//		checks
size_t		check_comma(const char *s);
int			check_format(const char *s);
int			check_hidden_file(t_map *map, const char *path);
int			check_extension(t_map *map, const char *path, const char *ext);
bool		check_missing_path(t_map *map);

//		setup
void		setup_player_vectors(t_entity *player);
void		vector_setter(t_vec *v, double x, double y);
void		init_player(t_game *game);
void		init_enemy(t_game *game);
void		init_color(t_game *game, t_color color_f, t_color color_c);

//		whitespaces
char		**trim_ws_loop(char **arr);
void		trim_ws_back(char *s);
size_t		first_char(const char *s);
size_t		last_char(const char *s);
#endif
