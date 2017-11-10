/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:55:58 by mvann             #+#    #+#             */
/*   Updated: 2017/11/09 16:38:25 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		print_error(char *s)
{
	ft_putstr("Error");
	if (*s)
	{
		ft_putstr(": ");
		ft_putstr(s);
	}
	ft_putstr("\n");
	exit(EXIT_FAILURE);
	return (0);
}

int		init_vars(t_vars **vars, int fd)
{
	if (!(*vars = (t_vars *)ft_memalloc(sizeof(t_vars)))
	|| !((*vars)->mlx = mlx_init()))
		print_error("malloc");
	(*vars)->win = mlx_new_window((*vars)->mlx, WIN_SIZE_X, WIN_SIZE_Y, "FDF");
	(*vars)->board = (t_vect **)ft_memalloc(sizeof(t_vect *) * 100);
	(*vars)->held = (t_held *)ft_memalloc(sizeof(t_held));
	(*vars)->x_off = X_OFFSET;
	(*vars)->y_off = Y_OFFSET;
	(*vars)->gradient = 1;
	if (!((*vars)->win && (*vars)->board && (*vars)->held))
		print_error("malloc");
	return (init_board((*vars)->board, fd, (*vars)));
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_vars	*vars;

	argc--;
	argv++;
	if (argc != 1)
		return (0);
	if ((fd = open(argv[0], O_RDONLY)) < 0)
		return (print_error("bad file"));
	if (!(ret = init_vars(&vars, fd)))
		return (print_error("bad map"));
	close(fd);
	axis_rot(vars, .5, 'x');
	axis_rot(vars, .5, 'y');
	draw_board(vars->board, vars);
	mlx_hook(vars->win, 2, 0, keydown_event, vars);
	mlx_hook(vars->win, 3, 0, keyup_event, vars);
	mlx_loop_hook(vars->mlx, loop_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
