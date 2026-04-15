#include "game.h"
#include "map.h"
#include "mlx/mlx.h"
#include "libft/libft.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void    strerrorWrapper(const int errnum, char* msg)
{
    printf("%s\n%s\n", strerror(errnum), msg);
}

void    freeFunc(t_map* map, char** arr)
{
    int i;

    i = 0;
    while (arr && arr[i])
        free(arr[i++]);
    if (arr)
        free(arr);
    if (map)
    {
        if (map->line)
            free(map->line);
        if (map->pathNO)
            free(map->pathNO);
        if (map->pathSO)
            free(map->pathSO);
        if (map->pathWE)
            free(map->pathWE);
        if (map->pathEA)
            free(map->pathEA);
        if (map->colorF)
            free(map->colorF);
        if (map->colorC)
            free(map->colorC);
    }
}

void    init_map(t_map* map)
{
    ft_memset(map, 0,sizeof(t_map));

}

int parseLine(t_map* map)
{
    char**  arr;

    map->line = get_next_line(map->mapFd);
    arr = ft_split(map->line, ' ');
    if (!arr || !arr[0] || !arr[1] || arr[2])
        return (freeFunc(NULL, arr), 1);
    else if (!ft_strncmp(arr[0], "NO", 2))
    {
        if (!map->pathNO)
            return (map->pathNO = ft_strdup(arr[1]), freeFunc(NULL, arr), 1);
    }
    else if (!ft_strncmp(arr[0], "SO", 2))
    {
        if (!map->pathSO)
            return (map->pathSO = ft_strdup(arr[1]), freeFunc(NULL, arr), 1);
    }
    else if (!ft_strncmp(arr[0], "WE", 2))
    {
        if (!map->pathWE)
            return (map->pathWE = ft_strdup(arr[1]), freeFunc(NULL, arr), 1);
    }
    else if (!ft_strncmp(arr[0], "EA", 2))
    {
        if (!map->pathEA)
            return (map->pathEA = ft_strdup(arr[1]), freeFunc(NULL, arr), 1);
    }
    else if (!ft_strncmp(arr[0], "F", 1))
    {
        if (!map->colorF)
            return (map->colorF = ft_strdup(arr[1]), freeFunc(NULL, arr), 1);
    }
    else if (!ft_strncmp(arr[0], "C", 1))
    {
        if (!map->colorC)
            return (map->colorC = ft_strdup(arr[1]), freeFunc(NULL, arr), 1);
    }
    return (freeFunc(NULL, arr), 0);
}

bool    missingPath(t_map *map)
{
    if (!map->pathNO || !map->pathSO || !map->pathWE
        || !map->pathEA || !map->colorF || !map->colorC)
        return (true);
    return (false);
}


int main(int ac, char **av)
{
    t_map   map;

    if (ac != 2)
        return (strerrorWrapper(EINVAL, "./cub3D 'PATH to map with .cub extension'"), 1);
    init_map(&map);
    if ((map.mapFd = open(av[1], O_RDONLY)) == -1)
        return (strerrorWrapper(errno, "PATH to map invalid or lacking permissions"), 1);
    while (map.line)
    {
        while (!map.inMap)
        {
            if (!parseLine(&map))
                map.inMap = true;
        }
        if (missingPath(&map))
            return (freeFunc(&map, NULL), write(1, "PATH missing\n", 13), 1);
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