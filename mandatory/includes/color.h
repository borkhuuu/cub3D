/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:51:55 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/05 19:52:20 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

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
