/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:35:57 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/30 20:03:19 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

int				check_tetrinumber(char **line)
{
	int			y;
	int			nb;

	nb = 1;
	y = 0;
	while (line[y])
	{
		if (ft_strlen(line[y]) == 1)
			nb++;
		y++;
	}
	return (nb);
}

static char		**fill_board(char **board, char *file, char *line, int *y)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (!(board = ft_memalloc(sizeof(char *) * 130)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if (!line)
			return (NULL);
		board[*y] = ft_strnew(ft_strlen(line) + 1);
		board[*y] = ft_strcpy(board[*y], line);
		board[*y][ft_strlen(line)] = '\n';
		board[*y][ft_strlen(line) + 1] = '\0';
		*y += 1;
		if (*y > 129)
			ft_error();
		free(line);
	}
	if (*y == 0)
		ft_error();
	close(fd);
	return (board);
}

char			**create_tetriminos(char *file, char **board)
{
	char		*line;
	int			y;
	int			nbline;

	y = 0;
	line = NULL;
	board = fill_board(board, file, line, &y);
	nbline = y;
	while (y < 130)
		ft_memdel((void **)board[y++]);
	if (check_board(board) == 0 || check_validtetriminos(board) == 0
			|| check_rows(board, nbline) == 0)
		ft_error();
	return (board);
}
