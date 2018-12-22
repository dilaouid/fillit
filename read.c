/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:35:57 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/22 17:48:24 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tetriminos(char *file, char **board)
{
	char	*line;
	int		y;
	int		nbtetriminos;
	int		fd;

	y = 0;
	fd = open(file, O_RDONLY);
	board = (char **)malloc(sizeof(char *) * 26);
	while (get_next_line(fd, &line) > 0)
	{
		board[y] = ft_strdup(line);
		board[y][ft_strlen(line)] = '\n';
		y++;
		free(line);
	}
	close(fd);
	y = 0;
	while (board[y] != NULL)
		y++;
	printf("Number of lines: %d\n", y);
	while (y < 26)
	{
		ft_memdel((void **)board[y]);
		y++;
	}
	nbtetriminos = check_tetrinumber(board);
	printf("Nb of tetriminos: %d\n", nbtetriminos);
	if (check_board(board) == 0 || check_validtetriminos(board) == 0)
	{
		ft_putendl("error");
		return (NULL);
	}
	else
		ft_putendl("OK!");
	return (board);
}
