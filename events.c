/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:25:09 by mvann             #+#    #+#             */
/*   Updated: 2017/11/09 17:43:49 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop_event(t_vars *vars)
{
	move_vects(vars);
	mlx_clear_window(vars->mlx, vars->win);
	draw_board(vars->board, vars);
	return (0);
}
