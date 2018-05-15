/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:56:21 by mvann             #+#    #+#             */
/*   Updated: 2017/11/09 13:56:47 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	matrix_mult(t_vect *vect, double dx, double dy, double dz)
{
	return (vect->x * dx + vect->y * dy + vect->z * dz);
}

void	update_vect(t_vect *vect, t_vect v)
{
	vect->x = v.x;
	vect->y = v.y;
	vect->z = v.z;
}

t_vect	*single_rot(t_vect *vect, double theta, char c)
{
	t_vect v;

	if (c == 'x')
	{
		v.x = vect->x;
		v.y = matrix_mult(vect, 0, cos(theta), -sin(theta));
		v.z = matrix_mult(vect, 0, sin(theta), cos(theta));
	}
	else if (c == 'y')
	{
		v.x = matrix_mult(vect, cos(theta), 0, sin(theta));
		v.y = vect->y;
		v.z = matrix_mult(vect, -sin(theta), 0, cos(theta));
	}
	else if (c == 'z')
	{
		v.x = matrix_mult(vect, cos(theta), -sin(theta), 0);
		v.y = matrix_mult(vect, sin(theta), cos(theta), 0);
		v.z = vect->z;
	}
	else
		return (vect);
	update_vect(vect, v);
	return (vect);
}

void	axis_rot(t_vars *vars, double theta, char c)
{
	int i;
	int j;

	i = 0;
	while (vars->board[i])
	{
		j = 0;
		while (j < vars->len)
		{
			single_rot(&(vars->board[i][j]), theta, c);
			j++;
		}
		i++;
	}
}

void	shift(t_vars *vars, int sx, int sy)
{
	vars->x_off += SHIFT_AMOUNT * sx;
	vars->y_off += SHIFT_AMOUNT * sy;
}
