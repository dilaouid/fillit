/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:35:57 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/28 20:52:22 by dilaouid         ###   ########.fr       */
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
	int			nb;

	nb = 0;
	fd = open(file, O_RDONLY);
	board = (char **)malloc(sizeof(char *) * 129);
	if (board == NULL)
		return (NULL);
	while (get_next_line(fd, &line) > 0 && *y < 129)
	{
		board[*y] = ft_strdup(line);
		board[*y][ft_strlen(line)] = '\n';
		*y += 1;
		nb++;
		printf("%d\n", *y);
		free(line);
		if (*y == 129)
			break;
	}
	close(fd);
	*y = 0;
	while (*y < nb)
	{
		printf("Y = %d\n", *y);
		ft_putstr(board[*y]);
		*y += 1;
	}
	free(board[*y]);
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
	while (y <= 129)
	{
		printf("qqqqqqq\n");
		free(board[y]);
		y++;
	}
	if (check_board(board) == 0 || check_validtetriminos(board) == 0
			|| check_rows(board, nbline) == 0)
		ft_error();
	return (board);
}
