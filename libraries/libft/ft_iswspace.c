#include "libft.h"

bool	ft_iswspace(const char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}
