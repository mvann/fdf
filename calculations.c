/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:56:21 by mvann             #+#    #+#             */
/*   Updated: 2017/10/13 13:35:11 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	matrix_mult(t_vect *vect, double dx, double dy, double dz)
{
	return (vect->x * dx + vect->y * dy + vect->z * dz);
}

t_vect	*single_rot(t_vect *vect, double theta, char c)
{
	double x;
	double y;
	double z;

	if (c == 'x')
	{
		x = matrix_mult(vect, 1, 0, 0);
		y = matrix_mult(vect, 0, cos(theta), -sin(theta));
		z = matrix_mult(vect, 0, sin(theta), cos(theta));
	}
	else if (c == 'y')
	{
		x = matrix_mult(vect, cos(theta), 0, sin(theta));
		y = matrix_mult(vect, 0, 1, 0);
		z = matrix_mult(vect, -sin(theta), 0, cos(theta));
	}
	else if (c == 'z')
	{
		x = matrix_mult(vect, cos(theta), -sin(theta), 0);
		y = matrix_mult(vect, sin(theta), cos(theta), 0);
		z = matrix_mult(vect, 0, 0, 1);
	}
	else
		return (vect);
	vect->x = x;
	vect->y = y;
	vect->z = z;
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
	// printf("%f, %f, %f\n", vars->board[3][3].x, vars->board[3][3].y, vars->board[3][3].z);
}

void	shift(t_vars *vars, int sx, int sy)
{
	int x;
	int y;
	t_vect **vs;

	vs = vars->board;
	y = 0;
	while (vs[y])
	{
		x = 0;
		while (x < vars->len)
		{
			vs[y][x].x += SHIFT_AMOUNT * sx;
			vs[y][x].y += SHIFT_AMOUNT * sy;
			x++;
		}
		y++;
	}
}
