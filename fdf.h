/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:42 by mvann             #+#    #+#             */
/*   Updated: 2017/11/08 20:17:44 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*DELTE ME*/ #include <stdio.h> //DELETE ME

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# ifndef NULL
#  define NULL (void *)0
# endif

# define WIN_SIZE_X 800
# define WIN_SIZE_Y WIN_SIZE_X
# define CELL_SIZE 40
# define X_OFFSET WIN_SIZE_X / 2
# define Y_OFFSET X_OFFSET
# define THETA .05
# define SHIFT_AMOUNT 5
# define Z_SCALAR 3

# define BACKGROUND_COLOR 0x000000
# define WIRE_COLOR 0xFFFFFF

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_Z 6
# define KEY_X 7
# define KEY_T 17

typedef struct	s_heights
{
	int			oldh;
	int			newh;
}				t_heights;

typedef struct	s_color
{
	int			h;
	int			col;
}				t_color;

typedef struct	s_vect
{
	double	x;
	double	y;
	double	z;
	int		h;
}				t_vect;

typedef struct	s_grad
{
	int		start;
	int		finish;
}				t_grad;

typedef struct	s_held
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		q;
	int		w;
	int		a;
	int		s;
	int		z;
	int		x;
	int		t;
}				t_held;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_vect	**board;
	int		x_offset;
	int		y_offset;
	int		len;
	t_held	*held;
}				t_vars;

int		init_board(t_vect **board, int fd, t_vars *vars);
void	draw_board(t_vect **board, t_vars *vars);
void	axis_rot(t_vars *vars, double theta, char c);
void	shift(t_vars *vars, int sx, int sy);
void	move_vects(t_vars *vars);
int		keydown_event(int keycode, t_vars *vars);
int		keyup_event(int keycode, t_vars *vars);
int		expose_event(t_vars *vars);
int		loop_event(t_vars *vars);
int		print_error();
int		get_color(int mid, int start, int fin, t_heights vessel);
int		keydown_event(int keycode, t_vars *vars);
int		keyup_event(int keycode, t_vars *vars);

#endif
