/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:55:28 by mvann             #+#    #+#             */
/*   Updated: 2017/11/08 19:53:10 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_mid(int mid, int start, int fin, t_heights h)
{
	if (fin == start)
		return (h.newh);
	return (((h.newh - h.oldh) * (mid - start)) / (fin - start) + h.oldh);
}

static void	init_colors(t_color colors[3])
{
	colors[0].h = 0;
	colors[0].col = 0x7EFF77;
	colors[1].h = 7;
	colors[1].col = 0x7F560F;
	colors[2].h = 10;
	colors[2].col = 0xFFFFFF;
}

int			get_color(int mid, int start, int fin, t_heights vessel)
{
	int		h;
	t_color	colors[3];
	int		num_colors;
	int		rgb;
	int		i;

	num_colors = 3;
	if ((h = get_mid(mid, start, fin, vessel)) < 0)
		return (0x4983FF);
	init_colors(colors);
	i = 0;
	while (i + 1 < num_colors && colors[i + 1].h <= h)
		i++;
	if (i == num_colors - 1)
		return (colors[num_colors - 1].col);
	rgb = 0;
	vessel.oldh = colors[i].col & 0xFF0000;
	vessel.newh = colors[i + 1].col & 0xFF0000;
	rgb |= get_mid(h, colors[i].h, colors[i + 1].h, vessel) & 0xFF0000;
	vessel.oldh = colors[i].col & 0x00FF00;
	vessel.newh = colors[i + 1].col & 0x00FF00;
	rgb |= get_mid(h, colors[i].h, colors[i + 1].h, vessel) & 0x00FF00;
	vessel.oldh = colors[i].col & 0x0000FF;
	vessel.newh = colors[i + 1].col & 0x0000FF;
	return (rgb |= get_mid(h, colors[i].h, colors[i + 1].h, vessel) & 0x0000FF);
}
