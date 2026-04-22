#ifndef CUB3D_H
# define CUB3D_H

#include "game.h"

/*					init_mlx.c				*/

int		init_mlx(t_game *game);
int		key_handler(int keycode, t_game *game);
int		x_window(void *param);
void	mlx_cleanup(t_game *game);

/*					UTILITY					*/
int		get_arr_size(char **arr);
void	strerror_wrapper(int errno);

#endif
