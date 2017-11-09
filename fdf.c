/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:55:58 by mvann             #+#    #+#             */
/*   Updated: 2017/11/08 20:22:43 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		print_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
	return (0);
}

int		init_vars(t_vars **vars, int fd)
{
	*vars = (t_vars *)ft_memalloc(sizeof(t_vars));
	(*vars)->mlx = mlx_init();
	(*vars)->win = mlx_new_window((*vars)->mlx, WIN_SIZE_X, WIN_SIZE_Y, "FDF");
	(*vars)->board = (t_vect **)ft_memalloc(sizeof(t_vect *) * 100);
	(*vars)->held = (t_held *)ft_memalloc(sizeof(t_held));
	(*vars)->x_offset = X_OFFSET;
	(*vars)->y_offset = Y_OFFSET;
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
		return (print_error());
	if ((ret = init_vars(&vars, fd)) == 0)
		return (print_error());
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
