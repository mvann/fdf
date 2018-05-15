/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:17:18 by mvann             #+#    #+#             */
/*   Updated: 2017/11/09 15:31:51 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keydown_event2(int keycode, t_vars *vars)
{
	t_held *keys;

	keys = vars->held;
	if (keycode == KEY_T)
		keys->t = 1;
	else if (keycode == KEY_Y)
		vars->gradient = vars->gradient ? 0 : 1;
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
}

int		keydown_event(int keycode, t_vars *vars)
{
	t_held *keys;

	keys = vars->held;
	if (keycode == KEY_Q)
		keys->q = 1;
	else if (keycode == KEY_W)
		keys->w = 1;
	else if (keycode == KEY_A)
		keys->a = 1;
	else if (keycode == KEY_S)
		keys->s = 1;
	else if (keycode == KEY_Z)
		keys->z = 1;
	else if (keycode == KEY_X)
		keys->x = 1;
	else if (keycode == KEY_UP)
		keys->up = 1;
	else if (keycode == KEY_DOWN)
		keys->down = 1;
	else if (keycode == KEY_LEFT)
		keys->left = 1;
	else if (keycode == KEY_RIGHT)
		keys->right = 1;
	keydown_event2(keycode, vars);
	return (0);
}

void	keyup_event2(int keycode, t_vars *vars)
{
	t_held *keys;

	keys = vars->held;
	if (keycode == KEY_T)
		keys->t = 0;
}

int		keyup_event(int keycode, t_vars *vars)
{
	t_held *keys;

	keys = vars->held;
	if (keycode == KEY_Q)
		keys->q = 0;
	else if (keycode == KEY_W)
		keys->w = 0;
	else if (keycode == KEY_A)
		keys->a = 0;
	else if (keycode == KEY_S)
		keys->s = 0;
	else if (keycode == KEY_Z)
		keys->z = 0;
	else if (keycode == KEY_X)
		keys->x = 0;
	else if (keycode == KEY_UP)
		keys->up = 0;
	else if (keycode == KEY_DOWN)
		keys->down = 0;
	else if (keycode == KEY_LEFT)
		keys->left = 0;
	else if (keycode == KEY_RIGHT)
		keys->right = 0;
	keyup_event2(keycode, vars);
	return (0);
}
