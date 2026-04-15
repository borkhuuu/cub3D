/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:04:15 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/30 00:04:16 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	low;
	int	up;
	int	digit;

	low = 'a';
	up = 'A';
	digit = '0';
	while (digit - 1 != '9')
	{
		if (digit == c)
			return (1);
		digit++;
	}
	while (low - 1 != 'z' && up - 1 != 'Z')
	{
		if (low == c || up == c)
			return (1);
		low++;
		up++;
	}
	return (0);
}
