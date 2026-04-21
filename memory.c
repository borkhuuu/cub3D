#include "map.h"

#include <unistd.h>
#include <stdlib.h>

void    free_func(t_map* map, char** arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
	if (map)
	{
		if (map->line)
		{
			free(map->line);
			map->line = NULL;
		}
		if (map->path_no)
		{
			free(map->path_no);
			map->path_no = NULL;
		}
		if (map->path_so)
		{
			free(map->path_so);
			map->path_so = NULL;
		}
		if (map->path_we)
		{
			free(map->path_we);
			map->path_we = NULL;
		}
		if (map->path_ea)
		{
			free(map->path_ea);
			map->path_ea = NULL;
		}
	}
}
