#include "game.h"
#include "map.h"
#include "mlx/mlx.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char*   getIdxLine(const int fd, int idx)
{
    char*   line;

    while ((line = get_next_line) && idx > 0)
    {
        idx--;
    }
    return (line);
}

int main(int ac, char **av)
{
    t_map   map;

    if (ac != 2)
        return (perror("./cub3D 'PATH to map with .cub extension'\n"), 1);
    if ((map.mapFd = open(av[1], O_RDONLY)) == -1)
        return (perror("open failed\n"), 1);
    map.mapLineIdx = 1;
    while (map.line)
    {
        map.line = getIdxLine(map.mapFd, map.mapLineIdx);
        
    }
}

// int main(int ac, char **av)
// {
//     void    *mlx;
//     void    *mlx_win;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World\n");
//     mlx_loop(mlx);
// }