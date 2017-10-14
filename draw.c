/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:39:55 by mvann             #+#    #+#             */
/*   Updated: 2017/10/13 17:40:13 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //DELETE THIS

// int		get_gradient(int n1, int range, t_gradient grad)
// {
//
// };

void	line_to(t_vars *vars, double x0, double y0, double x1, double y1, t_gradient grad)
{
	int dx = (int)x1 - (int)x0;
	int dy = (int)y1 - (int)y0;
	int delta = abs(dx) > abs(dy) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);
	int x;
	int y;
	int diff;
// vars->len+=color;
// vars->len-=color;
	y = (int)y0;
	x = (int)x0;
	// printf("<---:x:%i, x0:%f, x1:%f, y:%i, y0:%f, y1:%f, dx:%i, dy:%i, d:%i\n",
	// x,x0,x1,y,y0,y1,dx,dy,delta);
	if (abs(dx) > abs(dy))
	{
		while (x != (int)x1)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + X_OFFSET, y + Y_OFFSET, get_gradient(x - (int)x0, (int)x1 - (int)x1, grad);
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
		while (y != (int)y1)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + X_OFFSET, y + Y_OFFSET, color);
			if (delta > 0)
			{
				x += dx > 0 ? 1 : -1;
				delta += (-1) * 2 * abs(dy);//(dx > 0 ? dx : -dx);
			}
			delta += 2 * (abs(dx) > abs(dy) ? abs(dy) : abs(dx));
			y += dy > 0 ? 1 : -1;
		}
	}
	// printf("--->:x:%i, x0:%f, x1:%f, y:%i, y0:%f, y1:%f, dx:%i, dy:%i, d:%i\n",
	// x,x0,x1,y,y0,y1,dx,dy,delta);
}

void	draw_board(t_vect **board, t_vars *vars, int color)
{
	int row;
	int col;
	t_grad	grad;

	grad.start = 0xffffff;
	grad.finish = 0xff00ff;

	// color++;

	row = 0;
	while (board[row])
	{
		col = 0;
		while (col + 1 < vars->len)
		{
			line_to(vars, board[row][col].x, board[row][col].y,
				board[row][col + 1].x, board[row][col + 1].y, grad);
			col++;
		}
		row++;
	}
	col = 0;
	while (col < vars->len)
	{
		row = 0;
		while (board[row + 1])
		{
			line_to(vars, board[row][col].x, board[row][col].y,
				board[row + 1][col].x, board[row + 1][col].y, grad);
			row++;
		}
		col++;
	}
}
