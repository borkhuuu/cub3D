#include "libft.h"
#include <stddef.h>

size_t	ft_arr_size(const char **arr)
{
	size_t	n;
	
	n = 0;
	if (!arr)
		return (0);
	while (arr[n])
		n++;
	return (n);
}