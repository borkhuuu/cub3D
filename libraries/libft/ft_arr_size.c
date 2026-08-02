/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:05:10 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/02 17:05:35 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
