#include "../../includes/cub3D.h"
#include <stdbool.h>

bool	is_valid(const char c)
{
	if (c != '0' && c != '1' && c != '\n' && c != ' '
		&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
		return (false);
	return (true);
}

bool	is_player(const char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (true);
	return (false);
}

