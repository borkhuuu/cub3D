#ifndef GAME_H
#define GAME_H

#ifndef WIDTH
# define WIDTH 900
#endif
#ifndef HEIGHT
# define HEIGHT 1600
#endif

typedef struct s_map t_map;

typedef struct s_image
{
	void	*ptr_to_img;
	char	*ptr_to_pixel;
	int		line_len;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_game
{
	t_map	*map;
	t_image	image;
	void	*connection;
	void	*window;
}	t_game;

/*					game.c					*/
int	start_game(t_map *map);

#endif
