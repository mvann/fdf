/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:39:55 by mvann             #+#    #+#             */
/*   Updated: 2017/10/16 15:51:22 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //DELETE THIS

int		get_mid(int mid, int start, int fin, int sh, int fh)
{
	if (fin == start)
		return (fh);
	return (((fh - sh) * (mid - start)) / (fin - start) + sh);
}

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

int		get_color(int mid, int start, int fin, int sh, int fh)
{
	int		h;
	t_color	colors[3];
	int		num_colors;
	int		rgb;
	int		i;

	num_colors = 3;
	if ((h = get_mid(mid, start, fin, sh, fh)) < 0)
		return (0x4983FF);
	colors[0].h = 0;
	colors[0].col = 0x7EFF77;
	colors[1].h = 7;
	colors[1].col = 0x7F560F;
	colors[2].h = 10;
	colors[2].col = 0xFFFFFF;
	i = 0;
	while (i + 1 < num_colors && colors[i + 1].h <= h)
		i++;
	if (i == num_colors - 1)
		return (colors[num_colors - 1].col);
	rgb = 0;
	rgb |= get_mid(h, colors[i].h, colors[i + 1].h,
		colors[i].col & 0xFF0000, colors[i + 1].col & 0xFF0000) & 0xFF0000;
	rgb |= get_mid(h, colors[i].h, colors[i + 1].h,
		colors[i].col & 0x00FF00, colors[i + 1].col & 0x00FF00) & 0x00FF00;
	return (rgb |= get_mid(h, colors[i].h, colors[i + 1].h,
		colors[i].col & 0x0000FF, colors[i + 1].col & 0x0000FF) & 0x0000FF);
}

void	line_to(t_vars *vars, t_vect old, t_vect new)
{
	int dx = (int)new.x - (int)old.x;
	int dy = (int)new.y - (int)old.y;
	int delta = abs(dx) > abs(dy) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);
	int x;
	int y;
// vars->len+=color;
// vars->len-=color;
	y = (int)old.y;
	x = (int)old.x;
	// printf("<---:x:%i, old.x:%f, new.x:%f, y:%i, old.y:%f, new.y:%f, dx:%i, dy:%i, d:%i\n",
	// x,old.x,new.x,y,old.y,new.y,dx,dy,delta);
	if (abs(dx) > abs(dy))
	{
		while (x != (int)new.x)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + vars->x_offset, y + vars->y_offset,
				get_color(x, old.x, new.x, old.h, new.h));
			if (delta > 0)
			{
				y += dy > 0 ? 1 : -1;
				delta += (-1) * 2 * (abs(dx) > abs(dy) ? abs(dx) : abs(dy));//(dx > 0 ? dx : -dx);
			}
			delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
			x += dx > 0 ? 1 : -1;
		}
	}
	else
	{
		while (y != (int)new.y)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + vars->x_offset, y + vars->y_offset,
				get_color(y, old.y, new.y, old.h, new.h));
			if (delta > 0)
			{
				x += dx > 0 ? 1 : -1;
				delta += (-1) * 2 * abs(dy);//(dx > 0 ? dx : -dx);
			}
			delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
			y += dy > 0 ? 1 : -1;
		}
	}
	// printf("--->:x:%i, old.x:%f, new.x:%f, y:%i, old.y:%f, new.y:%f, dx:%i, dy:%i, d:%i\n",
	// x,old.x,new.x,y,old.y,new.y,dx,dy,delta);
}

void	draw_board(t_vect **board, t_vars *vars)
{
	int row;
	int col;
	int next_col;
	int next_row;

	row = 0;
	while (board[row])
	{
		col = 0;
		while (col < vars->len)
		{
			if ((next_col = col + 1 < vars->len))
				line_to(vars, board[row][col], board[row][col + 1]);
			if ((next_row = board[row + 1] != 0))
				line_to(vars, board[row][col], board[row + 1][col]);
			if (next_col && next_row && vars->held->t)
				line_to(vars, board[row][col], board[row + 1][col + 1]);
			col++;
		}
		row++;
	}
	// col = 0;
	// while (col < vars->len)
	// {
	// 	row = 0;
	// 	while (board[row + 1])
	// 	{
	// 		line_to(vars, board[row][col], board[row + 1][col]);
	// 		row++;
	// 	}
	// 	col++;
	// }
}
