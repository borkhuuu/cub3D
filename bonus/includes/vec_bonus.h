/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:20:33 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/01 19:57:57 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_BONUS_H
# define VEC_BONUS_H

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_vec_int
{
	int	x;
	int	y;
}	t_vec_int;

typedef struct s_doubles
{
	double	dx;
	double	dy;
	double	step;
	double	dist;
	double	dist_sq;
}	t_doubles;

#endif
