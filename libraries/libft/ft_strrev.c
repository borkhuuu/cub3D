/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:21:37 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/02 17:21:38 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrev(const char *s)
{
	char	*rev_str;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	rev_str = ft_calloc(end + 1, sizeof(char));
	if (!rev_str)
		return (NULL);
	while (start < end)
	{
		rev_str[start] = s[end - 1 - start];
		start++;
	}
	return (rev_str);
}
