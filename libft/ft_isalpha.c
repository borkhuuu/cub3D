/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:59:41 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/29 23:59:42 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	low;
	int	up;

	up = 'A';
	low = 'a';
	while (up - 1 != 'Z' && low - 1 != 'z')
	{
		if (up == c || low == c)
			return (1);
		up++;
		low++;
	}
	return (0);
}
