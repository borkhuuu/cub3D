/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:19:18 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:20:16 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_BONUS_H
# define COLOR_BONUS_H

# include <stdbool.h>

typedef struct s_color
{
	char	**values;
	int		r;
	int		g;
	int		b;
	bool	set;
}	t_color;

#endif
