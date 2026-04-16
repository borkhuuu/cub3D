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

void    freeFunc(t_map* map, char** arr, char* s)
{
    int i;

    i = 0;
    while (arr && arr[i])
        free(arr[i++]);
    if (arr)
    {
        free(arr);
        arr = NULL;
    }
    if (s)
    {
        free(s);
        s = NULL;
    }
    if (map)
    {
        if (map->line)
        {
            free(map->line);
            map->line = NULL;
        }
        if (map->pathNO)
        {
            free(map->pathNO);
            map->pathNO = NULL;
        }
        if (map->pathSO)
        {
            free(map->pathSO);
            map->pathSO = NULL;
        }
        if (map->pathWE)
        {
            free(map->pathWE);
            map->pathWE = NULL;
        }
        if (map->pathEA)
        {
            free(map->pathEA);
            map->pathEA = NULL;
        }
        if (map->colorF)
        {
            free(map->colorF);
            map->colorF = NULL;
        }
        if (map->colorC)
        {
            free(map->colorC);
            map->colorC = NULL;
        }
    }
}

void    init_map(t_map* map)
{
    ft_memset(map, 0,sizeof(t_map));
}

int getArrSize(char** arr)
{
    int i;

    i = 0;
    if (!arr)
        return (0);
    while (arr[i])
        i++;
    return (i);
}

void parseLine(t_map* map)
{
    char**  arr;
    int     arrSize;

    map->line = get_next_line(map->mapFd);
    arr = ft_split(map->line, ' ');
    arrSize = getArrSize(arr);
    if (arrSize == 0)
        return ;
    else if (arrSize >= 1 && arr[0][0] == '1')
        return (map->inMap = true, freeFunc(NULL, arr, NULL));
    else if (arrSize != 2)
        return (freeFunc(map, arr, NULL));
    else if (!ft_strcmp(arr[0], "NO"))
    {
        if (!map->pathNO)
            return (map->pathNO = ft_strdup(arr[1]), freeFunc(NULL, arr, map->line));
    }
    else if (!ft_strcmp(arr[0], "SO"))
    {
        if (!map->pathSO)
            return (map->pathSO = ft_strdup(arr[1]), freeFunc(NULL, arr, map->line));
    }
    else if (!ft_strcmp(arr[0], "WE"))
    {
        if (!map->pathWE)
            return (map->pathWE = ft_strdup(arr[1]), freeFunc(NULL, arr, map->line));
    }
    else if (!ft_strcmp(arr[0], "EA"))
    {
        if (!map->pathEA)
            return (map->pathEA = ft_strdup(arr[1]), freeFunc(NULL, arr, map->line));
    }
    else if (!ft_strcmp(arr[0], "F"))
    {
        if (!map->colorF)
            return (map->colorF = ft_strdup(arr[1]), freeFunc(NULL, arr, map->line));
    }
    else if (!ft_strcmp(arr[0], "C"))
    {
        if (!map->colorC)
            return (map->colorC = ft_strdup(arr[1]), freeFunc(NULL, arr, map->line));
    }
    else
    {
        map->inMap = true;
        freeFunc(NULL, arr, NULL);
    }
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
    while (map.line && !map.inMap)
    {
        parseLine(&map)

    }
    if (missingPath(&map))
        return (freeFunc(&map, NULL), write(1, "PATH missing\n", 13), 1);
}

// int main(int ac, char **av)
// {
//     void    *mlx;
//     void    *mlx_win;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World\n");
//     mlx_loop(mlx);
// }