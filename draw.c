/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:39:55 by mvann             #+#    #+#             */
/*   Updated: 2017/11/08 20:01:21 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_octant(int dx, int dy)
{
	if (dx >= dy && dx >= 0 && dy >= 0)
		return (0);
	else if (dy >= dx && dx >= 0 && dy >= 0)
		return (1);
	else if (dy >= dx && dx <= 0 && dy >= 0)
		return (2);
	else if (dx >= dy && dx <= 0 && dy >= 0)
		return (3);
	else if (dx >= dy && dx <= 0 && dy <= 0)
		return (4);
	else if (dy >= dx && dx <= 0 && dy <= 0)
		return (5);
	else if (dy >= dx && dx >= 0 && dy <= 0)
		return (6);
	else
		return (7);
}

void	line_to1(t_vars *vars, t_vect old, t_vect new, t_heights vessel)
{
	int dx;
	int dy;
	int delta;
	int x;
	int y;

	dx = (int)new.x - (int)old.x;
	dy = (int)new.y - (int)old.y;
	delta = abs(dx) > abs(dy) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);
	y = (int)old.y;
	x = (int)old.x;
	vessel.oldh = old.h;
	vessel.newh = new.h;
	while (x != (int)new.x)
	{
		mlx_pixel_put(vars->mlx, vars->win, x + vars->x_offset,
			y + vars->y_offset, get_color(x, old.x, new.x, vessel));
		if (delta > 0)
		{
			y += dy > 0 ? 1 : -1;
			delta += (-1) * 2 * (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
		}
		delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
		x += dx > 0 ? 1 : -1;
	}
}

void	line_to2(t_vars *vars, t_vect old, t_vect new, t_heights vessel)
{
	int dx;
	int dy;
	int delta;
	int x;
	int y;

	dx = (int)new.x - (int)old.x;
	dy = (int)new.y - (int)old.y;
	delta = abs(dx) > abs(dy) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);
	y = (int)old.y;
	x = (int)old.x;
	vessel.oldh = old.h;
	vessel.newh = new.h;
	while (y != (int)new.y)
	{
		mlx_pixel_put(vars->mlx, vars->win, x + vars->x_offset,
			y + vars->y_offset, get_color(y, old.y, new.y, vessel));
		if (delta > 0)
		{
			x += dx > 0 ? 1 : -1;
			delta += (-1) * 2 * abs(dy);
		}
		delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
		y += dy > 0 ? 1 : -1;
	}
}

void	line_to(t_vars *vars, t_vect old, t_vect new, t_heights vessel)
{
	int dx;
	int dy;

	dx = (int)new.x - (int)old.x;
	dy = (int)new.y - (int)old.y;
	if (abs(dx) > abs(dy))
		line_to1(vars, old, new, vessel);
	else
		line_to2(vars, old, new, vessel);
}

void	draw_board(t_vect **board, t_vars *vars)
{
	int			row;
	int			col;
	int			next_col;
	int			next_row;
	t_heights	vessel;

	vessel.oldh = 0;
	vessel.newh = 0;
	row = 0;
	while (board[row])
	{
		col = 0;
		while (col < vars->len)
		{
			if ((next_col = col + 1 < vars->len))
				line_to(vars, board[row][col], board[row][col + 1], vessel);
			if ((next_row = board[row + 1] != 0))
				line_to(vars, board[row][col], board[row + 1][col], vessel);
			if (next_col && next_row && vars->held->t)
				line_to(vars, board[row][col], board[row + 1][col + 1], vessel);
			col++;
		}
		row++;
	}
}
