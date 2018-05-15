/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:51:32 by mvann             #+#    #+#             */
/*   Updated: 2017/11/09 17:42:32 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_split_len(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	check_valid_char(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
		|| (i > 0 && s[i] == '-') || (i > 0 && s[i] == '+'))
			print_error("unexpected character in map");
		i++;
	}
}

static void	handle_split(char **split, t_vect **board, int len, int i)
{
	int	j;
	int cell_size;
	int lesser;

	lesser = WIN_SIZE_X > WIN_SIZE_Y ? WIN_SIZE_Y : WIN_SIZE_X;
	cell_size = len ? (lesser - 50) / len : CELL_SIZE;
	j = 0;
	while (split[j])
	{
		check_valid_char(split[j]);
		board[i][j].x = j * cell_size - len / 2 * cell_size;
		board[i][j].y = i * cell_size - len / 4 * cell_size;
		board[i][j].z = ft_atoi(split[j]) * Z_SCALAR;
		board[i][j].h = ft_atoi(split[j]);
		free(split[j]);
		j++;
	}
}

int			init_board(t_vect **board, int fd, t_vars *vars)
{
	char	*str;
	char	**split;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (get_next_line(fd, &str))
	{
		split = ft_strsplit(str, ' ');
		if (!len)
			len = get_split_len(split);
		if (len && len != get_split_len(split))
			return (0);
		board[i] = (t_vect *)malloc(sizeof(t_vect) * len);
		handle_split(split, board, len, i);
		free(split);
		i++;
	}
	board[i] = NULL;
	vars->len = len;
	return (1);
}
