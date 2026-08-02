/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:20:21 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/02 17:23:33 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_split	split;

	ft_memset(&split, 0, sizeof(t_split));
	split.arr = ft_calloc(n + 1, sizeof(char *));
	if (!split.arr)
		return (NULL);
	while (s[split.idx] && ft_iswspace(s[split.idx]))
		split.idx++;
	while (s[split.idx] && split.arr_idx < n)
	{
		if (split.arr_idx + 1 == n)
			split.len = ft_strlen(&s[split.idx]);
		else
			split.len = next_word(&s[split.idx]);
		split.arr[split.arr_idx] = ft_calloc(split.len + 1, sizeof(char));
		if (!split.arr[split.arr_idx])
			return (ft_free_arr(split.arr), NULL);
		ft_strlcpy(split.arr[split.arr_idx], &s[split.idx], split.len + 1);
		split.arr_idx++;
		split.idx += split.len;
		while (s[split.idx] && ft_iswspace(s[split.idx]))
			split.idx++;
	}
	return (split.arr);
}
