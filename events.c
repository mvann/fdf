/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:30:30 by mvann             #+#    #+#             */
/*   Updated: 2017/10/16 15:50:58 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //DELETE THIS

int		keydown_event(int keycode, t_vars *vars)
{
	t_held *keys;

	// printf("down:%d\n", keycode);
	keys = vars->held;
	if (keycode == KEY_Q)
		keys->q = 1;
	if (keycode == KEY_W)
		keys->w = 1;
	if (keycode == KEY_A)
		keys->a = 1;
	if (keycode == KEY_S)
		keys->s = 1;
	if (keycode == KEY_Z)
		keys->z = 1;
	if (keycode == KEY_X)
		keys->x = 1;
	if (keycode == KEY_UP)
		keys->up = 1;
	if (keycode == KEY_DOWN)
		keys->down = 1;
	if (keycode == KEY_LEFT)
		keys->left = 1;
	if (keycode == KEY_RIGHT)
		keys->right = 1;
	if (keycode == KEY_T)
		keys->t = 1;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		keyup_event(int keycode, t_vars *vars)
{
	t_held *keys;

	// printf("up:%d\n", keycode);
	keys = vars->held;
	if (keycode == KEY_Q)
		keys->q = 0;
	if (keycode == KEY_W)
		keys->w = 0;
	if (keycode == KEY_A)
		keys->a = 0;
	if (keycode == KEY_S)
		keys->s = 0;
	if (keycode == KEY_Z)
		keys->z = 0;
	if (keycode == KEY_X)
		keys->x = 0;
	if (keycode == KEY_UP)
		keys->up = 0;
	if (keycode == KEY_DOWN)
		keys->down = 0;
	if (keycode == KEY_LEFT)
		keys->left = 0;
	if (keycode == KEY_RIGHT)
		keys->right = 0;
	if (keycode == KEY_T)
		keys->t = 0;
	// if (keycode == KEY_ESC)
	// 	exit(EXIT_SUCCESS);
	return (0);
}

int		expose_event(t_vars *vars)
{
	printf("expose_event_triggered\n");
	vars->len++;
	vars->len--;
	return (0);
}

int		loop_event(t_vars *vars)
{
	// printf("here\n");
	// draw_board(vars->board, vars, BACKGROUND_COLOR);
	mlx_clear_window(vars->mlx, vars->win);
	// printf("here2\n");
	move_vects(vars);
	// printf("here3\n");
	draw_board(vars->board, vars);
	// printf("here4\n");
	return(0);
}
