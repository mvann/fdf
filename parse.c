/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:51:32 by mvann             #+#    #+#             */
/*   Updated: 2017/10/15 14:49:01 by mvann            ###   ########.fr       */
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

int		init_board(t_vect **board, int fd, t_vars *vars)
{
	char	*str;
	char	**split;
	int		i;
	int		j;
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
		j = 0;
		while (split[j])
		{
			board[i][j].x = j * CELL_SIZE - len / 2 * CELL_SIZE;
			board[i][j].y = i * CELL_SIZE - len / 4 * CELL_SIZE;
			board[i][j].z = ft_atoi(split[j]) * Z_SCALAR;
			board[i][j].h = ft_atoi(split[j]);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	board[i] = NULL;
	vars->len = len;
	return (1);
}
