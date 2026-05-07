/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:03:16 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/07 14:03:30 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include <stdbool.h>

bool	is_valid(const char c)
{
	if (c != '0' && c != '1' && c != '2' && c != '\n' && c != ' '
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

bool	is_enemy(const char c)
{
	if (c == '2')
		return (true);
	return (false);
}
