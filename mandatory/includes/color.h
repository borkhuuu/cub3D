#ifndef COLOR_H
# define COLOR_H

#include <stdbool.h>

typedef	struct s_color
{
	char	**values;
	int		r;
	int		g;
	int		b;
	bool	set;
}	t_color;

#endif
