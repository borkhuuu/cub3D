#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_game t_game;
typedef struct s_raycast t_raycast;
typedef struct s_texture
{
	void	*ptr_to_img;
	char	*ptr_to_pixel;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
	int		color;
}	t_texture;

typedef struct s_render
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		start;
	int		end;

}	t_render;

/*					init_mlx.c				*/

int		init_mlx(t_game *game);
int		key_handler(int keycode, t_game *game);
int		x_window(void *param);
void	mlx_cleanup(t_game *game);
void	ft_pixel_put(t_game *game, int x, int y, int colour);

/*					render.c				*/
int		render_player(t_game *game);
void	draw(t_game *game, t_texture t, int height, int x);

/*					textures.c				*/
int		load_textures(t_game *game);
t_texture	select_texture(t_game *game, t_raycast ray);
void	calculate_texture_pixel(t_raycast *ray, t_render *r, t_texture t);
int		get_texture_pixel_color(t_texture t, int x, int y);
/*					UTILITY					*/
int		get_arr_size(char **arr);
void	strerror_wrapper(int errno);
void	free_textures(t_game *game, t_texture textures[4]);
const char	*skip_whitespaces(char *s);
#endif
