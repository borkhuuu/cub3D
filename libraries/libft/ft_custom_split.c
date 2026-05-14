#include "libft.h"

size_t	next_word(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && !ft_iswspace(s[i]))
		i++;
	return (i);
}

char	**ft_custom_split(const char *s, size_t n)
{
	char	**arr;
	size_t	idx;
	size_t	len;
	size_t	arr_idx;

	idx = 0;
	arr_idx = 0;
	if (!s)
		return (NULL);
	arr = ft_calloc(n + 1, sizeof(char*));
	if (!arr)
		return (NULL);
	while (s[idx] && ft_iswspace(s[idx]))
		idx++;
	while (s[idx] && arr_idx < n)
	{
		if (arr_idx + 1 == n)
			len = ft_strlen(&s[idx]);
		else
			len = next_word(&s[idx]);
		arr[arr_idx] = ft_calloc(len + 1, sizeof(char));
		if (!arr[arr_idx])
			return (ft_free_arr(arr), NULL);
		ft_strlcpy(arr[arr_idx], &s[idx], len + 1);
		arr_idx++;
		idx += len;
		while (s[idx] && ft_iswspace(s[idx]))
			idx++;
	}
	return (arr);
}
