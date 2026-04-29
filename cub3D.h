#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_game t_game;

typedef struct s_texture
{
	void	*ptr_to_img;
	char	*ptr_to_pixel;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_texture;

/*					init_mlx.c				*/

int		init_mlx(t_game *game);
int		key_handler(int keycode, t_game *game);
int		x_window(void *param);
void	mlx_cleanup(t_game *game);
void	ft_pixel_put(t_game *game, int x, int y, int colour);

/*					textures.c				*/
int		load_textures(t_game *game);

/*					UTILITY					*/
int		get_arr_size(char **arr);
void	strerror_wrapper(int errno);
void	free_textures(t_game *game, t_texture textures[4]);
const char	*skip_whitespaces(char *s);
#endif
