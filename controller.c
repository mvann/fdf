/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:42:28 by mvann             #+#    #+#             */
/*   Updated: 2017/10/13 13:34:51 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_vects(t_vars *vars)
{
	t_held *keys;

	keys = vars->held;
	// printf("move\n");
	// printf("keys->x:%d\n", keys->x);
	if (keys->q)
		axis_rot(vars, -THETA, 'x');
	if (keys->w)
		axis_rot(vars, THETA, 'x');
	if (keys->a)
		axis_rot(vars, -THETA, 'y');
	if (keys->s)
		axis_rot(vars, THETA, 'y');
	if (keys->z)
		axis_rot(vars, -THETA, 'z');
	if (keys->x)
		axis_rot(vars, THETA, 'z');
	if (keys->up)
		shift(vars, 0, -1);
	if (keys->down)
		shift(vars, 0, 1);
	if (keys->left)
		shift(vars, -1, 0);
	if (keys->right)
		shift(vars, 1, 0);
}
